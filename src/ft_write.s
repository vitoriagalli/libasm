; prototype:		size_t	ft_write(int fd, const void *buf, size_t count)
; return value:		rax		sys_write (1)
; first argument:	rdi		file descriptor, output location STDOUT (1)
; second argument:	rsi		buffer (address of chars to write)
; third argument:	rdx		count (numb of chars to output)

global		ft_write

section		.text

extern		__errno_location

ft_write:
	mov		rax, 1		; sys_write syscall
	syscall
	cmp		rax, 0		; if error rax < 0
	jl		.error
	jmp		.exit
.error:
	imul	rax, -1
	mov		rdx, rax			; save the value of the error type
	call	__errno_location	; ret the address where to put the error value
	mov		qword[rax], rdx
	mov		rax, -1
.exit:
	ret
