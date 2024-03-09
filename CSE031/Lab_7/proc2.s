		.data
x:		.word 5
y:		.word 10
m:		.word 15
b:		.word 2

		.text
MAIN:	la $t0, x
		lw $s0, 0($t0)		# s0 = x
		la $t0, y
		lw $s1, 0($t0)		# s1 = y
		add $s2,$zero,$s0	#s2=x
		
		# Prepare to call sum(x)
		add $a0, $zero, $s0	# Set a0 as input argument for SUM
		jal SUM
		add $t0, $s1, $s2
		add $s3, $t0, $v0
		addi $a0, $s3, 0 
		li $v0, 1		 
		syscall	
		j END

		
SUM: 	la $t0, m
		lw $s0, 0($t0)		# s0 = m
		add $a1,$zero,$a0
		add $a0, $s0, $a0	# Update a0 as new argument for SUB
		add $k0,$zero,$ra	#hold the return address in k0
		jal SUB
		add $v0, $a1, $v0
		jr $k0		
		
SUB:	la $t0, b
		addi $sp, $sp 4
		sw $s0, 0($sp)		# Backup s0 from SUM
		lw $s0, 0($t0)		# s0 = b
		sub $v0, $a0, $s0
		lw $s0, 0($sp)		# Restore s0 from SUM
		addi $sp, $sp 4
		jr $ra

		
END:
