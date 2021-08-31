#ifndef _ELF_READER_
#define _ELF_READER_

#include <stdio.h>
#include <elf.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

Elf64_Ehdr read_header(FILE **fp, char *name, Elf32_Ehdr *header_32);

void mannage_magic(unsigned char e_ident[EI_NIDENT]);

void mannage_error(char *msg, int code);
#endif /* _ELF_READER_ */
