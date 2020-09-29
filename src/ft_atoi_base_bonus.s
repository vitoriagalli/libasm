global		ft_atoi_base

extern		ft_strlen

section		.text

;------------------------------------------------------------------------------;
; int  ft_is_space(char c);                                                    ;
;------------------------------------------------------------------------------;

ft_is_space:
	cmp		byte [rdi], 0x09
	je		.is_space
	cmp		byte [rdi], 0x0A
	je		.is_space
	cmp		byte [rdi], 0x0B
	je		.is_space
	cmp		byte [rdi], 0x0C
	je		.is_space
	cmp		byte [rdi], 0x0D
	je		.is_space
	cmp		byte [rdi], 0x20
	je		.is_space
.is_not_space:
	mov		rax, -1
	ret
.is_space:
	mov		rax, 1
	ret

;------------------------------------------------------------------------------;
; int  ft_is_sign(char c);                                                     ;
;------------------------------------------------------------------------------;

ft_is_sign:
	cmp		byte [rdi], 0x2B
	je		.is_plus
	cmp		byte [rdi], 0x2D
	je		.is_minus
	mov		rax, 0
	ret
.is_plus:
	mov		rax, 1
	ret
.is_minus:
	mov		rax, -1
	ret

;------------------------------------------------------------------------------;
; int  ft_dup_char(char *rest_string_to_compare);                              ;
;------------------------------------------------------------------------------;

ft_dup_char:
	mov		r9b, byte[rsi]
	inc		rsi
.looping:
	cmp		byte [rsi], 0
	je		.end_of_str
	cmp		byte [rsi], r9b
	je		.dup_char
	inc		rsi
	jmp		.looping
.dup_char:
	mov		rax, 1
	ret
.end_of_str:
	mov		rax, 0
	ret

;------------------------------------------------------------------------------;
; int  ft_check_base(char *base);                                              ;
;------------------------------------------------------------------------------;

ft_check_base:
	cmp		byte[rdi], 0
	je		.b_error
	call	ft_strlen
	cmp		rax, 1
	jle		.b_error
	push	rax
.loop_check_char:
	cmp		byte [rdi], 0
	je		.end_of_base
	call	ft_is_space
	cmp		rax, 0
	jg		.base_error
	call	ft_is_sign
	cmp		rax, 0
	jne		.base_error
	push	rsi
	mov		rsi, rdi
	call	ft_dup_char
	pop		rsi
	cmp		rax, 0
	jg		.base_error
	inc		rdi
	jmp		.loop_check_char
.end_of_base:
	pop		rax
	ret
.base_error:
	pop		rax
.b_error:
	mov		rax, 0
	ret

;------------------------------------------------------------------------------;
; int  ft_posit_base(char *str_posit_pointer, char *base);                     ;
;------------------------------------------------------------------------------;

ft_posit_base:
	xor		rax, rax
	mov		cl, [rdi]
.nextchar:
	cmp		byte [rsi + rax], 0
	jz		.not_base
	cmp		cl, [rsi + rax]
	je		.posit
	inc		rax
	jmp		.nextchar
.posit:
	ret
.not_base:
	mov		rax, -1
	ret

;------------------------------------------------------------------------------;
; int  ft_atoi_base(char *str, char *base);                                    ;
;------------------------------------------------------------------------------;

ft_atoi_base:
	cmp		rdi, 0
	je		.error
	cmp		rsi, 0
	je		.error
	push	rdi				; store str address
	mov		rdi, rsi		; mov the base addr to the argument
	call	ft_check_base	; check and return the base_len if it works
	mov		rbx, rax		; store base_len to some register
	pop		rdi				; recover str address
	cmp		rbx, 0			; if base_error, exit function
	je		.error
	dec		rdi
.while_is_space:
	inc		rdi
	call	ft_is_space
	cmp		rax, 0
	jg		.while_is_space
	mov		r9, 1
	mov		rax, 1
	dec		rdi
.while_is_sign:
	mul		r9
	mov		r9, rax
	inc		rdi
	call	ft_is_sign
	cmp		rax, 0
	jne		.while_is_sign
	call	ft_posit_base	; return the posit of the char on the base string
	cmp		rax, 0			; check if (char) belongs to the base
	jl		.error
	inc		rdi;
.loop_is_base:
	push	rax;			; store posit
	call	ft_posit_base
	mov		rcx, rax		; save new posit into other register
	pop		rax				; recover posit
	cmp		rcx, 0			; check if (char) belongs to the base
	jl		.exit
	mul		rbx				; rax = rax * rbx, rbx is base_size
	add		rax, rcx		; add the new posit
	inc		rdi				; increment string  address
	jmp		.loop_is_base
.exit:
	mul		r9
	ret
.error:
	mov		rax, 0
	ret
