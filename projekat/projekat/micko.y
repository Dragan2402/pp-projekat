%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "defs.h"
  #include "symtab.h"
  #include "codegen.h"

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  int out_lin = 0;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;
  int fun_idx = -1;
  int class_idx = -1;
  int fcall_idx = -1;
  int lab_num = -1;
  int* parameter_map[128];
  int arg_counter = 0;
  int isClass = 0;
  int attributes_counter=0;
  FILE *output;
%}

%union {
  int i;
  char *s;
}

%token <i> _TYPE
%token _IF
%token _ELSE
%token _RETURN
%token _CLASS
%token _NEW
%token <s> _ID
%token <s> _INT_NUMBER
%token <s> _UINT_NUMBER
%token _LPAREN
%token _RPAREN
%token _LBRACKET
%token _RBRACKET
%token _ASSIGN
%token _SEMICOLON
%token _DOT
%token _COMMA
%token <i> _AROP
%token <i> _RELOP

%type <i> num_exp exp literal
%type <i> function_call argument rel_exp if_part

%nonassoc ONLY_IF
%nonassoc _ELSE



%%

program
  : { isClass=1; } classes_list { isClass=0; } function_list
      {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
      }
  ;

classes_list
  : 
  | classes_existing_list
  ;

classes_existing_list
  : class 
  | classes_existing_list class
  ;

class
  : _CLASS _ID {
        class_idx = lookup_symbol($2, CLASS);
        if(class_idx == NO_INDEX){
          class_idx = insert_symbol($2, CLASS, NO_TYPE, NO_ATR, NO_ATR);
          int* param_types = (int*) malloc(sizeof(int)*128);
          parameter_map[class_idx] = param_types;
          }
        else 
          err("redefinition of class '%s'", $2);
        attributes_counter=0;
  }
    _LBRACKET attributes_list constructor { 
       if( arg_counter != get_atr1(class_idx)){
        err("Invalid number of arguments in constructor, arguments '%d', attributes '%d'",arg_counter,attributes_counter);
       }
     } functions_list _RBRACKET {
      clear_symbols(class_idx+1);
      attributes_counter=0;
    } ;

attributes_list
  :
  | attributes_list attribute
  ;

attribute
  : _TYPE _ID {
      {
        if(lookup_symbol($2, ATR) == NO_INDEX){
          insert_symbol($2, ATR, $1, attributes_counter, NO_ATR);
          attributes_counter = get_atr1(class_idx);
          int* param_types = parameter_map[class_idx];
          param_types[attributes_counter] = $1;
          attributes_counter += 1;
          set_atr1(class_idx, attributes_counter); OVDE SI STAO NASTAVI DALJE POTREBNO JE UBACITI VALIDACIJU ARGUEMANATA I DODJELU PA ONDA FUNKCIJE
           }
        else 
           err("redefinition of '%s'", $2);
      }

  } _SEMICOLON;

functions_list
  : 
  | function_list;

function_list
  : function
  | function_list function
  ;

constructor
  : _ID {
    char* class_name = get_name(class_idx);
    char* id = $1;
    int ret = strcmp(class_name,id);
    if (ret < 0 ){
      err("Inavlid constructor name '%s', class name '%s'",$1,get_name(class_idx));
    }
  } _LPAREN constructor_parameters _RPAREN _LBRACKET attribute_assign_list _RBRACKET;

constructor_parameters
  :
  | constructor_existing_parameters
  ;

constructor_existing_parameters
  : constructor_parameter 
  | constructor_existing_parameters _COMMA constructor_parameter
  ;

constructor_parameter
  : _TYPE _ID
    {
      if(lookup_symbol($2, PAR) != -1){
        err("Redefinition of parameter %s ", $2);
      }
      insert_symbol($2, PAR, $1, 1, NO_ATR);
      ++arg_counter;
    }
  ;


attribute_assign_list
  : 
  | attribute_assign_list attribute_assign ;

attribute_assign
  : _ID _ASSIGN _ID _SEMICOLON
  | _ID _ASSIGN literal _SEMICOLON
  ;


function
  : _TYPE _ID
      {
        fun_idx = lookup_symbol($2, FUN);
        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol($2, FUN, $1, NO_ATR, NO_ATR);
        else 
          err("redefinition of function '%s'", $2);

        code("\n%s:", $2);
        code("\n\t\tPUSH\t%%14");
        code("\n\t\tMOV \t%%15,%%14");
      }
    _LPAREN parameter _RPAREN body
      {
        clear_symbols(fun_idx + 1);
        var_num = 0;
        
        code("\n@%s_exit:", $2);
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
      }
  ;

parameter
  : /* empty */
      { set_atr1(fun_idx, 0); }

  | _TYPE _ID
      {
        insert_symbol($2, PAR, $1, 1, NO_ATR);
        set_atr1(fun_idx, 1);
        set_atr2(fun_idx, $1);
      }
  ;

body
  : _LBRACKET variable_list
      {
        if(var_num)
          code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
        code("\n@%s_body:", get_name(fun_idx));
      }
    statement_list _RBRACKET
  ;



variable_list
  : /* empty */
  | variable_list variable
  ;

variable
  : _TYPE _ID _SEMICOLON
      {
        if(lookup_symbol($2, VAR|PAR) == NO_INDEX)
           insert_symbol($2, VAR, $1, ++var_num, NO_ATR);
        else 
           err("redefinition of '%s'", $2);
      }
  ;

statement_list
  : /* empty */
  | statement_list statement
  ;

statement
  : compound_statement
  | assignment_statement
  | if_statement
  | class_declaration
  | return_statement
  ;

class_declaration
  : _CLASS _ID _ID _ASSIGN _NEW _ID _LPAREN class_argument_list _RPAREN _SEMICOLON
  ;


class_argument_list
  : /* empty */
  | class_arguments
  ;

class_arguments
  : class_argument
  | class_arguments _COMMA class_argument
  ;

class_argument
  : num_exp
  ;

compound_statement
  : _LBRACKET statement_list _RBRACKET
  ;

assignment_statement
  : _ID _ASSIGN num_exp _SEMICOLON
      {
        if(isClass==0){
          int idx = lookup_symbol($1, VAR|PAR);
          if(idx == NO_INDEX)
            err("invalid lvalue '%s' in assignment", $1);
          else
            if(get_type(idx) != get_type($3))
              err("incompatible types in assignment");
          gen_mov($3, idx);
        }
      }
  ;

num_exp
  : exp

  | num_exp _AROP exp
      {
        if(get_type($1) != get_type($3))
          err("invalid operands: arithmetic operation");
        int t1 = get_type($1);    
        code("\n\t\t%s\t", ar_instructions[$2 + (t1 - 1) * AROP_NUMBER]);
        gen_sym_name($1);
        code(",");
        gen_sym_name($3);
        code(",");
        free_if_reg($3);
        free_if_reg($1);
        $$ = take_reg();
        gen_sym_name($$);
        set_type($$, t1);
      }
  ;

exp
  : literal
  | _ID _DOT function_call
    {
      $$ = take_reg();
      gen_mov(FUN_REG, $$);
    }
  | _ID
      {
        if( isClass==0){
          $$ = lookup_symbol($1, VAR|PAR);
          if($$ == NO_INDEX)
            err("'%s' undeclared", $1);
        }
      }
  | function_call
      {
        $$ = take_reg();
        gen_mov(FUN_REG, $$);
      }  
  
  | _LPAREN num_exp _RPAREN
      { $$ = $2; }
  ;

literal
  : _INT_NUMBER
      { $$ = insert_literal($1, INT); }

  | _UINT_NUMBER
      { $$ = insert_literal($1, UINT); }
  ;

function_call
  : _ID 
      {
        fcall_idx = lookup_symbol($1, FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", $1);
      }
    _LPAREN argument _RPAREN
      {
        if(isClass==0){
          if(get_atr1(fcall_idx) != $4)
            err("wrong number of arguments");
          code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
          if($4 > 0)
            code("\n\t\t\tADDS\t%%15,$%d,%%15", $4 * 4);
          set_type(FUN_REG, get_type(fcall_idx));
          $$ = FUN_REG;
        }
      }
  ;

argument
  : /* empty */
    { $$ = 0; }

  | num_exp
    { 
      if(isClass==0){
        if(get_atr2(fcall_idx) != get_type($1))
          err("incompatible type for argument");
        free_if_reg($1);
        code("\n\t\t\tPUSH\t");
        gen_sym_name($1);
        $$ = 1;
      }
    }
;

if_statement
  : if_part %prec ONLY_IF
      { code("\n@exit%d:", $1); }

  | if_part _ELSE statement
      { code("\n@exit%d:", $1); }
  ;

if_part
  : _IF _LPAREN
      {
        $<i>$ = ++lab_num;
        code("\n@if%d:", lab_num);
      }
    rel_exp
      {
        code("\n\t\t%s\t@false%d", opp_jumps[$4], $<i>3);
        code("\n@true%d:", $<i>3);
      }
    _RPAREN statement
      {
        code("\n\t\tJMP \t@exit%d", $<i>3);
        code("\n@false%d:", $<i>3);
        $$ = $<i>3;
      }
  ;

rel_exp
  : num_exp _RELOP num_exp
      {
        if(get_type($1) != get_type($3))
          err("invalid operands: relational operator");
        $$ = $2 + ((get_type($1) - 1) * RELOP_NUMBER);
        gen_cmp($1, $3);
      }
  ;

return_statement
  : _RETURN num_exp _SEMICOLON
      {
        if(isClass==0){
        if(get_type(fun_idx) != get_type($2))
          err("incompatible types in return");
        gen_mov($2, FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));   
        }     
      }
  ;

%%

int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  error_count++;
  return 0;
}

void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  warning_count++;
}

int main() {
  int synerr;
  init_symtab();
  output = fopen("output.asm", "w+");

  synerr = yyparse();

  clear_symtab();
  fclose(output);
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count) {
    remove("output.asm");
    printf("\n%d error(s).\n", error_count);
  }

  if(synerr)
    return -1;  //syntax error
  else if(error_count)
    return error_count & 127; //semantic errors
  else if(warning_count)
    return (warning_count & 127) + 127; //warnings
  else
    return 0; //OK
}

