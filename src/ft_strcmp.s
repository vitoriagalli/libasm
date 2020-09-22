;------------------------------------------------------------------------------;
; int		ft_strcmp(const char *s1, const char *s2)                          ;
;                                                                              ;
; 1st arg:	rdi		(const char *s1)                                           ;
; 2nd arg:	rsi		(const char *s2)                                           ;
; return :	rax		s1 - s2                                                    ;
;------------------------------------------------------------------------------;

global		ft_strcmp

section		.text

ft_strcmp:
	xor		rax, rax
	xor		rdx, rdx
	xor		rcx, rcx
.compare:
	mov		al, [rdi + rcx]
	mov		dl, [rsi + rcx]
	cmp		al, 0
	jz		.subtract
	cmp		dl, 0
	jz		.subtract
	cmp		al, dl
	jnz		.subtract
	inc		rcx
	jmp		.compare
.subtract:
	sub		rax, rdx
	ret
