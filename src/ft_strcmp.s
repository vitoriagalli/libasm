; prototype:		int		ft_strcmp(const char *s1, const char *s2)
; first argument:	rdi		(const char *s1)
; second argument:	rsi		(const char *s2)
; return value:		rax		al is the one byte rax
; data register		rdx		dl is the one byte rdx

global		ft_strcmp

section		.text

ft_strcmp:
	xor		rax, rax
	xor		rdx, rdx
	xor		rcx, rcx
.compare:
	mov		al, [rdi + rcx]		; brackets is used to move the value (s1)
	mov		dl, [rsi + rcx]		; move byte pointed to one byte register (s2)
	cmp		al, 0				; check \0 char in s1
	jz		.subtract
	cmp		al, dl				; compare both bytes pointed (s1 and s2)
	jnz		.subtract
	inc		rcx
	jmp		.compare
.subtract:
	sub		rax, rdx			; s1 - s2
	ret
