#include <stdint.h>
#include <utils.h>
#include <irq/irq.h>
#include <clocks/clocks.h>
#include <uart/uart.h>
#include <ledmatrix/matrix.h>
#include <uart_img/uart_img.h>
#include <buttons/buttons.h>

extern const uint8_t _binary_image_raw_start;
extern const uint8_t _binary_image_raw_end;
extern const uint8_t _binary_image_raw_size;

int main() {
	irq_init();
 	clocks_init();
	uart_init(38400);
    matrix_init();
	uimg_init();

	uint8_t size = _binary_image_raw_size;
	const uint8_t *img = & _binary_image_raw_start;

	for(int i = 0, j = 0; i < 64 && size >= 3; i++) {
		setNextLed(img[j++]);
		setNextLed(img[j++]);
		setNextLed(img[j++]);
	}

	while (1) {
		showPicture();
	}


	while(1);
	return 0;
}
