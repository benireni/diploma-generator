		.data

		.align 0
greetings: 	.asciiz "Hello, World!"


		.text
		.globl main
main:
		li $v0, 4
		la $a0, greetings
		syscall

		li $v0, 10
		syscall