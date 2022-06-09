
funkcija1Test:
		PUSH	%14
		MOV 	%15,%14
@funkcija1Test_body:
		JGTU	?,?,%0
@funkcija1Test_exit:
		MOV 	%14,%15
		POP 	%14
		RET
funkcija2Test:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@funkcija2Test_body:
		MOV 	%13,%1
		JGTU	?,?,%2
@funkcija2Test_exit:
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