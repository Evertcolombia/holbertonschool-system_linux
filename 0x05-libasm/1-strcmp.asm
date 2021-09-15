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
	mov cl, [edi]
	mov bl, [esi]

	while: cmp cl, bl
		jne return

		cmp cl, 0
		jne return

		inc edi
		inc esi
		mov cl, [edi]
		mov bl, [esi]

		cmp cl, 0
		jne while
		je return

	return:
	mov al, bl
	cmp al, 0
	je return_zero

return_zero:
	mov eax, 0
	ret	

