#include "elfread.h"

void mannage_entry_point(Elf64_Addr entryP)
{
	printf("  Entry point address:");
	print_spaces(15);
	printf("0x%03lx\n", entryP);
}
