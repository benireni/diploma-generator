		.data
		.align 0
base_str:	.asciiz "pica-pau"
target_str:	.asciiz " jantando"

		.text
		.globl main
main:
		la $t0, base_str
		lb $t1, 0($t0)
		
		la $t2, target_str
		lb $t3, 0($t2)
base_length_loop:
		beqz $t1, concatenate_target_str
		
		addi $t0, $t0, 1
		lb $t1, 0($t0)
		
		j base_length_loop
		
concatenate_target_str:
		beqz $t3, print_str
		
		sb $t3, 0($t0)
		
		addi $t0, $t0, 1
		addi $t2, $t2, 1
		
		lb $t3, 0($t2)
		
		j concatenate_target_str
		
print_str:
		sb $t3, 0($t0)
		
		li $v0, 4
		la $a0, base_str
		syscall
		
		li $v0, 10
		syscall
		
		