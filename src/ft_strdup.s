; prototype:		char	*ft_strdup(const char *s)
; first argument:	rdi	str to duplicate
; return value:		rax

global		ft_strdup

section		.text

extern		malloc
extern		ft_strlen
extern		ft_strcpy
extern		__errno_location		; /usr/include/asm-generic/errno-base.h

ft_strdup:
	call	ft_strlen
	inc		rax			; allocate null terminating byte
	push	rdi			; backup the first argument address (str)
	mov		rdi, rax	; argument to call malloc
	call	malloc		; return a pointer to a chunck of memory allocated
	pop		rdi			; recover the str addr (remove input addr from stack)
	or		rax, rax	; check return pointer from malloc
	jz		.error		; if is zero, error
	jmp		.copy
.error:
	call	__errno_location	; return the addr erno
	mov		qword[rax], 12		; erno addr has value 12 (ENOMEM out of memory)
	mov		rax, 0
	jmp		.exit
.copy:
	mov		rsi, rdi	; move the src addr to the second argument register
	mov		rdi, rax	; move the allocated pointer to the dest address
	call	ft_strcpy
.exit:
	ret
