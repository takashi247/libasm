section	.text
		global _ft_strlen

_ft_strlen:
		mov	rdx, 0
		jmp	.loop
.loop:
		cmp	BYTE[rdi + rdx], 0
		je	.exit
		inc	rdx
		jmp	.loop
.exit:
		mov	rax, rdx
		ret
