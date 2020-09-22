global		ft_list_remove_if

section		.text

;------------------------------------------------------------------------------;
; void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),   ;
;					void (*free_fct)(void *))                                  ;
;------------------------------------------------------------------------------;

ft_list_remove_if:
	mov		r8, rdi				; begin_list
	mov		r13, rsi			; data ref
	cmp		r8, 0				; check if pointer is null
	je		.exit
	cmp		qword[r8], 0		; check if list is null
	je		.exit
	mov		r9, [r8]			; ptr
.looping:
	cmp		qword[r8 + 8], 0	; check end of list
	je		.exit
	cmp		r9, 0
	je		.exit
	mov		rdi, [r9]			; ptr->data
	mov		rsi, r13
	push	rdx
	push	rcx
	call	rdx					; call *cmp() function
	pop		rcx
	pop		rdx
	je		.remove_node
	mov		r8, r9
	mov		r9, [r9 + 8]		; iterate pointers
	jmp		.looping
.remove_node:
	mov		rdi, r9
	cmp		[r8], r9
	je		.first_node
	mov		r9, [r9 + 8]
	mov		[r8 + 8], r9
	jmp		.free_node
.first_node:
	mov		r12, [r9 + 8]
	cmp		r12, 0
	je		.only_node
	mov		[r8], r12
	mov		r9, [r9 + 8]
	jmp		.free_node
.only_node:
	mov		qword[r8], 0
	mov		r9, 0
	jmp		.free_node
.free_node:
	push	r10
	push	rdx
	push	rcx
	call	rcx					; call *free_fct() functior
	pop		rcx
	pop		rdx
	pop		r10
	jmp		.looping
.exit:
	ret
