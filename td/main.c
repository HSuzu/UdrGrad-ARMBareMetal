#include <stdint.h>
#include <utils.h>
#include <irq/irq.h>
#include <clocks/clocks.h>
#include <gpio/leds/led.h>
#include <uart/uart.h>
#include <ledmatrix/matrix.h>
#include <buttons/buttons.h>

int main() {
	irq_init();
 	clocks_init();
    led_init();
	uart_init(38400);
    matrix_init();
	button_init();

	while(1);
	return 0;
}
