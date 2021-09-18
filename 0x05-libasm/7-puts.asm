BITS 64

global asm_puts			; Export our 'asm_puts function'
extern asm_strlen

	section .text
	; size_t asm_puts(const char *str);
	; prints a string of characters on the standard output
	;
	; edi <- const char str
	;
	; Return: total number of writen bytes to the output
asm_puts:

	push rbp		; saves base pointer into the stack
	mov rbp, rsp		; update base pointer to handle the current stack position

	; Save registers that are gonna be used in this
	; procedure, in case they were used before
	push rdi

	; call asm_strlen
	call asm_strlen
	mov r8, rax		; save the result on r15


	; Setup 'write' syscall
	mov rax, 1		; set Write syscall
	mov rdi, 1		; set write to stdout
	mov rdx, r8		; set write r15 bytes
	mov rsi, [rsp]

	syscall

end:
	pop rdi
	mov rsp, rbp
	pop rbp
	ret
