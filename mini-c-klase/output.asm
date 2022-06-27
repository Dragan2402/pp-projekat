
age:
		WORD	1
height:
		WORD	1
weight:
		WORD	1
shoeSize:
		WORD	1
Person:
		PUSH	%14
		MOV 	%15,%14
		MOV 	8(%14),age
		MOV 	12(%14),height
		MOV 	16(%14),weight
		MOV 	20(%14),shoeSize
		JMP 	@Person_exit
@Person_exit:
		MOV 	%14,%15
		POP 	%14
		RET
getAge:
		PUSH	%14
		MOV 	%15,%14
@getAge_body:
		MOV 	age,%13
		JMP 	@getAge_exit
@getAge_exit:
		MOV 	%14,%15
		POP 	%14
		RET
getHeight:
		PUSH	%14
		MOV 	%15,%14
@getHeight_body:
		MOV 	height,%13
		JMP 	@getHeight_exit
@getHeight_exit:
		MOV 	%14,%15
		POP 	%14
		RET
getWeight:
		PUSH	%14
		MOV 	%15,%14
@getWeight_body:
		MOV 	weight,%13
		JMP 	@getWeight_exit
@getWeight_exit:
		MOV 	%14,%15
		POP 	%14
		RET
getShoe:
		PUSH	%14
		MOV 	%15,%14
@getShoe_body:
		MOV 	shoeSize,%13
		JMP 	@getShoe_exit
@getShoe_exit:
		MOV 	%14,%15
		POP 	%14
		RET
setAgeHeight:
		PUSH	%14
		MOV 	%15,%14
@setAgeHeight_body:
		MOV 	8(%14),age
		MOV 	8(%14),height
@setAgeHeight_exit:
		MOV 	%14,%15
		POP 	%14
		RET
getSumPlusFive:
		PUSH	%14
		MOV 	%15,%14
@getSumPlusFive_body:
		CALL	getAge
		MOV 	%13,%0
		CALL	getHeight
		MOV 	%13,%1
		ADDS	%0,%1,%0
		CALL	getWeight
		MOV 	%13,%1
		ADDS	%0,%1,%0
		CALL	getShoe
		MOV 	%13,%1
		ADDS	%0,%1,%0
		ADDS	%0,8(%14),%0
		MOV 	%0,%13
		JMP 	@getSumPlusFive_exit
@getSumPlusFive_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$20,%15
@main_body:
		MOV 	$25,-4(%14)
		MOV 	$180,-8(%14)
		MOV 	$80,-12(%14)
		MOV 	$43,-16(%14)
		MOV 	$5,-20(%14)
		PUSH	-16(%14)
		PUSH	-12(%14)
		PUSH	-8(%14)
		PUSH	-4(%14)
		CALL	Person
		ADDS	%15,$16,%15
		PUSH	$179
		PUSH	$24
		CALL	setAgeHeight
		ADDS	%15,$8,%15
		PUSH	-20(%14)
		CALL	getSumPlusFive
		ADDS	%15,$4,%15
		MOV 	%13,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET