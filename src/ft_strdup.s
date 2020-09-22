;------------------------------------------------------------------------------;
; char	*ft_strdup(const char *s)                                              ;
;                                                                              ;
; 1st arg:	rdi		str to duplicate                                           ;
; return :	rax		addr of the dup str                                        ;
;------------------------------------------------------------------------------;

global		ft_strdup

section		.text

extern		malloc
extern		ft_strlen
extern		ft_strcpy
extern		__errno_location

ft_strdup:
	push	rdi
	call	ft_strlen
	inc		rax
	mov		rdi, rax
	call	malloc
	pop		rdi
	or		rax, rax
	jz		.error
	mov		rsi, rdi
	mov		rdi, rax
	call	ft_strcpy
	jmp		.exit
.error:
	neg		rax
	push	rax
	call	__errno_location
	pop		qword[rax]
	mov		rax, -1
.exit:
	ret
