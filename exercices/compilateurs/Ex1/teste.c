/*
Le value d'un objet qui est marqué comme *COM* est le "alignment constraints" de ce
objet, dans les autres cas, il montre le décalé du object dans la "section" qu'il est.

Pour les archives executables, le value est vraiment le addresse.

 https://docs.oracle.com/cd/E23824_01/html/819-0690/chapter6-79797.html#chapter6-35166
 https://refspecs.linuxbase.org/elf/gabi4+/ch4.symtab.html
 https://www.intezer.com/executable-linkable-format-101-part-2-symbols/
*/
#include <stdint.h>

int32_t x;
//int8_t y;  // 00000001       O *COM*	00000001 y
//int16_t y; // 00000002       O *COM*	00000002 y
//int32_t y; // 00000004       O *COM*	00000004 y
int16_t k;
int32_t y;   // 00000008       O *COM*	00000008 y
int32_t w = 10;

const char mesg[] = "Hello World!";

int main() {
	static uint8_t z;
	uint16_t t;

	k = 10;
	y = 12;
	z = z + 1;
	t = y + z;
	
	return 0;
}
