		.data
		
		.align 0
input_request:	.asciiz "Provide the two numbers that you wish to get MDC:\n"

		.text
		.globl main
main:
		li $v0, 5
		syscall
		move $t0, $v0
		
		li $v0, 5
		syscall
		move $t1, $v0
		
		li $t2, 16 #divisor iterator
		j calculate_mdc
		
calculate_mdc:
		div $t0, $t2
		mfhi $t3 #remainder of t0
		
		div $t1, $t2
		mfhi $t4 #remainder of t1
		
		beq $t3, $t4, check_mdc
		
		bgt $t2, $t0, output_one
		bgt $t2, $t1, output_one
		
		addi $t2, $t2, -1
		j calculate_mdc
		
check_mdc:
		beqz $t3, output_mdc
		j calculate_mdc
		
output_one:
		li $a0, 1
		j print_result
		
output_mdc:
		mflo $s0
		move $a0, $t2
		
print_result:	
		li $v0, 1
		syscall
		
		li $v0, 10
		syscall	