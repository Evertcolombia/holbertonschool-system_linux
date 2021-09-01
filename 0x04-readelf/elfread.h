#ifndef _ELF_READER_
#define _ELF_READER_

#include <stdio.h>
#include <elf.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct header_types
{
	int type;
	char *msg;
} Hdr_t;


Elf64_Ehdr read_header(FILE **fp, char *name, Elf32_Ehdr *header_32);

void mannage_magic(unsigned char e_ident[EI_NIDENT]);
void mannage_class(unsigned char class);
void mannage_version(unsigned char version);
void mannage_data(unsigned char data);
void mannage_os_abi(unsigned char os_flag);

void mannage_error(char *msg, int code);
void print_spaces(int spaces);
void struct_iterator(Hdr_t *h_t, int size, unsigned char flag);
#endif /* _ELF_READER_ */
