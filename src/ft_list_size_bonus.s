global		ft_list_size

section		.text

;------------------------------------------------------------------------------;
; int	ft_list_size(t_list *begin_list);                                      ;
;------------------------------------------------------------------------------;

ft_list_size:
	xor		rax, rax
.looping:
	cmp		rdi, 0
	je		.end_of_list
	cmp		qword[rdi], 0
	je		.end_of_list
	inc		rax
	mov		rdi, [rdi + 8]
	jmp		.looping
.end_of_list:
	ret
