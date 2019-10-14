#include "uart_img.h"

rgb_color art[64];
int ptnPixel;
int ptnLed;

void uimg_init() {
    for(int i = 0; i < 64; i++) {
        art[i].r = 0;
        art[i].g = 0;
        art[i].b = 0;
    }

    ptnPixel = 0;
    ptnLed = 0;
}

void setNextLed(uint8_t value) {
    switch (ptnLed) {
    default:
    /* RED light */
    case 0: {
        art[ptnPixel].r = value;
        ptnLed = 1;
    } break;
    /* GREEN light */
    case 1: {
        art[ptnPixel].g = value;
        ptnLed = 2;
    } break;
    /* BLUE light */
    case 2: {
        art[ptnPixel].b = value;
        ptnLed = 0;

        if(ptnPixel < 64) {
            ptnPixel++;
        } else {
            ptnPixel = 0;
        }
    } break;
    }
}

void showPicture() {
    write_image(art, 1);
}

void resetPtn() {
    ptnLed = 0;
    ptnPixel = 0;
}