BITS 64

global asm_strcmp		; Export our 'asm_strcmp' function

	section .text

	; int asm_strcmp(const char *s1, const char *s2);
	; compare two str
	;
	; edi <- const char s1
	; esi <- const char s2
	;
	; Return: value

asm_strcmp:
	mov bl, [edi]		; get the byte value pointed by edi
	mov cl, [esi]		; get the byte value pointed by esi

	sub bl, cl		; subtract cl to bl and get the rest in bl
	cmp bl, 0		; compare bl to zero
	jnz return		; if not zero return

	while:
		inc edi			; increment the str pointer @s1
		inc esi			; increment the str pointer @s2
		mov bl, [edi]		; get the byte value pointed by @s1
		mov cl, [esi]		; get the byte value pointed by @s2

		sub bl, cl		; subtract cl to bl
		cmp bl, 0		; compare the result with 0
		jnz return		; if not zero return

		cmp cl, 0		; compare the value on cl
		jnz while		; if not zero jump while

	return:
	cmp bl, 0			; get the value to return
	je return_zero			; if zero
	jg return_signed		; greather than 0
	jl return_unsigned		; less than 0

return_zero:
	mov eax, 0		; return 0
	ret

return_signed:
	mov eax, 1		; return 1
	ret

return_unsigned:
	mov eax, -1		; return -1
	ret
