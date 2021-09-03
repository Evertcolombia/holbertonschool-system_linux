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
void endian_check(Elf64_Ehdr *header, Elf32_Ehdr *header_32);

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
void mannage_entry_point(Elf32_Addr entryP_32, Elf64_Addr entryP, int sel);
void mannage_prog_header(Elf32_Addr phoof32, Elf64_Addr phoof64, int sel);
void  mannage_prog_section(Elf32_Addr section32, Elf64_Addr section64, int sel);
void mannage_flags(Elf32_Word flags32, Elf64_Word flags64, int sel);
void mannage_header_size(Elf32_Half hsize32, Elf64_Half hsize64,int sel);

/* header size helpers.c */
void mannage_header_proSize(Elf32_Half phsize32, Elf64_Half phsize, int sel);
void manange_progHeader_num(Elf32_Half nsize32, Elf64_Half nsize64, int sel);
void mannage_hdr_secSize(Elf32_Half hssize32, Elf64_Half hssize64,int sel);
void mannage_hdrSec_num(Elf32_Half shnum32, Elf64_Half shnum64, int sel);
void mannage_tableIndex(Elf32_Half tindex32, Elf64_Half tindex64, int sel);

void mannage_error(char *msg, int code);

/* helpers.c */
void print_spaces(int spaces);
void struct_iterator(Hdr_t *h_t, int size, unsigned char flag);
void type_iterator(Hdr_t *h_t, int size, unsigned int type);
int machine_iterator(Hdr_t *h_t, int size, unsigned int machine);

#endif /* _ELF_READER_ */
