
@funkcija1Test_body:
		MOV 	p,%13
		JMP 	@funkcija1Test_exit
@funkcija1Test_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$5,-4(%14)
			CALL	funkcija1Test
		MOV 	%13,-8(%14)
			CALL	funkcija1Test
		MOV 	%13,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET