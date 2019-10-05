#include <stm32l475xx.h>
#include <stm32l4xx.h>
#include <stdint.h>

#define FCK (80000000)
#define UART_BAUD_RATE (115200)
#define UART_OVERSAPLING16

void uart_init();
void uart_putchar(uint8_t);
uint8_t uart_getchar();
