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
void mannage_class(unsigned char class_value)
{
	Hdr_t h_types[] = {
		{ELFCLASS32, "ELF32"},
	      	{ELFCLASS64, "ELF64"},
		{ELFCLASSNONE, "Invalid class"}
	};

	printf("  Class:");
	print_spaces(29);
	struct_iterator(h_types, 3, class_value);
}

/**
 * mannage_data - gets data info from elf header
 * @data: flag to ckeck
 *
 * Return: None
 */
void mannage_data(unsigned char data)
{
	Hdr_t h_types[] = {
		{ELFDATA2LSB, "2's complement, little endian"},
		{ELFDATA2MSB, "2's complement, big endian"},
		{ELFDATANONE, "Invalid data encoding"},
	};
	printf("  Data:");
	print_spaces(30);
	struct_iterator(h_types, 3, data);
}

/**
 * mannage_version -  gets ELF header version number
 * @version: flag to ckeck
 *
 * Return: None
 */
void mannage_version(unsigned char version)
{
	Hdr_t h_types[] = {
		{EV_CURRENT, "1 (current)"},
		{EV_NONE, "0 (invalid)"}
	};

	printf("  Version:");
	print_spaces(27);
	struct_iterator(h_types, 2, version);
}


/**
 * mannage_os_abi -  Gets ELF header operating system
 * @os_flag: flag to check
 *
 * Return: None
 */
void mannage_os_abi(unsigned char os_flag)
{
	Hdr_t h_types[] = {
		{ELFOSABI_HPUX, "UNIX - HP-UX"},
		{ELFOSABI_NETBSD, "UNIX - NetBSD"},
		{ELFOSABI_SOLARIS, "UNIX - Solaris"},
		{ELFOSABI_GNU, "UNIX - GNU"},
		{ELFOSABI_AIX, "UNIX - AIX"},
		{ELFOSABI_FREEBSD, "UNIX - FreeBSD"},
		{ELFOSABI_TRU64, "UNIX - TRU64"},
		{ELFOSABI_MODESTO, "Novell - Modesto"},
		{ELFOSABI_OPENBSD, "UNIX - OpenBSD"},
		{ELFOSABI_SYSV, "UNIX - System V"}
	};

	printf("  OS/ABI:");
	print_spaces(28);
	struct_iterator(h_types, 10, os_flag);	
}
