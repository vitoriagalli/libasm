;------------------------------------------------------------------------------;
; size_t    ft_write(int fd, const void *buf, size_t count)                    ;
;                                                                              ;
; 1st arg:  rdi file descriptor, output location STDOUT (1)                    ;
; 2nd arg:  rsi buffer (address of chars to write)                             ;
; 3th arg:  rdx count (numb of chars to output)                                ;
; return :  rax sys_write (1)                                                  ;
;------------------------------------------------------------------------------;

global		ft_write

section		.text

extern		__errno_location

ft_write:
	mov		rax, 1
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
