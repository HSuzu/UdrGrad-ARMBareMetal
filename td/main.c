#include <stdint.h>
#include <clocks/clocks.h>
#include <gpio/leds/led.h>
#include <uart/uart.h>

int main() {
 	clocks_init();
    led_init();
	uart_init();

	uint8_t input[1000];

	while(1) {
		uart_puts((uint8_t *) "Type Anything:");
		uart_gets(input, 1000);
		uart_puts(input);
	}

	while(1);
	return 0;
}
