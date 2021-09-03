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

/* eident_helpers.c */
void mannage_magic(unsigned char e_ident[EI_NIDENT]);
void mannage_class(unsigned char class_value);
void mannage_version(unsigned char version);
void mannage_data(unsigned char data);
void mannage_os_abi(unsigned char os_flag);

/* header_helpers.c */
void mannage_abi_version(unsigned char abi_version);
void mannage_type(Elf64_Half e_type64, Elf32_Half e_type32, unsigned char c_val);
void mannage_machine(Elf64_Half flag);
void mannage_machine_2(Elf64_Half flag);
void mannage_version_2(Elf64_Word version);

/* header_helpers_2.c */
void mannage_entry_point(Elf64_Addr entryP);

void mannage_error(char *msg, int code);

/* helpers.c */
void print_spaces(int spaces);
void struct_iterator(Hdr_t *h_t, int size, unsigned char flag);
void type_iterator(Hdr_t *h_t, int size, unsigned int type);
int machine_iterator(Hdr_t *h_t, int size, unsigned int machine);

#endif /* _ELF_READER_ */
