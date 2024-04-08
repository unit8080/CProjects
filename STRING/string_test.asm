	.file	"string_test.c"
	.intel_syntax
	.text
.globl main
	.type	main, @function
main:
	lea	%ecx, [%esp+4]
	and	%esp, -16
	push	DWORD PTR [%ecx-4]
	push	%ebp
	mov	%ebp, %esp
	push	%ecx
	sub	%esp, 20
	mov	DWORD PTR [%ebp-8], 0
	mov	%eax, DWORD PTR [%ebp-8]
	mov	DWORD PTR [%esp], %eax
	call	puts // <<<< see here >>>
	add	%esp, 20
	pop	%ecx
	pop	%ebp
	lea	%esp, [%ecx-4]
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.1.2 20080704 (Red Hat 4.1.2-52)"
	.section	.note.GNU-stack,"",@progbits
