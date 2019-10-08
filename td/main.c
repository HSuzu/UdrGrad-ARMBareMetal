#include <stdint.h>
#include <utils.h>
#include <clocks/clocks.h>
#include <gpio/leds/led.h>
#include <uart/uart.h>
#include <ledmatrix/matrix.h>

int main() {
 	clocks_init();
    led_init();
	uart_init();
    matrix_init();

    while(1) {
		test_pixels();
    }


	while(1);
	return 0;
}
