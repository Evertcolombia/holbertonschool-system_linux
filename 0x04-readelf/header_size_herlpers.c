#include "elfread.h"

void mannage_header_proSize(Elf32_Half phsize32, Elf64_Half phsize64, int sel)
{
	printf("  Size of program headers:");
	print_spaces(11);

	if (sel != 2)
		printf("%d (bytes)\n", phsize32);
	else
		printf("%d (bytes)\n", phsize64);
}

void manange_progHeader_num(Elf32_Half nsize32, Elf64_Half nsize64, int sel)
{
	printf("  Number of program headers:");
	print_spaces(9);

	if (sel != 2)
		printf("%d\n", nsize32);
	else
		printf("%d\n", nsize64);
}
