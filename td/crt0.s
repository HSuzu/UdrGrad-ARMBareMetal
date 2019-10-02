	.cpu cortex-m4
 	.syntax unified
	.global _start
 	.thumb

	.EXTERN	_init_sp[WEAK]

_start:
	ldr sp, =_init_sp
#	ldr sp, [r0]
	mov r0, 0
	bl	init_bss
	bl	main

_exit:
	b	_exit
