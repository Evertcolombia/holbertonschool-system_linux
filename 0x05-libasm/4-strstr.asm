BITS 64

global asm_strstr		; Export our 'asm_strstr' function

	section .text

	; char *asm_strstr(const char *haystack, const char *needle);
	; find first occurrence of the str needle
	; in the string haystack
	;
	; edi <- const char haystack
	; esi <- const char needle
	;
	; Return value

asm_strstr:

	push rbp ; saves base pointer into the stack
	mov rbp, rsp ; update base pointer to handle the current stack position

	push r9
	mov r9b, [esi]		; save a copy of esi p value
	mov rbx, 0

	mov cl, [edi]		; check is @haystack is null
	cmp cl, 0
	jz return_null

	cmp r9b, 0		; check if @needle is null
	jz return_haystack

	while:
		mov r9b, [esi + ebx]		; ebx will control the @neddle position
		mov cl, [edi]			; update the @haystack position

		cmp cl, r9b		;	compare both values
		je go_deep		; if are equal
		jne reset_needle	; if are not equal

		after_reset:
			inc edi
			mov cl, [edi]
			cmp cl, 0
			jz end_program
			jnz while
return_null:
	mov eax, 0
	jmp end_program

return_haystack:
	mov rax, rdi
	jmp end_program

reset_needle:
	mov rbx, 0
	mov rax, 0
	jmp after_reset

go_deep:
	cmp ebx, 0
	je set_rax
	;while_deep:
		; from here we need take the rest of
		;comparations

set_rax:
	mov eax, edi
	;jmp while_deep

end_program:
	pop r9
	mov rsp, rbp		; Restore previous stack frame
	pop rbp			; Those two lines are equivalent to 'leave'
	ret			; return to address in the stack IP
