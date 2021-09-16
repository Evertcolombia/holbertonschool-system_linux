BITS 64

global asm_strcmp		; Export our 'asm_strcmp; function

	section .text

	; int asm_strcmp(const char *s1, const char *s2)
	; compare two str
	;
	; edi <- const char s1
	; esi <- const char s2
	;
	; Return: value

asm_strcmp:
	mov bl, [edi]
	mov cl, [esi]
	
	sub bl, cl
	cmp bl, 0
	jne return

	while:	
		inc edi
		inc esi
		mov bl, [edi]
		mov cl, [esi]
							
		sub bl, cl
		cmp bl, 0
		jne return
		
		cmp cl, 0
		jne while

	return:
	;mov al, bl
	cmp bl, 0
	je return_zero
	jg return_signed
	jl return_unsigned

return_zero:
	mov eax, 0
	ret	

return_signed:
	mov eax, 1
	ret

return_unsigned:
	mov eax, -1
	ret
