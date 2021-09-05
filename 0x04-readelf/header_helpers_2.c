#include "elfread.h"

/**
 * mannage_entry_point - The virtual address to which
 * @entryP_32: entry pont for 32
 * @entryP: entry pont for 64
 * @sel: structure to use
 *
 * Return: None
 */
void mannage_entry_point(Elf32_Addr entryP_32, Elf64_Addr entryP, int sel)
{
	printf("  Entry point address:");
	print_spaces(15);

	if (sel != 2)
		printf("0x%x\n", entryP_32);
	else
		printf("0x%lx\n", entryP);
}

/**
 * mannage_prog_header - The program header table's file offset in bytes
 * @phoff32: offset in 32
 * @phoff64: offset in 64
 * @sel: structure to use
 *
 * Return: None
 */
void mannage_prog_header(Elf32_Addr phoff32, Elf64_Addr phoff64, int sel)
{
	printf("  Start of program headers:");
	print_spaces(10);

	if (sel != 2)
		printf("%d (bytes into file)\n", phoff32);
	else
		printf("%lu (bytes into file)\n", phoff64);
}


/**
 *  mannage_prog_section - The section header table's file offset in bytes
 * @section32: section in 32 bytes
 * @section64: section in 64 bytes
 * @sel: selecte structure
 *
 * Return: None
 */
void  mannage_prog_section(Elf32_Addr section32, Elf64_Addr section64, int sel)
{
	printf("  Start of section headers:");
	print_spaces(10);

	if (sel != 2)
		printf("%d (bytes into file)\n", section32);
	else
		printf("%lu (bytes into file)\n", section64);
}

/**
 * mannage_flags - Processor-specific flags associated with the file
 * @flags32: flags in 32 bytes
 * @flags64: flags in 64 bytes
 * @sel: selected structuree
 *
 * Return: None
 */
void mannage_flags(Elf32_Word flags32, Elf64_Word flags64, int sel)
{
	printf("  Flags:");
	print_spaces(29);

	if (sel != 2)
		printf("0x%x\n", flags32);
	else
		printf("0x%x\n", flags64);
}

/**
 * mannage_header_size - The ELF header's size in bytes.
 * @hsize32: size in 32 bytes
 * @hsize64: size in 64 bytes
 * @sel: selected structure
 *
 * Return: None
 */
void mannage_header_size(Elf32_Half hsize32, Elf64_Half hsize64, int sel)
{
	printf("  Size of this header:");
	print_spaces(15);

	if (sel != 2)
		printf("%d (bytes)\n", hsize32);
	else
		printf("%d (bytes)\n", hsize64);
}
