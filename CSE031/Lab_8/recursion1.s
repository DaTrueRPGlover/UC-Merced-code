.data
prompt: .asciiz "Please enter a number: "

.text
.globl main
main:

li $v0, 4 #Print prompt
la $a0, prompt
syscall

li $v0, 5 #Read int
syscall
move $s0, $v0 #Store the int in $s0

jal recursion #Call recursion

li $v0, 1 #Print result
move $a0, $v0
syscall

li $v0, 10 #Exit
syscall

recursion:

addi $sp, $sp, -4 #Move stack pointer down 4
sw $ra, 0($sp) #Store return address

slti $t0, $s0, -1 #Check if m == -1
bne $t0, $0, not_m_minus_1
li $v0, 3 #Return 3
jr $ra

not_m_minus_1:
slti $t0, $s0, -2 #Check if m <= -2
bne $t0, $0, not_m_minus_2
slti $t0, $s0, -3 #Check if m < -2
beq $t0, $0, m_minus_2
j m_minus_1

m_minus_2:
li $v0, 2 #Return 2
jr $ra

m_minus_1:
li $v0, 1 #Return 1
jr $ra

not_m_minus_2:
addi $t1, $s0, 3 #m - 3
sw $s0, 0($sp) #Store m on stack

jal recursion #Call recursion
lw $s0, 0($sp) #Restore $s0

lw $ra, 0($sp) #Restore return address
addi $sp, $sp, 4 #Move stack pointer up 4

add $v0, $v0, $s0 #Add recursion result and m
jr $ra

exit:
li $v0, 10
syscall
