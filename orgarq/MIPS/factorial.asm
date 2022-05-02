		.data
		
		.align 0
presentation: 	.asciiz "---------------\nFACTORIAL CALCULATOR\n\n"
input_request: 	.asciiz "Provide a number: "
		
introduction: 	.asciiz "The factorial of "
conclusion: 	.asciiz " is "

error_message: 	.asciiz "The number must not be negative."

		.text
		.globl main
main:
		la $a0, presentation
		li $v0, 4
		syscall
		
		la $a0, input_request
		li $v0, 4
		syscall
		
		li $v0, 5
		syscall
		
		move $a0, $v0
		move $s0, $a0
		
		jal factorial
		move $s1, $v0
		
		li $v0, 4
		la $a0, introduction
		syscall
		
		li $v0, 1
		move $a0, $s0
		syscall
		
		li $v0, 4
		la $a0, conclusion
		syscall
		
		li $v0, 1
		move $a0, $s1
		syscall
		
		li $v0, 10
		syscall
		
error_halt:
		li $v0, 4
		la $a0, error_message
		syscall

		li $v0, 10
		syscall
		
factorial:
		blt $a0, 0, error_halt
		li $v0, 1

		addi $sp, $sp, -4
		sw $a0, 0($sp)
					
		bgt $a0, 0, factorial_loop
		j factorial_conclusion
		
factorial_loop:
		mul $v0, $v0, $a0
		addi $a0, $a0, -1

		bgt $a0, 1, factorial_loop
		
factorial_conclusion:		
		lw $a0, 0($sp)
		addi $sp, $sp, 4
		
		jr $ra