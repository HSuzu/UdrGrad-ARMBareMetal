#ifndef UART_IMG_H
#define UART_IMG_H

#include <stdint.h>
#include <uart/uart.h>
#include <gpio/leds/led.h>
#include <ledmatrix/matrix.h>

void uimg_init();
void setDefaultPicture(rgb_color *pic);
void setNextLed(uint8_t value);
void showPicture();

void resetPtn();

#endif // UART_IMG_H
