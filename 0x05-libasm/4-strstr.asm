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

	mov bl, [edi]		; check is @haystack is null
	cmp bl, 0
	je return_null

	mov cl, [esi]		; check if @needle is null
	cmp cl, 0
	je return_haystack


	; while:

		;cmp bl, cl
		;je go_deep

return_null:
	mov eax, 0
	jmp end_program

return_haystack:
	mov rax, rdi
	jmp end_program

;go_deep:
;	cmp ebx, 0
;	je set_rax
;	while_deep:

;set_rax:
	;mov eax, edi
	;jmp while_deep	

end_program:
	pop r9
	mov rsp, rbp		; Restore previous stack frame
	pop rbp			; Those two lines are equivalent to 'leave'
	ret			; return to address in the stack IP
