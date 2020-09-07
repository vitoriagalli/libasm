global		ft_atoi_base

extern		ft_strlen
extern		ft_strcpy

section		.text

; prototype			int	ft_is_space(char c)
; first argument	rdi	char to compare

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

; prototype:		int	ft_is_sign(char c)
; first argument	rdi	char to compare

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

; prototype			int	ft_dup_char(char *rest_string)
; first argument	rsi	address of the rest of the base to compare

ft_dup_char:
	mov		r9b, byte[rsi]		; move the char to a one byte string
	inc		rsi
.looping:
	cmp		byte [rsi], 0		; check if is end of str
	je		.end_of_str
	cmp		byte [rsi], r9b		; check if pointer base equals to the char
	je		.dup_char
	inc		rsi
	jmp		.looping
.dup_char:
	mov		rax, 1
	ret
.end_of_str:
	mov		rax, 0
	ret

; prototype:		int	ft_check_base(char *base)
; first argument	rdi	base

ft_check_base:
	cmp		byte[rdi], 0		; check if base is null
	je		.b_error
	call	ft_strlen
	cmp		rax, 1
	jle		.b_error			; check if base <= 1
	push		rax				; store base addr
.loop_check_char:
	cmp		byte [rdi], 0
	je		.end_of_base
	call	ft_is_space		; check if base has space
	cmp		rax, 0
	jg		.base_error
	call	ft_is_sign		; check if base has sign
	cmp		rax, 0
	jne		.base_error
	push	rsi
	mov		rsi, rdi
	call	ft_dup_char		; check if base has duplicate char
	pop		rsi
	cmp		rax, 0
	jg		.base_error
	inc		rdi					; increment base addr
	jmp		.loop_check_char
.end_of_base:
	pop		rax
	ret
.base_error:
	pop		rax
.b_error:
	mov		rax, 0
	ret

; prototype:		int	ft_posit_base(char *str, char base)
; first argument	rdi	str
; second argument	rsi	base

ft_posit_base:
	xor		rax, rax
	mov		cl, [rdi]			; move the char value into a one byte register
.nextchar:
	cmp		byte [rsi + rax], 0	; check if is end of base
	jz		.not_base
	cmp		cl, [rsi + rax]		; compare char with base pointer
	je		.posit
	inc		rax
	jmp		.nextchar
.posit:
	ret
.not_base:
	mov		rax, -1
	ret

; prototype:		int		ft_atoi_base(char *str, char *base)
; first argument	rdi		str
; second argument	rsi		base

ft_atoi_base:
	cmp		rdi, 0			; check if str is null
	je		.error
	cmp		rsi, 0			; check if base is null
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
	jg		.while_is_space	; loop to increment char that is space
	mov		r9, 1
	mov		rax, 1
	dec		rdi
.while_is_sign:
	mul		r9
	mov		r9, rax
	inc		rdi
	call	ft_is_sign
	cmp		rax, 0
	jne		.while_is_sign	; loop to get the signal result
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
	mul		r9				; verify the sign
	ret
.error:
	mov		rax, 0
	ret
