#include "elfread.h"

/**
 * read_header - reads the header from an elf file
 * @fp: file to read
 * @name: name of the file
 * @header_32: pointer to a Elf32Ehdr object
 *
 * Return: Elf64_Ehdr object on success
 */
Elf64_Ehdr read_header(FILE **fp, char *name, Elf32_Ehdr *header_32)
{
	struct stat sb;
	Elf64_Ehdr header_64;

	if ((stat(name, &sb) == 0) && ((sb.st_mode & S_IFMT) == S_IFDIR))
		mannage_error("readelf: Error: '%s' is not an ordinary file\n", 1);
	else if (stat(name, &sb) == 0 && access(name, R_OK) != 0)
		mannage_error("readelf: Error: Input file '%s' is not readable\n", 1);
	 else if (stat(name, &sb) != 0)
		 mannage_error("readelf: Error: '%s': No such file\n", 1);

	*fp = fopen(name, "rb");
	if (fp == NULL)
		mannage_error("Unable to open '%s': %s\n", 1);

	fread(&header_64, sizeof(header_64), 1, *fp);
	rewind(*fp);
	fread(header_32, sizeof(header_32), 1, *fp);

	if (memcmp(header_64.e_ident, ELFMAG, SELFMAG) == 0)
		return (header_64);

	fprintf(stderr, "readelf: Error: Not an ELF file - it has the wrong magic bytes at the start\n");
	exit(1);
}
