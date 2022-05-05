		.data
		
		.align 0
input_request:	.asciiz "Provide the two strings that you wish to compare separated by an enter:\n"
		
base_str:	.space 32
compared_str:	.space 32

		.text
		.globl main
		
main:
		la $a0, input_request
		li $v0, 4
		syscall

		la $a0, base_str
		li $a1, 30
		li $v0, 8
		syscall
		
		la $a0, compared_str
		li $a1, 30
		li $v0, 8
		syscall
		
		la $t0, base_str
		la $t2, compared_str
		
compare:
		lb $t1, 0($t0)
		lb $t3, 0($t2)

		beqz $t1, route_diff
		beqz $t3, route_diff
		
		bne $t1, $t3, route_diff
		
		addi $t0, $t0, 1
		addi $t2, $t2, 1
				
		j compare
		
route_diff:
		bgt $t1, $t3, output_gt
		blt $t1, $t3, output_lt
		beq $t1, $t3, output_eq
		
output_gt:	li $a0, -1
		j print_result

output_lt:	li $a0, 1
		j print_result

output_eq:	li $a0, 0
		j print_result

print_result:
		li $v0, 1
		syscall
		
		li $v0, 10
		syscall