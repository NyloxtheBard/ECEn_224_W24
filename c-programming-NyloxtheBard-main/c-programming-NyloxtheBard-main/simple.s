	.arch armv8-a
	.file	"simple.c"
	.text
	.align	2
	.global	fun_number
	.type	fun_number, %function
fun_number:
.LFB0:
	.cfi_startproc
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	mov	w0, 10
	str	w0, [sp, 12]
	ldr	w0, [sp, 12]
	add	sp, sp, 16
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE0:
	.size	fun_number, .-fun_number
	.align	2
	.global	multiplication
	.type	multiplication, %function
multiplication:
.LFB1:
	.cfi_startproc
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	s0, [sp, 12]
	str	s1, [sp, 8]
	ldr	s1, [sp, 12]
	ldr	s0, [sp, 8]
	fmul	s0, s1, s0
	add	sp, sp, 16
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE1:
	.size	multiplication, .-multiplication
	.section	.rodata
	.align	3
.LC0:
	.string	"Hello, World!"
	.align	3
.LC1:
	.string	"This is a funny number: %d\n"
	.align	3
.LC2:
	.string	"This is multiplication: %f\n"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
.LFB2:
	.cfi_startproc
	stp	x29, x30, [sp, -16]!
	.cfi_def_cfa_offset 16
	.cfi_offset 29, -16
	.cfi_offset 30, -8
	mov	x29, sp
	adrp	x0, .LC0
	add	x0, x0, :lo12:.LC0
	bl	puts
	bl	fun_number
	mov	w1, w0
	adrp	x0, .LC1
	add	x0, x0, :lo12:.LC1
	bl	printf
	mov	w0, 62915
	movk	w0, 0x4048, lsl 16
	fmov	s1, w0
	fmov	s0, 1.0e+1
	bl	multiplication
	fcvt	d0, s0
	adrp	x0, .LC2
	add	x0, x0, :lo12:.LC2
	bl	printf
	mov	w0, 0
	ldp	x29, x30, [sp], 16
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
