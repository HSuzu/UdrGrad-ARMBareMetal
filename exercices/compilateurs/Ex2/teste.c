/**
Ex2.1
En executant "objdump -x teste" après la compilation "gcc -o teste teste.c",
on peut voir les "sections" comme en dessous, alors, l'ordre de stockage est
text, rodata, data, bss, tas et pile (les deux dernières sont grâce à
l'execution du code).

Sections:
Idx Name          Size      VMA               LMA               File off  Algn
 13 .text         000002f2  0000000000000630  0000000000000630  00000630  2**4
 15 .rodata       00000048  0000000000000930  0000000000000930  00000930  2**2
 22 .data         00000010  0000000000201000  0000000000201000  00001000  2**3
 23 .bss          00000008  0000000000201010  0000000000201010  00001010  2**0
**/

/**
Ex2.2
En executant "./test" on regarde le resultat en dessous, pour la manière où
le logiciel est ècrit, on sait que la pile a les elements dans la ordre
(A,B) --> (C,D), donc, la pile croît vers l'addresse 0.
Le même analyse montre qui le tas croît vers 0xff...

Output:
A  = 0x7ffe9e6ff000
B  = 0x7ffe9e6ff004
C  = 0x7ffe9e6fefe0
D  = 0x7ffe9e6fefe4
V1 = 0x5570daf84260
V2 = 0x5570daf85210
V3 = 0x5570daf865d0
V4 = 0x5570daf87580
**/

#include <stdio.h>
#include <stdlib.h>

void foo() {
	int c = 10;
	int d = 11;

	printf("C  = %p\nD  = %p\n", &c, &d);
}

void bar() {
	int *v3 = (int *)malloc(1000*sizeof(int));
	int *v4 = (int *)malloc(1000*sizeof(int));
	
	printf("V3 = %p\nV4 = %p\n", v3, v4);

	free(v3);
	free(v4);
}

int main () {
	int a = 10;
	int b = 20;

	int *v1 = (int *)malloc(1000*sizeof(int));
	int *v2 = (int *)malloc(1000*sizeof(int));

	printf("A  = %p\nB  = %p\n", &a, &b);
	foo();

	printf("V1 = %p\nV2 = %p\n", v1, v2);

	bar();	

	free(v1);
	free(v2);
	return 0;
}
