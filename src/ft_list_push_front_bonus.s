; first argument:	rdi		t_list	**begin_list
; second argument:	rsi		void	*data	(size of 8bytes = 64bits)

global		ft_list_push_front

section		.text

extern		malloc
extern		__errno_location		; /usr/include/asm-generic/errno-base.h

; first argument:	rdi		void *data
ft_create_elem:
	push	rdi
	mov		rdi, 16				; sizeof(t_list) = 16
	call	malloc
	pop		rdi
	or		rax, rax
	jz		.error
	mov		[rax], rdi
	mov		qword[rax + 8], 0x0	; qword = 64 bits
	jmp		.exit
.error:
	call	__errno_location	; return the addr erno
	mov		qword[rax], 12		; erno addr has value 12 (ENOMEM out of memory)
	mov		rax, 0
.exit:
	ret

ft_list_push_front:
	push	rdi
	mov		rdi, rsi
	call	ft_create_elem
	pop		rdi
	cmp		qword[rdi], 0
	je		.begin_list
.add_element:
	mov		rcx, [rdi]
	mov		[rax + 8], rcx
.begin_list:
	mov		[rdi], rax
	ret
