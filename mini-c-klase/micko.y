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
  int current_class_idx = -1;
  int current_instance_idx= -1;
  int instance_declaration_arg_counter = 0;

  int fcall_idx = -1;
  int instance_index=-1;
  int lab_num = -1;
  int return_count=0;
  int* parameter_map_function[128];


  int arguments_array[128];
  int* parameter_map[128];
  int arg_counter = 0;
  int arg_position = 1;
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
        
        current_class_idx = lookup_symbol($2, CLAS);
        if(current_class_idx == NO_INDEX){
          current_class_idx = insert_symbol($2, CLAS, NO_TYPE, 0, NO_ATR,NO_ATR);
          int* param_types = (int*) malloc(sizeof(int)*128);
          parameter_map[current_class_idx] = param_types;
          }
        else 
          err("redefinition of class '%s'", $2);
        attributes_counter=0;
  }
    _LBRACKET attributes_list constructor { 
       if( arg_counter != get_atr1(current_class_idx)){
        err("Invalid number of arguments in constructor, arguments '%d', attributes '%d'",arg_counter,attributes_counter);
       }
       
     } functions_list _RBRACKET {
      arg_counter=0;
      attributes_counter=0;
    } ;

attributes_list
  :
  | attributes_list attribute
  ;

attribute
  : _TYPE _ID {
      {
        if($1 == VOID)
          err("attribute '%s' cannot be void",$2);
        int atr_idx = lookup_symbol($2, ATR);
        if(atr_idx == NO_INDEX){
          int idx=insert_symbol($2, ATR, $1, attributes_counter, NO_ATR,current_class_idx);
          code("\n%s:\n\t\tWORD\t1",$2);
          attributes_counter = get_atr1(current_class_idx);
          int* param_types = parameter_map[current_class_idx];
          param_types[attributes_counter] = $1;
          attributes_counter += 1;
          set_atr1(current_class_idx, attributes_counter); 
           }
        else 
         if(get_atr3(atr_idx)==current_class_idx){
           err("redefinition of '%s'", $2);
          }else{
            int idx=insert_symbol($2, ATR, $1, attributes_counter, NO_ATR,current_class_idx);
            code("\n%s:\n\t\tWORD\t1", $2);
            attributes_counter = get_atr1(current_class_idx);
            int* param_types = parameter_map[current_class_idx];
            param_types[attributes_counter] = $1;
            attributes_counter += 1;
            set_atr1(current_class_idx, attributes_counter); 
          }
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
    char* class_name = get_name(current_class_idx);
    char* id = $1;
    int ret = strcmp(class_name,id);
    if (ret < 0 ){
      err("Inavlid constructor name '%s', class name '%s'",$1,get_name(current_class_idx));
    }
    arg_counter = 0 ;
    arg_position=1;
    code("\n%s:", $1);
    code("\n\t\tPUSH\t%%14");
    code("\n\t\tMOV \t%%15,%%14");
    
  } _LPAREN  constructor_parameters _RPAREN _LBRACKET attribute_assign_list {  
    code("\n\t\tJMP \t@%s_exit", $1);  
    code("\n@%s_exit:", $1);
    code("\n\t\tMOV \t%%14,%%15");
    code("\n\t\tPOP \t%%14");
    code("\n\t\tRET");
    clear_symbols(get_last_element() - arg_counter +1);
  } _RBRACKET;

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
      if($1 == VOID)
          err("attribute '%s' cannot be void",$2);
      if(lookup_symbol($2, PAR) != -1){
        err("Redefinition of parameter %s ", $2);
      }else{
        int indx_atr=lookup_symbol($2,ATR);
        if(indx_atr != NO_INDEX){
          if(get_atr3(indx_atr) == current_class_idx){
            err("Redefinition of attribute %s ", $2);
          }else{
            int* param_types = parameter_map[current_class_idx];
            if(param_types[arg_counter] != $1){
              err("inavlid constructor parameter, paramtere type '%d', attribute type '%d'", $1, param_types[arg_counter]);
            }
            insert_symbol($2, PAR, $1, arg_position , NO_ATR,current_class_idx);
            ++arg_position;
            ++arg_counter;

          }
        }else{
          int* param_types = parameter_map[current_class_idx];
          if(param_types[arg_counter] != $1){
            err("inavlid constructor parameter, paramtere type '%d', attribute type '%d'",$1,param_types[arg_counter]);
          }
          insert_symbol($2, PAR, $1, arg_position, NO_ATR,current_class_idx);
          ++arg_position;
          ++arg_counter;

        }
      }
    }
  ;


attribute_assign_list
  : 
  | attribute_assign_list attribute_assign ;

attribute_assign
  : _ID _ASSIGN _ID _SEMICOLON
  {
      int idx = lookup_symbol($1, ATR);
      if(idx == NO_INDEX)
        err("unknown attribute '%s' in class", $1);
      else{
        if(get_atr3(idx) == current_class_idx){
          int idx_par = lookup_symbol($3,PAR);
          if(get_type(idx) != get_type(idx_par))
            err("incompatible types in assignment of attribute");
          if(get_atr3(idx_par)!=current_class_idx)
            err("parametar '%s' not from this class",$3);
          gen_mov(idx_par, idx);
        }else{
          err("unknown attribute '%s' in class", $1);
        }
      }
    }
  ;


function
  : _TYPE _ID
      {
        if (isClass==0){
            fun_idx = lookup_symbol($2, FUN);
            if(fun_idx == NO_INDEX){
              int* param_types = (int*) malloc(sizeof(int)*128);
              fun_idx = insert_symbol($2, FUN, $1, NO_ATR, NO_ATR,NO_ATR);
              parameter_map_function[fun_idx] = param_types;
            }
            else
              if(get_atr3(fun_idx) == NO_ATR){
                int* param_types = (int*) malloc(sizeof(int)*128);
                fun_idx = insert_symbol($2, FUN, $1, NO_ATR, NO_ATR,NO_ATR);
                parameter_map_function[fun_idx] = param_types;

              }else{
                err("redefinition of function '%s'", $2);
                }

            code("\n%s:", $2);
            code("\n\t\tPUSH\t%%14");
            code("\n\t\tMOV \t%%15,%%14");
        }
        else{
            fun_idx = lookup_symbol($2, FUN);
            if(fun_idx == NO_INDEX){
              int* param_types = (int*) malloc(sizeof(int)*128);
              fun_idx = insert_symbol($2, FUN, $1, NO_ATR, NO_ATR,current_class_idx);   
              parameter_map_function[fun_idx] = param_types;
            }
            else {
              if(get_atr3(fun_idx) == current_class_idx){
                err("redefinition of function '%s' in class '%s", $2, get_name(current_class_idx));
              }else{
                  int* param_types = (int*) malloc(sizeof(int)*128);
                  fun_idx = insert_symbol($2, FUN, $1, NO_ATR, NO_ATR,current_class_idx);
                  parameter_map_function[fun_idx] = param_types;
              }
            }
            code("\n%s:", $2);
            code("\n\t\tPUSH\t%%14");
            code("\n\t\tMOV \t%%15,%%14");
            arg_position=1;
        }
      }
    _LPAREN parameter_list _RPAREN body
      {
        if( (return_count == 0) && (get_type(fun_idx) != VOID) )
          warn("Function should return a value");
        return_count = 0;
        clear_symbols(fun_idx + 1);
        var_num = 0;
        
        code("\n@%s_exit:", $2);
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
      }
  ;
parameter_list
  : 
  { set_atr1(fun_idx, 0); }
  | parameters
;

parameters
  : parameter
  | parameters _COMMA parameter
  ;

parameter
  : _TYPE _ID
      {
        if(isClass==0){
          if(lookup_symbol($2, PAR) != -1){
            err("Redefinition of parameter %s ", $2);
          }
          insert_symbol($2, PAR, $1, arg_position, NO_ATR,NO_ATR);
          int num_params = get_atr1(fun_idx);
    
          int* param_types = parameter_map_function[fun_idx];
          param_types[num_params] = $1;
          num_params += 1;
          arg_position +=1;
          set_atr1(fun_idx, num_params);
        }else{
        if(lookup_symbol($2, PAR) != -1){
          err("Redefinition of parameter %s ", $2);
          }
        insert_symbol($2, PAR, $1, arg_position, NO_ATR,current_class_idx);
        int num_params = get_atr1(fun_idx);

        int* param_types = parameter_map_function[fun_idx];
        param_types[num_params] = $1;
        num_params += 1;
        arg_position +=1;
        set_atr1(fun_idx, num_params);
        }
        
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
        if($1 == VOID)
          err("variable '%s' cannot have type void",$2);
        if (isClass==0){
          int var_indx = lookup_symbol($2, VAR|PAR);
          if(var_indx == NO_INDEX)
            insert_symbol($2, VAR, $1, ++var_num, NO_ATR,NO_ATR);
          else{
            if(get_atr3(var_indx) == NO_ATR){
              err("redefinition of '%s'", $2);
            }else{
              insert_symbol($2, VAR, $1, ++var_num, NO_ATR,NO_ATR);
            }
          }
        }else{
          if(lookup_symbol($2, VAR|PAR|ATR) == NO_INDEX)
            insert_symbol($2, VAR, $1, ++var_num, NO_ATR,current_class_idx);
          else {
            int var_indx =lookup_symbol($2,ATR);
            if(var_indx == NO_INDEX){
              err("redefinition of '%s'", $2);
            }else{
              if(get_atr3(var_indx) == current_class_idx){
                err("redefinition of '%s' attribute", $2);
              }else{
                insert_symbol($2, VAR, $1, ++var_num, NO_ATR,current_class_idx);
              }
            }
          }
        }
      }
  ;

statement_list
  : /* empty */
  | statement_list statement
  ;

statement
  : compound_statement
  | class_function
  | assignment_statement
  | if_statement
  | class_declaration
  | return_statement
  ;

class_function
  : _ID {
    int indx = lookup_symbol($1,INST);
    if(indx==NO_INDEX)
      err("unknown instance '%s'",$1);
    current_instance_idx=indx;
  }_DOT function_call  _SEMICOLON;

class_declaration
  : _CLASS _ID {
      isClass=1;
      if(lookup_symbol($2, CLAS) == NO_INDEX)
        err("'%s' is not a class", $2);
    }
  _ID {
    int idx=lookup_symbol($4,VAR|PAR|INST);
    if(idx == NO_INDEX){
      instance_index = lookup_symbol($2,CLAS);
      current_instance_idx = insert_symbol($4, INST, NO_TYPE, NO_ATR, NO_ATR,instance_index);
    }else{
      err("redefinition of '%s' ",$4);
    }
  }
  _ASSIGN _NEW _ID {
      if(lookup_symbol($8, CLAS) == NO_INDEX)
        err("'%s' is not a class", $8);
      if(lookup_symbol($2,CLAS) != lookup_symbol($8,CLAS)){
        err("invalid instance of class creation");
      }
    }
    _LPAREN {instance_declaration_arg_counter = 0;} class_argument_list 
        {
      int class_idx = lookup_symbol($2, CLAS);
      if(get_atr1(class_idx) != instance_declaration_arg_counter)
        err("wrong number of args to class '%s'", get_name(class_idx));
      for(int i=instance_declaration_arg_counter-1; i >= 0 ; i--){
            int indx = arguments_array[i];
            free_if_reg(indx);
            code("\n\t\tPUSH\t");
            gen_sym_name(indx);
      }
      instance_declaration_arg_counter = 0;
      isClass=0;
      code("\n\t\tCALL\t%s", get_name(class_idx));
      code("\n\t\tADDS\t%%15,$%d,%%15",get_atr1(class_idx) * 4);

  }

    _RPAREN _SEMICOLON
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
  {
    if(parameter_map[get_atr3(current_instance_idx)][instance_declaration_arg_counter] != get_type($1))
      err("incompatible type for argument in '%s'",get_name(get_atr3(current_instance_idx)));

    arguments_array[instance_declaration_arg_counter]=$1;
    instance_declaration_arg_counter += 1;
  }
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
        }else{
          int id_indx = lookup_symbol($1,VAR|PAR|ATR);
          if(id_indx == NO_INDEX){
            err("invalid lvalue '%s' in assignment", $1);
          }else{
            int is_atr = lookup_symbol($1,ATR);
            if(is_atr != NO_INDEX){
              if(get_atr3(is_atr) != current_class_idx)
                err("attribute not part of this class '%s' class '%s' ",$1,get_name(current_class_idx));
              else{
                  if(get_type(id_indx) != get_type($3))
                    err("incompatible types in assignment");
                  gen_mov($3, id_indx);
              }
            }else{
                if(get_type(id_indx) != get_type($3))
                  err("incompatible types in assignment");
                gen_mov($3, id_indx);
            }
          }
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
      isClass=1;
      int instance_indx = lookup_symbol($1,INST);
      current_class_idx= get_atr3(instance_indx);
      if(instance_indx==NO_INDEX){
        err("'%s' is not declared as class",$1);
      };      
      $$ = $3;
      isClass=0;
    }
  | _ID
      {
        if( isClass==0){
          $$ = lookup_symbol($1, VAR|PAR);
          if($$ == NO_INDEX)
            err("'%s' undeclared", $1);
        }else{
          int indx = lookup_symbol($1,VAR|PAR|ATR);
          $$ = indx;
          if($$ == NO_INDEX)
            err("'%s' undeclared", $1);
          if(lookup_symbol($1,VAR|PAR)==NO_INDEX){
            if(get_atr3(indx) != current_class_idx){
              err("'%s' undeclared, atr3 '%d' class idx '%d'", $1, get_atr3(indx),current_class_idx);
            }
          }
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
        arg_counter=0;
        if(isClass==0){
        fcall_idx = lookup_symbol($1, FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", $1);
        }
        else
        {
          fcall_idx = lookup_symbol($1, FUN);
          if(fcall_idx == NO_INDEX)
            err("'%s' is not a function", $1);
          if(get_atr3(fcall_idx) != current_class_idx){
            err("'%s' is not a function of class", $1);
          }
        }
      }
    _LPAREN argument_list _RPAREN
      {

          if(get_atr1(fcall_idx) != arg_counter)
            err("wrong number of arguments for function '%s' number of arguments '%d' ",get_name(fcall_idx), arg_counter);
          
          for(int i=arg_counter-1; i >= 0 ; i--){
            int indx = arguments_array[i];
            free_if_reg(indx);
            code("\n\t\tPUSH\t");
            gen_sym_name(indx);
           }

          code("\n\t\tCALL\t%s", get_name(fcall_idx));
          if(arg_counter > 0)
            code("\n\t\tADDS\t%%15,$%d,%%15", arg_counter * 4);
          set_type(FUN_REG, get_type(fcall_idx));
          $$ = FUN_REG;
          arg_counter=0;
          
      }
  ;

argument_list
  : /* empty */
   
  | arguments
 
  ;

arguments
  : argument
  | arguments _COMMA argument
  ;

argument
  : num_exp
    { 
      if(isClass==0){
        if(parameter_map_function[fcall_idx][arg_counter] != get_type($1)){
          err("incompatible arguments");
        }
        arguments_array[arg_counter]=$1;
        arg_counter += 1;

    
      }else{
        if(parameter_map_function[fcall_idx][arg_counter]  != get_type($1)){
          err("incompatible arguments");
        }
        arguments_array[arg_counter]=$1;
        arg_counter += 1;

    
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
      if(get_type(fun_idx) == VOID)
        err("Function cannot return value");
      else if(get_type(fun_idx) != get_type($2))
        err("incompatible types in return");
      return_count++;
        gen_mov($2, FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));        
      }
    | _RETURN _SEMICOLON
    {
      if(get_type(fun_idx) != VOID)
        warn("Function should return a value");
      return_count++; 
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

