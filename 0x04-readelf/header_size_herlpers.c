#include "elfread.h"

/**
 * void mannage_header_proSize - The size in bytes of one entry
 * @phsize32: size in 32 bytes
 * @phsize64: size in 64 bytes
 * @sel: selected structure
 *
 * Return None
 */
void mannage_header_proSize(Elf32_Half phsize32, Elf64_Half phsize64, int sel)
{
	printf("  Size of program headers:");
	print_spaces(11);

	if (sel != 2)
		printf("%d (bytes)\n", phsize32);
	else
		printf("%d (bytes)\n", phsize64);
}
/**
 * manange_progHeader_num - The ELF header's size in bytes.
 * @nsize32: size in 32 bytes
 * @nsize32: size un 64 bytes
 * @sel: sekected structure
 *
 * Return: None
 */
void manange_progHeader_num(Elf32_Half nsize32, Elf64_Half nsize64, int sel)
{
	printf("  Number of program headers:");
	print_spaces(9);

	if (sel != 2)
		printf("%d\n", nsize32);
	else
		printf("%d\n", nsize64);
}

/**
 *  mannage_hdr_secSize - A section header's size in bytes.
 * @hssize32: size in 32 bytes
 * @hssize64: sizze in 64 bytes
 * @sel: selected structure
 *
 * Return: None
 */
void mannage_hdr_secSize(Elf32_Half hssize32, Elf64_Half hssize64, int sel)
{
	printf("  Size of section headers:");
	print_spaces(11);

	if (sel != 2)
		printf("%d (bytes)\n", hssize32);
	else
		printf("%d (bytes)\n", hssize64);
}


/**
 * mannage_hdrSec_num - The number of entries in the section header table.
 * @shnum32: entries for 32
 * @shnum64: entries for 64
 * @sel: structrue to use
 *
 * Return: None
 */
void mannage_hdrSec_num(Elf32_Half shnum32, Elf64_Half shnum64, int sel)
{
	printf("  Number of section headers:");
	print_spaces(9);

	if (sel != 2)
		printf("%d\n", shnum32);
	else
		printf("%d\n", shnum64);
}

/**
 * mannage_tableIndex - The section header table index 
 * @tindex32: index in 32
 * @tindex64: index in 64
 * @sel: structure to use
 *
 * Return: None
 */
void mannage_tableIndex(Elf32_Half tindex32, Elf64_Half tindex64, int sel)
{
	printf("  Section header string table index:");
	print_spaces(1);

	if (sel != 2)
		printf("%d\n", tindex32);
	else
		printf("%d\n", tindex64);
}
