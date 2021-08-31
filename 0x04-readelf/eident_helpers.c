#include "elfread.h"

/**
 * mannage_magic - print magic memory content
 * @e_ident: initial bytes mark the file as an object file
 *
 * Return: None
 */
void mannage_magic(unsigned char e_ident[EI_NIDENT])
{
	int i = 0;

	printf("  Magic:   ");
	for(; i < (EI_NIDENT- 1); i++)
		printf("%02x ", e_ident[i]);
	printf("%02x\n", e_ident[i]);

}

/**
 * mannage_class - print the class value for elf header
 * @class: value to compare
 *
 * Return: None
 */
void mannage_class(unsigned char class)
{
	Hdr_t h_types[] = {
		{ELFCLASS32, "ELF32"},
	      	{ELFCLASS64, "ELF64"},
		{ELFCLASSNONE, "Invalid class"}
	};

	printf("  Class:");
	print_spaces(29);
	struct_iterator(h_types, 3, class);
}
