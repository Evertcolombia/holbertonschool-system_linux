BITS 64

global asm_strchr		; Export our 'asm_strchr' function

	section .text

	; char *asm_strchr(const char *s, int c);
	; find first occurrence of the character c in the string s.
	;
	; edi <- const char s
	; esi <- int c
	;
	; Return value

asm_strchr:

	mov bl, [edi]
	mov cl, sil		; register for 8-bits -> esi

	cmp bl, cl
	je return

	while:

		inc edi
		mov bl, [edi]

		cmp bl, cl
		je return
		jne while

	return:
		mov eax, edi
		ret
