BITS 64

global asm_strlen	; Export our 'asm_strlen' function

	section .text

	; size_t asm_strlen(const char *str);
	; get the lenght of a str
	;
	; edi <- str
	;
	; Return: length of the str

asm_strlen:
	mov eax, 0		; init the counter in eax
	mov cl, [edi]		; get the byte value pointed by edi

	while: cmp cl, 0		; compare the value to \0
		jz return		; if null return
		inc eax			; Increment the counter
		inc edi			; increment the str pointer
		mov cl, [edi]		; get the byte value
		cmp cl, 0		; compare the value to \0
		jnz while		; if not zero jump to while again

	return:
	ret
