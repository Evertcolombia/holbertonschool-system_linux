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
	cmp bl, sil		; sil -> register for 8-bits -> esi
	je return
	
	while:

		inc edi
		mov bl, [edi]

		cmp bl, 0
		je mov_zero

		cmp bl, sil
		je return

		jmp while

	return:
		mov eax, edi
		ret

mov_zero:
	mov eax, 0
	ret
