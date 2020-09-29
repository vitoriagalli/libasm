;------------------------------------------------------------------------------;
; size_t  ft_strlen(const char *s)                                             ;
;                                                                              ;
; 1st arg:  rdi  *s                                                            ;
; return :  rax  len                                                           ;
;------------------------------------------------------------------------------;

global		ft_strlen

section		.text

ft_strlen:
	xor		rcx, rcx
.nextchar:
	cmp		byte [rdi + rcx], 0
	jz		.exit
	inc		rcx
	jmp		.nextchar
.exit:
	mov		rax, rcx
	ret
