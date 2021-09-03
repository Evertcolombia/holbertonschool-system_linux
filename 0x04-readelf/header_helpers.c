#include "elfread.h"

/**
 * mannage_abi_version - Identifies the object file version
 * @abi_version: version argument
 *
 * Return: None
 */
void mannage_abi_version(unsigned char abi_version)
{
	printf("  ABI Version:");
	print_spaces(23);
	printf("%d\n", abi_version);
}

/**
 * mannage_type - Identifies the object file type
 * @e_type64: type in 64
 * @e_type32: type in 32
 * @c_val: value
 *
 * Return: None
 */
void mannage_type(Elf64_Half e_type64, Elf32_Half e_type32, int c_val)
{
	Hdr_t h_types[] = {
		{ET_NONE, "NONE (None)"},
		{ET_REL, "REL (Relocatable file)"},
		{ET_EXEC, "EXEC (Executable file)"},
		{ET_DYN, "DYN (Shared object file)"},
		{ET_CORE, "CORE (Core	 file)"},
	};

	printf("  Type:");
	print_spaces(30);
	
	if (c_val == 2)
		type_iterator(h_types, 5, e_type64);
	else
		type_iterator(h_types, 5, e_type32);
}	


/**
 * mannage_machine - Specifies the required architecture for an individual file
 * @flag: flag to search
 *
 * Return: None
 */
void mannage_machine(Elf64_Half flag)
{
	Hdr_t h_types[] = {
		{EM_NONE, "None"},
		{EM_AARCH64, "AArch64"},
		{EM_M32, "WE32100"},
		{EM_SPARC, "Sparc"},
		{EM_386, "Intel 80386"},
		{EM_68K, "MC68000"},
		{EM_88K, "MC88000"},
		{EM_860, "Intel 80860"},
		{EM_MIPS, "MIPS R3000"},
		{EM_S370, "IBM System/370"},
		{EM_MIPS_RS3_LE, "MIPS R4000 big-endian"},
		{EM_PARISC, "HPPA"},
		{EM_SPARC32PLUS, "Sparc v8+"},
		{EM_960, "Intel 90860"},
		{EM_PPC, "PowerPC"},
		{EM_PPC64, "PowerPC64"},
		{EM_FR20, "Fujitsu FR20"},
		{EM_RH32, "TRW RH32"},
		{EM_ARM, "ARM"},
		{EM_SH, "Renesas / SuperH SH"},
		{EM_SPARCV9, "Sparc v9"},
		{EM_TRICORE, "Siemens Tricore"},
		{EM_ARC, "ARC"},
		{EM_H8_300, "Renesas H8/300"},
		{EM_H8_300H, "Renesas H8/300H"},
		{EM_H8S, "Renesas H8S"},
		{EM_H8_500, "Renesas H8/500"},
		{EM_IA_64, "Intel IA-64"},
		{EM_MIPS_X, "Stanford MIPS-X"},
		{EM_COLDFIRE, "Motorola Coldfire"},
		{EM_ALPHA, "Alpha"},
		{EM_D10V, "d10v"},
		{EM_D30V, "d30v"},
		{EM_M32R, "Renesas M32R (formerly Mitsubishi M32r)"},
		{EM_V800, "Renesas V850 (using RH850 ABI)"},
		{EM_V850, "Renesas V850"}
	};
	
	printf("  Machine:");
	print_spaces(27);

	if (machine_iterator(h_types, 35, flag) != 0)
		mannage_machine_2(flag);
}

/**
 * mannage_machine_2 - gets the target machine type string
 * @flag: number that represents the machine
 *
 * Return: the string or NULL
 */
void mannage_machine_2(Elf64_Half flag)
{
	Hdr_t h_types[] = {
		{EM_MN10300, "mn10300"},
		{EM_MN10200, "mn10200"},
		{EM_FR30, "Fujitsu FR30"},
		{EM_PJ, "picoJava"},
		{EM_MMA, "Fujitsu Multimedia Accelerator"},
		{EM_PCP, "Siemens PCP"},
		{EM_NCPU, "Sony nCPU embedded RISC processor"},
		{EM_NDR1, "Denso NDR1 microprocesspr"},
		{EM_STARCORE, "Motorola Star*Core processor"},
		{EM_ME16, "Toyota ME16 processor"},
		{EM_ST100, "STMicroelectronics ST100 processor"},
		{EM_TINYJ, "Advanced Logic Corp. TinyJ embedded processor"},
		{EM_PDSP, "Sony DSP processor"},
		{EM_FX66, "Siemens FX66 microcontroller"},
		{EM_ST9PLUS, "STMicroelectronics ST9+ 8/16 bit microcontroller"},
		{EM_ST7, "STMicroelectronics ST7 8-bit microcontroller"},
		{EM_68HC16, "Motorola MC68HC16 Microcontroller"},
		{EM_68HC12, "Motorola MC68HC12 Microcontroller"},
		{EM_68HC11, "Motorola MC68HC11 Microcontroller"},
		{EM_68HC08, "Motorola MC68HC08 Microcontroller"},
		{EM_68HC05, "Motorola MC68HC05 Microcontroller"},
		{EM_SVX, "Silicon Graphics SVx"},
		{EM_ST19, "STMicroelectronics ST19 8-bit microcontroller"},
		{EM_VAX, "Digital VAX"},
		{EM_AVR, "Atmel AVR 8-bit microcontroller"},
		{EM_CRIS, "Axis Communications 32-bit embedded processor"},
		{EM_JAVELIN, "Infineon Technologies 32-bit embedded cpu"},
		{EM_FIREPATH, "Element 14 64-bit DSP processor"},
		{EM_ZSP, "LSI Logic's 16-bit DSP processor"},
		{EM_MMIX, "Donald Knuth's educational 64-bit processor"},
		{EM_HUANY, "Harvard Universitys's machine-independent object format"},
		{EM_PRISM, "Vitesse Prism"},
		{EM_X86_64, "Advanced Micro Devices X86-64"},
		{EM_S390, "IBM S/390"},
		{EM_XTENSA, "Tensilica Xtensa Processor"},
	};
	machine_iterator(h_types, 34, flag);
}

/**
 * mannage_version_2 - mannage version 2
 * @version: version to print
 *
 * Return: None
 */
void mannage_version_2(Elf64_Word version)
{
	printf("  Version:");
	print_spaces(27);
	printf("0x%x\n", version);
}
