global		ft_list_push_front

section		.text

extern		malloc
extern		__errno_location		; /usr/include/asm-generic/errno-base.h

;------------------------------------------------------------------------------;
; t_list  *ft_create_elem(void *data);                                         ;
;------------------------------------------------------------------------------;

ft_create_elem:
	push	rdi
	mov		rdi, 16			; sizeof(t_list) = 16
	call	malloc
	pop		rdi
	or		rax, rax
	jz		.error_memory
	mov		[rax], rdi
	mov		qword[rax + 8], 0
	ret
.error_memory:
	neg		rax
	push	rax
	call	__errno_location
	pop		qword[rax]		; erno addr has value 12 (ENOMEM out of memory)
	mov		rax, 0
	ret

;------------------------------------------------------------------------------;
; void  ft_list_push_front(t_list **begin_list, void *data);                   ;
; -----------------------------------------------------------------------------;

ft_list_push_front:
	cmp		rdi, 0
	je		.error
	cmp		rsi, 0			; data	(size of 8bytes = 64bits)
	je		.error
	push	rdi
	mov		rdi, rsi
	call	ft_create_elem
	pop		rdi
	cmp		rax, 0
	je		.error
.add_element:
	cmp		qword[rdi], 0
	je		.begin_list
	mov		rcx, [rdi]
	mov		[rax + 8], rcx
.begin_list:
	mov		[rdi], rax
	ret
.error:
	mov		rax, 0
	ret
