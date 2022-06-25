
p:
		WORD	1
Dragan:
		PUSH	%14
		MOV 	%15,%14
		MOV 	8(%14),p
		JMP 	@Dragan_exit
@Dragan_exit:
		MOV 	%14,%15
		POP 	%14
		RET
funkcija1Test:
		PUSH	%14
		MOV 	%15,%14
@funkcija1Test_body:
		MOV 	p,%13
		JMP 	@funkcija1Test_exit
@funkcija1Test_exit:
		MOV 	%14,%15
		POP 	%14
		RET
pet:
		PUSH	%14
		MOV 	%15,%14
@pet_body:
		MOV 	8(%14),%13
		JMP 	@pet_exit
@pet_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$5,-4(%14)
		PUSH	-4(%14)
		CALL	Dragan
		ADDS	%15,$4,%15
		PUSH	-4(%14)
		CALL	funkcija1Test
		ADDS	%15,$4,%15
		MOV 	%13,-8(%14)
		PUSH	-4(%14)
		CALL	pet
		ADDS	%15,$4,%15
		MOV 	%13,%0
		MOV 	%0,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET