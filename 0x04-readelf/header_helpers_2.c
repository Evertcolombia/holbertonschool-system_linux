#include "elfread.h"

void mannage_entry_point(Elf32_Addr entryP_32, Elf64_Addr entryP, int sel)
{
	printf("  Entry point address:");
	print_spaces(15);

	if (sel != 2)			
		printf("0x%x\n", entryP_32);
	else
		printf("0x%lx\n", entryP);
}

void mannage_prog_header(Elf32_Addr phoff32, Elf64_Addr phoff64, int sel)
{
	printf("  Start of program headers:");
	print_spaces(10);

	if (sel != 2)
		printf("%d (bytes into file)\n", phoff32);
	else
		printf("%lu (bytes into file)\n", phoff64);
}

void  mannage_prog_section(Elf32_Addr section32, Elf64_Addr section64, int sel)
{
	printf("  Start of section headers:");
	print_spaces(10);

	if (sel != 2)
		printf("%d (bytes into file)\n", section32);
	else
		printf("%lu (bytes into file)\n", section64);
}

void mannage_flags(Elf32_Word flags32, Elf64_Word flags64, int sel)
{
	printf("  Flags:");
	print_spaces(29);

	if (sel != 2)
		printf("0x%x\n", flags32);
	else
		printf("0x%x\n", flags64);
}

void mannage_header_size(Elf32_Half hsize32, Elf64_Half hsize64, int sel)
{
	printf("  Size of this header:");
	print_spaces(15);

	if (sel != 2)
		printf("%d (bytes)\n", hsize32);
	else
		printf("%d (bytes)\n", hsize64);
}
