;------------------------------------------------------------------------------;
; char *ft_strcpy(char *dest, const char *src)                                 ;
;                                                                              ;
; 1st arg:  rdi  dest                                                          ;
; 2nd arg:  rsi  src                                                           ;
; return :  rax  src address                                                   ;
;------------------------------------------------------------------------------;

global		ft_strcpy

section		.text

ft_strcpy:
	mov		rax, rdi
	xor		rcx, rcx
.looping:
	cmp		byte [rsi + rcx], 0
	jz		.exit
	mov		dl, [rsi + rcx]
	mov		[rax + rcx], dl
	inc		rcx
	jmp		.looping
.exit:
	mov		byte[rax + rcx], 0
	ret
