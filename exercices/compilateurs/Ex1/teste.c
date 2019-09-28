/*
compilation: gcc -c teste.c -o teste.o

[Outputs]
+ arm-none-eabi-objdump -t

teste.o:     file format elf32-littlearm

SYMBOL TABLE:
00000000 l    df *ABS*	00000000 teste.c
00000000 l    d  .text	00000000 .text
00000000 l    d  .data	00000000 .data
00000000 l    d  .bss	00000000 .bss
00000000 l    d  .rodata	00000000 .rodata
00000000 l       .bss	00000001 z.4167
00000000 l    d  .comment	00000000 .comment
00000000 l    d  .ARM.attributes	00000000 .ARM.attributes
00000004       O *COM*	00000004 x
00000002       O *COM*	00000002 k
00000004       O *COM*	00000004 y
00000003       O *COM*	00000004 g
00000005       O *COM*	00000004 g2
00000000 g     O .data	00000004 w
00000000 g     O .rodata	0000000d mesg
00000000 g     F .text	00000084 main

+ arm-none-eabi-readelf -s teste.o
Symbol table '.symtab' contains 22 entries:
   Num:    Value  Size Type    Bind   Vis      Ndx Name
     0: 00000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 00000000     0 FILE    LOCAL  DEFAULT  ABS teste.c
     2: 00000000     0 SECTION LOCAL  DEFAULT    1 
     3: 00000000     0 SECTION LOCAL  DEFAULT    3 
     4: 00000000     0 SECTION LOCAL  DEFAULT    4 
     5: 00000000     0 NOTYPE  LOCAL  DEFAULT    3 $d
     6: 00000000     0 SECTION LOCAL  DEFAULT    5 
     7: 00000000     0 NOTYPE  LOCAL  DEFAULT    5 $d
     8: 00000000     0 NOTYPE  LOCAL  DEFAULT    1 $a
     9: 00000078     0 NOTYPE  LOCAL  DEFAULT    1 $d
    10: 00000000     1 NOTYPE  LOCAL  DEFAULT    4 z.4167
    11: 00000000     0 NOTYPE  LOCAL  DEFAULT    4 $d
    12: 00000000     0 SECTION LOCAL  DEFAULT    6 
    13: 00000000     0 SECTION LOCAL  DEFAULT    7 
    14: 00000004     4 OBJECT  GLOBAL DEFAULT  COM x
    15: 00000002     2 OBJECT  GLOBAL DEFAULT  COM k
    16: 00000004     4 OBJECT  GLOBAL DEFAULT  COM y
    17: 00000004     3 OBJECT  GLOBAL DEFAULT  COM g
    18: 00000004     5 OBJECT  GLOBAL DEFAULT  COM g2
    19: 00000000     4 OBJECT  GLOBAL DEFAULT    3 w
    20: 00000000    13 OBJECT  GLOBAL DEFAULT    5 mesg
    21: 00000000   132 FUNC    GLOBAL DEFAULT    1 main

Dans le manual page du objdump, on a: "The first number is the symbol’s value (sometimes refered to as its address). [...] After the section name comes another field, a number, which for common symbols is the alignment and for other symbol is the size. Finally the symbol’s name is displayed."

Comme on peut regarder, objdump et readelf nous donnent résultats diferent pour commom symbols, par exemple, en regardant les lignes suivantes, c'est clair la différence:

[objdump]
00000000 l       .bss	00000001 z.4167
00000003       O *COM*	00000004 g
00000005       O *COM*	00000004 g2

[readelf]
   Num:    Value  Size Type    Bind   Vis      Ndx Name
    10: 00000000     1 NOTYPE  LOCAL  DEFAULT    4 z.4167
    17: 00000004     3 OBJECT  GLOBAL DEFAULT  COM g
    18: 00000004     5 OBJECT  GLOBAL DEFAULT  COM g2

La première colonne d'objdump pour les simboles autres que common sont le valeur du simbole, par contre, pour les "common symbols" on a le value égale
à la taille et vice-versa, la quatrième colonne d'objdump est la taille du simbole, sauf pour les "common symbols", où on a le valeur.

On trouve dans les manuels d'ELF que le value d'un objet qui est marqué comme *COM* est le "alignment constraints" de ce objet, dans les autres cas, il montre le décalé du object dans la "section" qu'il est. Pour les archives executables, le value est vraiment le addresse.

Donc, la première colonne du resutat de l'execution d'objdump n'est pas le adresse d'objet, mais le valeur pour les objet autres que *COM* et la taille pour eux.

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
int8_t g[3]; // 00000003       O *COM*	00000004 g
int8_t g2[5]; // 00000005       O *COM*	00000004 g2
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
