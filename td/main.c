#include <stdint.h>
#include <clocks/clocks.h>
#include <gpio/leds/led.h>
#include <uart/uart.h>

#define N 1000

uint32_t sum = 0;

int main() {
 	clocks_init();
    led_init();
	uart_init();

	uint8_t input = 0;

	while(1) {
		int i = 0;
		while(i++ < N) {
			input = uart_getchar();
			sum += input;
		}
		uart_hex(sum);
		sum = 0;
	}

	while(1);
	return 0;
}
