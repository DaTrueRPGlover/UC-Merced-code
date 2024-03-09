.data
str1:	.asciiz "Please enter a number: "
str2:	.asciiz "Sum of even numbers is: "
str3:	.asciiz "Sum of odd numbers is: "
nwl:	.asciiz "\n"
odds:	.word 0
evens:	.word 0 

.text
main:	la $a0, str1
	li $v0, 4
	syscall
	
loop:	add $t0, $0, $zero
	li $v0, 5
	syscall
	move $t0, $v0
	
	beq $t0, $zero, finish
	
	srl $t1, $t0, 1
	sll $t1, $t1, 1
	bne $t1, $t0, oddn
	
even:	lw $t2, evens
	add $t2, $t2, $t0
	sw $t2, evens
	la $a0, str1
	li $v0, 4
	syscall
	j loop
	
oddn:	lw $t2, odds
	add $t2, $t2, $t0
	sw $t2, odds
	la $a0, str1
	li $v0, 4
	syscall
	j loop
	
finish:	lw $t2, evens
	lw $t3, odds
	la $a0, str2
	li $v0, 4
	syscall
	move $a0, $t2
	li $v0, 1
	syscall
	la $a0, nwl
	li $v0, 4
	syscall
	la $a0, str3
	li $v0, 4
	syscall
	move $a0, $t3
	li $v0, 1
	syscall
	la $a0, nwl
	li $v0, 4
	syscall
	
	li $v0, 10
	syscall