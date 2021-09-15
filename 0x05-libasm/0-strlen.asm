BITS 64

global asm_strlen	; Export our 'asm_strlen' function

	section .text

	; size_t asm_strlen(const char *str)
	; get the lenght of a str
	;
	;
	; edi <- str
	;
	; Return: length of the str

asm_strlen:
	mov eax, 0
	mov cl, [edi]
	while: cmp cl, 0
		jz return		
		inc eax
		inc edi
		mov cl, [edi]
		cmp cl, 0
		jnz while

	return:
	ret
