global		ft_list_sort

section		.text

; first argument:	rdi		t_list	**begin_list
; second argument:	rsi		int		(*cmp)()
ft_list_sort:
	mov		rcx, rsi			; mov *cmp() to rcx register
	mov		r8, rdi				; data pointer
	cmp		qword[r8], 0x0		; check if list is null
	je		.exit
	mov		r9, [r8]			; ptr
	cmp		qword[r9], 0x0		; check if list is null ??????
	je		.exit
.looping:
	mov		r10, [r9 + 8]		; ptr->next
	cmp		r10, 0
	je		.exit
	mov		rdi, [r9]			; ptr->data
	mov		rsi, [r10]			; ptr->next_data
	push	rcx					; (for some reason, rcx is restarted (zero) after it is called)
	call	rcx					; call *cmp() functior
	pop		rcx
	jg		.swap				; swap values if s1 > s2
	mov		r9, [r9 + 8]		; if is not, iterate pointers
	jmp		.looping
.swap:
	mov		r11, [r9]
	mov		r12, [r10]
	mov		[r9], r12
	mov		[r10], r11
	mov		r9, [r8]			; move the pointer to the beginning of the list
	jmp		.looping
.exit:
	ret
