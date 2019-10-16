#include <stdint.h>
#include <utils.h>
#include <irq/irq.h>
#include <clocks/clocks.h>
#include <uart/uart.h>
#include <ledmatrix/matrix.h>
#include <uart_img/uart_img.h>
#include <buttons/buttons.h>

int main() {
	irq_init();
 	clocks_init();
	uart_init(38400);
    matrix_init();
	uimg_init();
	button_init();

	while (1) {
		showPicture();
	}


	while(1);
	return 0;
}
