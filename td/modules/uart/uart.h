#ifndef UART_H
#define UART_H

#include <stm32l475xx.h>
#include <stm32l4xx.h>
#include <stdint.h>
#include <stddef.h>

#include <uart_img/uart_img.h>


#define FCK (80000000)
#define UART_OVERSAPLING16

void uart_init(int baudrate);
void uart_putchar(uint8_t);
uint8_t uart_getchar();
void uart_puts(const uint8_t *s);
void uart_gets(uint8_t *s, size_t size);
void uart_putn(const uint8_t *s, size_t n);

void uart_waitTransmission();
void uart_hex(uint32_t n);

#endif // UART_H