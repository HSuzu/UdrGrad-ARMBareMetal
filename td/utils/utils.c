#include "utils.h"

void mswait(int ms) {
    for(int i = 0; i < ms*_FCK_/5000; i++) {
        asm volatile("nop");
    }
}
