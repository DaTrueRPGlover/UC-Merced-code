.data
n:	.word 25
str1:	.asciiz "Less than\n"
str2:	.asciiz "Less than or equal to\n"
str3:	.asciiz "Greater than\n"
str4:	.asciiz "Greater than or equal to\n"

.text
main:	add     $t0, $0, $zero	
	li	$v0, 5
	syscall
#	lw	$t0, 0($v0)
	la      $t1, n
	lw      $t1, 0($t1)
	blt	$v0, $t1, lt
	ble	$v0, $t1, let
	bgt	$v0, $t1, bt
	bge	$v0, $t1, bet
	
lt: 	la      $t2, str1
	#lw      $t2, 0($t2)
	addi	$a0, $t2, 0
	li	$v0, 4
	syscall	
	li	$v0, 10
	syscall

let:	la      $t2, str2
	#lw      $t2, 0($t2)
	addi	$a0, $t2, 0
	li      $v0, 4		
	syscall	
	li	$v0, 10
	syscall

bt:	la      $t2, str3
	#lw      $t2, 0($t2)
	addi	$a0, $t2, 0
	li      $v0, 4		
	syscall	
	li	$v0, 10
	syscall

bet:	la      $t2, str4
	#lw      $t2, 0($t2)
	addi	$a0, $t2, 0
	li      $v0, 4		
	syscall	
	li	$v0, 10
	syscall
