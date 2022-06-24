
@funkcija1Test_body:
		MOV 	p,%13
		JMP 	@funkcija1Test_exit
@funkcija1Test_exit:
		MOV 	%14,%15
		POP 	%14
		RET
@getAge_body:
		MOV 	age,%13
		JMP 	@getAge_exit
@getAge_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$6,-8(%14)
		MOV 	$5,-4(%14)
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET