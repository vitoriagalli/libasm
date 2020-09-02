; ft_list_size prototype
; int	ft_list_size(t_list *begin_list)

; first argument:	rdi		t_list	*begin_list

global		ft_list_size

section		.text

ft_list_size:
	xor		rax, rax
.looping:
	cmp		rdi, 0x0
	je		.end_of_list
	cmp		qword[rdi], 0x0
	je		.end_of_list
	inc		rax
	mov		rdi, [rdi + 8]
	jmp		.looping
.end_of_list:
	ret
