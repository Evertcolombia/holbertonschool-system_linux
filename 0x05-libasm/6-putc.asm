BITS 64

global asm_putc			; Export our 'asm_putc' function

	section .text

	; size_t asm_putc(int c);
	; prints a single character on the standard output
	;
	; edi <- int c
	;
	; Return: number of printed char

asm_putc:

	push rbp		; saves base pointer into the stack
	mov rbp, rsp		; update base pointer to handle the current stack position

	; Save registers that are gonna be used in this
	; procedure, in case they were used before
	push rdi		; used as destination in I/O

	; Setup 'write' syscall
	mov rax, 1		; set Write syscall
	mov rdi, 1		; set write to stdout
	mov rdx, 1		; set write 1 byte
	mov rsi, rsp		; Adress of the character to be printed (adress of the stack)

	syscall			; exec the syscall

end:
	pop rdi

	mov rsp, rbp		; Restore previous stack frame
	pop rbp			; Those two lines are equivalent to 'leave'
        ret

