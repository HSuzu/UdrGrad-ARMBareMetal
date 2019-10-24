	.cpu cortex-m4
 	.syntax unified
	.global _start
 	.thumb
	.section .bootloader, "ax", %progbits

    .thumb_func
_start:
	ldr	sp, =_init_sp
	bl	bootloader
	bl	init_memory
	bl	main

_exit:
	b	_exit
