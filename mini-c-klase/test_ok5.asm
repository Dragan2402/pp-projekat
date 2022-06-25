
a:
		WORD	1
b:
		WORD	1
Rectangle:
		PUSH	%14
		MOV 	%15,%14
		MOV 	8(%14),a
		MOV 	12(%14),b
		JMP 	@Rectangle_exit
@Rectangle_exit:
		MOV 	%14,%15
		POP 	%14
		RET
getA:
		PUSH	%14
		MOV 	%15,%14
@getA_body:
		ADDS	a,8(%14),%0
		MOV 	%0,%13
		JMP 	@getA_exit
@getA_exit:
		MOV 	%14,%15
		POP 	%14
		RET
getB:
		PUSH	%14
		MOV 	%15,%14
@getB_body:
		MOV 	b,%13
		JMP 	@getB_exit
@getB_exit:
		MOV 	%14,%15
		POP 	%14
		RET
r:
		WORD	1
Circle:
		PUSH	%14
		MOV 	%15,%14
		MOV 	16(%14),r
		JMP 	@Circle_exit
@Circle_exit:
		MOV 	%14,%15
		POP 	%14
		RET
getR:
		PUSH	%14
		MOV 	%15,%14
@getR_body:
		MOV 	r,%13
		JMP 	@getR_exit
@getR_exit:
		MOV 	%14,%15
		POP 	%14
		RET
getRFull:
		PUSH	%14
		MOV 	%15,%14
@getRFull_body:
		ADDS	r,r,%0
		MOV 	%0,%13
		JMP 	@getRFull_exit
@getRFull_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$20,%15
@main_body:
		MOV 	$5,-4(%14)
		MOV 	$6,-8(%14)
		MOV 	$5,-20(%14)
		PUSH	-8(%14)
		PUSH	-4(%14)
		CALL	Rectangle
		ADDS	%15,$8,%15
		PUSH	-20(%14)
		CALL	getA
		ADDS	%15,$4,%15
		MOV 	%13,-12(%14)
		CALL	getB
		MOV 	%13,-16(%14)
		PUSH	-4(%14)
		CALL	Circle
		ADDS	%15,$4,%15
		CALL	getRFull
		MOV 	%13,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET