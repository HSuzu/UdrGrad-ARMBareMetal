	.cpu cortex-m4
 	.syntax unified
	.global _start
 	.thumb

    .thumb_func
_start:
	ldr sp, =_init_sp
	bl	init_memory
	bl	main

_exit:
	b	_exit
