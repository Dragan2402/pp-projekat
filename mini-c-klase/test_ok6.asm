
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
		SUBS	%15,$4,%15
@main_body:
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET