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
	int select = 0;


	if (argc != 2)
		mannage_error("Usage: elf-header <ELF-file>\n", 0);

	header_64 = read_header(&fp, argv[1], &header_32);
	endian_check(&header_64, &header_32);

	/* Parse the rest of the ELF file here. */
	printf("ELF Header:\n");
	mannage_magic(header_64.e_ident);
	mannage_class(header_64.e_ident[4]);
	mannage_data(header_64.e_ident[5]);
	mannage_version(header_64.e_ident[6]);
	mannage_os_abi(header_64.e_ident[7]);
	mannage_abi_version(header_64.e_ident[8]);
	select = header_64.e_ident[4];
	mannage_type(header_64.e_type, header_32.e_type, select);
	mannage_machine(header_64.e_machine);
	mannage_version_2(header_64.e_version);
	mannage_entry_point(header_32.e_entry, header_64.e_entry, select);
	mannage_prog_header(header_32.e_phoff, header_64.e_phoff, select);
	mannage_prog_section(header_32.e_shoff, header_64.e_shoff, select);
	mannage_flags(header_32.e_flags, header_64.e_flags, select);
	mannage_header_size(header_32.e_ehsize, header_64.e_ehsize, select);
	mannage_header_proSize(header_32.e_phentsize, header_64.e_phentsize, select);
	manange_progHeader_num(header_32.e_phnum, header_64.e_phnum, select);
	mannage_hdr_secSize(header_32.e_shentsize, header_64.e_shentsize, select);
	mannage_hdrSec_num(header_32.e_shnum, header_64.e_shnum, select);
	mannage_tableIndex(header_32.e_shstrndx, header_64.e_shstrndx, select);
	/* Don't forget to close the file. */
	fclose(fp);
	return (0);
}
