; prototype:		char	*ft_strcpy(char *dest, const char *src)
; first argument:	rdi	dest
; second argument:	rsi	src
; return value:		rax	src address

global		ft_strcpy

section		.text

ft_strcpy:
	mov		rax, rdi
	xor		rcx, rcx			; rcx is counter
.looping:
	cmp		byte [rsi + rcx], 0	; compare the src pointed byte with zero
	jz		.exit
	mov		dl, [rsi + rcx]		; both operands cant be memory, use two instr
	mov		[rax + rcx], dl		; atribute src pointed byte to dest address
	inc		rcx
	jmp		.looping
.exit:
	mov		byte[rax + rcx], 0	; include the terminating null byte
	ret
