#include <stdint.h>
#include <clocks/clocks.h>
#include <gpio/leds/led.h>
#include <uart/uart.h>

int main() {
 	clocks_init();
    led_init();
	uart_init();

	while(1) {
		uint8_t c = uart_getchar();
		uart_putchar(c);
	}

	while(1);
	return 0;
}
