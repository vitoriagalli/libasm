; prototype:		size_t	ft_strlen(const char *s)
; first argument:	rdi	*s
; return value:		rax	len
; counter			rcx	i

global		ft_strlen

section		.text

ft_strlen:
	xor		rcx, rcx
.nextchar:
	cmp		byte [rdi + rcx], 0	; compare byte pointed with end of string
	jz		.exit				; jump if the zero flag has been set
	inc		rcx					; increment the addr in rcx by one byte
	jmp		.nextchar			; jump to the 'nextchar' subroutine
.exit:
	mov		rax, rcx		; rax now equals the number of bytes of the string
	ret
