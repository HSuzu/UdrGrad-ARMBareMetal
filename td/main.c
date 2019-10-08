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
        mswait(100);

        activate_row(1);
        mswait(100);

        activate_row(2);
        mswait(100);

        activate_row(3);
        mswait(100);

        activate_row(4);
        mswait(100);

        activate_row(5);
        mswait(100);

        activate_row(6);
        mswait(100);

        activate_row(7);
        mswait(100);

        deactivate_rows();
        mswait(100);
    }


	while(1);
	return 0;
}
