li $s0, $zero
lw $t0, 4($s0)
#lw $t0, $s0, 0
#$t0 = $s0
addi $t1, $t0, -7
#$t1 = $t0 - 7
add $t2, $t1, $t0
#$t2 = $t1 + $t0
addi $t3, $t2, 2
#$t3 = $t2 + 2
add $t4, $t3, $t2
#$t4 = $t3 + $t2
addi $t5, $t4, -28
#$t5 = $t4 - 28
add $t6, $t4, $t5
#$t6 = $t4 - $t5
addi $t7, $t6, 12
#$t7 = $t6 + 12
