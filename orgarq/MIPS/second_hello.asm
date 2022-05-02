	.data

	.align 0
msg: 	.asciiz “a”


	.text

main:
	li $v0, 4
	la $a0, msg
	syscall

	li $v0, 10
syscall