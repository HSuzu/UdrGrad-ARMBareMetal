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
        activate_row(0);
        mswait(500);

        activate_row(1);
        mswait(500);

        activate_row(2);
        mswait(500);

        activate_row(3);
        mswait(500);

        activate_row(4);
        mswait(500);

        activate_row(5);
        mswait(500);

        activate_row(6);
        mswait(500);

        activate_row(7);
        mswait(500);

        deactivate_rows();
        mswait(500);
    }


	while(1);
	return 0;
}
