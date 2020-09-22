;------------------------------------------------------------------------------;
; size_t	ft_read(int fd, void *buf, size_t count);                          ;
;                                                                              ;
; 1st arg:	rdi		file descriptor, output location STDIN (0)                 ;
; 2nd arg:	rsi		buffer (address of where to place data)                    ;
; 3th arg:	rdx		count (max numb of char to read)                           ;
; return :	rax		sys_read(0)                                                ;
;------------------------------------------------------------------------------;

global		ft_read

section		.text

extern		__errno_location

ft_read:
	mov		rax, 0
	syscall
	cmp		rax, 0
	jl		.error
	ret
.error:
	neg		rax
	push	rax
	call	__errno_location
	pop		qword[rax]
	mov		rax, -1
	ret
