#include "utils.h"

void mswait(int ms) {
    for(int i = 0; i < ms*_FCK_/1000; i++) {
        asm volatile("nop");
    }
}
