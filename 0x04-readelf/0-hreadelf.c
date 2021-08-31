#include "elfread.h"

/**
 * mannage_error - error mannager
 * @msg: mesagge to print
 * @code: code to exit
 *
 * Return None
 */
void mannage_error(char *msg, int code)
{
	dprintf(STDERR_FILENO, "%s", msg);
	exit(code);
}

/**
 * main - entry point
 * @argc: args count
 * @argv: args list
 *
 * Return 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	Elf32_Ehdr header_32;
	Elf64_Ehdr header_64;


	if (argc != 2)
		mannage_error("Usage: elf-header <ELF-file>\n", 0);

	header_64 = read_header(&fp, argv[1], &header_32);

	/* Parse the rest of the ELF file here. */
	printf("ELF Header:\n");
	mannage_magic(header_64.e_ident);

	/* Don't forget to close the file. */
	fclose(fp);
	return (0);
}
