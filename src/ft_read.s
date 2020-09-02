; prototype:		size_t	ft_read(int fd, void *buf, size_t count);
; return value:		rax		sys_read(0)
; first argument:	rdi		file descriptor, output location STDIN (0)
; second argument:	rsi		buffer (address of where to place data)
; third argument:	rdx		count (max numb of char to read)

global		ft_read

section		.text

extern		__errno_location

ft_read:
	mov		rax, 0			; sys_read syscall
	syscall
	cmp		rax, 0			; if rax < 0, is error
	jl		.error
	jmp		.exit
.error:
	imul	rax, -1
	mov		rdx, rax				; move the rax addr to rdx
	call	__errno_location		; return addr where to put the error value
	mov		qword[rax], rdx			; move rdx value to [rax]
	mov		rax, -1					; sinalize something went wrong
.exit:
	ret
