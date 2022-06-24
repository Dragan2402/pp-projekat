
@funkcija1Test_body:
		ADDS	p,8(%14),%0
		MOV 	%0,%13
		JMP 	@funkcija1Test_exit
@funkcija1Test_exit:
		MOV 	%14,%15
		POP 	%14
		RET
		SUBS	%15,$4,%15
@funkcija2Test_body:
			PUSH	$6
			CALL	funkcija1Test
			ADDS	%15,$4,%15
		MOV 	%13,%0
		MOV 	%0,-4(%14)
		ADDS	-4(%14),8(%14),%0
		MOV 	%0,%13
		JMP 	@funkcija2Test_exit
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