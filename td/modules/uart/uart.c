#include "uart.h"
#include <gpio/leds/led.h>


/** STLINK UART1 TX: PB06
 ** STLINK UART1 RX: PB07
 **/


void uart_init() {
	/* Disable USART */
	// USART1->CR1 &= ~(USART_CR1_UE);

	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;

	/* Activate USART CLOCK and set it for PCLK (value = 0) */
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	RCC->CCIPR &= ~RCC_CCIPR_USART1SEL;

	/* IMPORTANT: It must have 2 cycles before changing any register of USART1 */

	/* Configure UART ports: AF (Alternative Function) to AF7 */
	GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE6_Msk) | GPIO_MODER_MODE6_1;
	GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE7_Msk) | GPIO_MODER_MODE7_1;

	GPIOB->AFR[0] = (GPIOB->AFR[0] & ~GPIO_AFRL_AFSEL6) | (0x7 << GPIO_AFRL_AFSEL6_Pos);
	GPIOB->AFR[0] = (GPIOB->AFR[0] & ~GPIO_AFRL_AFSEL7) | (0x7 << GPIO_AFRL_AFSEL7_Pos);

	/* Reset USART1 */
	// RCC->APB2RSTR = RCC_APB2RSTR_USART1RST;

	/* Configure baud rate to 115200 (oversample = 16) */
	#ifdef UART_OVERSAPLING16
		uint32_t USARTDIV = FCK/UART_BAUD_RATE;
		uint32_t brr = USARTDIV;
	#else
		uint32_t USARTDIV = 2*FCK/UART_BAUD_RATE;
		uint32_t brr = (USARTDIV & 0x7) >> 1;
		brr = brr | (USARTDIV & 0xFFF0);
	#endif

	/* BRR must be bigger or equal then 16 */
	if(brr < 16)
		brr = 16;

	/* Configure Baud Rate */
	USART1->BRR = brr;

	/* Configure UART to handle words of 8 bits (M = 0),
	 * 16 oversample (OVER8 = 0), no parity (PCE = 0)
	 * and 1 stop bit (STOP = 0) */
	USART1->CR1 = USART1->CR1 & ~(USART_CR1_M1 | USART_CR1_M0);
	USART1->CR1 = USART1->CR1 & ~USART_CR1_OVER8;
	USART1->CR1 = USART1->CR1 & ~USART_CR1_PCE;
	USART1->CR2 = USART1->CR2 & ~USART_CR2_STOP;

	/* Enable transmitter and receiver */
	USART1->CR1 = USART1->CR1 | USART_CR1_UE;
	USART1->CR1 = USART1->CR1 | USART_CR1_TE | USART_CR1_RE;
}

void uart_putchar(uint8_t c) {
	while(!(USART1->ISR & USART_ISR_TXE));
	USART1->TDR = c;
}

uint8_t uart_getchar() {
	// while(USART1->ISR & USART_ISR_FE);
	// while(USART1->ISR & USART_ISR_ORE);
	while(!(USART1->ISR & USART_ISR_RXNE));
	return USART1->RDR;
}

void uart_puts(const uint8_t *s) {
	int i = 0;
	while(s[i] != '\0') {
		uart_putchar(s[i]);
		i++;
	}

	uart_putchar('\n');
	/* Carriage return */
	uart_putchar(0xd);
}

void uart_gets(uint8_t *s, size_t size) {
	uint8_t c = uart_getchar();
	size_t i = 0;

	while (c != '\n' && c != 0xd && i < size-1) {
		s[i] = c;

		i++;
		c = uart_getchar();
	}

	s[i] = '\0';
}


void uart_putn(const uint8_t *s, size_t n) {
	size_t i = 0;
	while(i < n && s[i] != '\0') {
		uart_putchar(s[i]);
	}

	uart_putchar('\n');
}

void uart_hex(uint32_t n) {
	uart_putchar('0');
	uart_putchar('x');
	for(int i = 7; i >= 0 ; i--) {
		uint8_t p = ((uint32_t)(n & (uint32_t)(0xF << (i*4))) >> (i*4));

		if(p <= 9) {
			uart_putchar(p + '0');
		} else {
			uart_putchar(p - 10 + 'A');
		}
	}

	uart_putchar('\n');
	/* Carriage return */
	uart_putchar(0xd);
}
