#include <stdint.h>
#include <utils.h>
#include <irq/irq.h>
#include <clocks/clocks.h>
#include <gpio/leds/led.h>
#include <uart/uart.h>
#include <ledmatrix/matrix.h>
#include <buttons/buttons.h>

extern const uint8_t _binary_image_raw_start;
extern const uint8_t _binary_image_raw_end;
extern const uint8_t _binary_image_raw_size;

int main() {
	irq_init();
 	clocks_init();
    led_init();
	uart_init();
    matrix_init();
	button_init();

	uint8_t size = _binary_image_raw_size;
	const uint8_t *img = & _binary_image_raw_start;
	rgb_color art[64];

	for(int i = 0, j = 0; i < 64 && size >= 3; i++) {
		art[i].r = img[j++];
		art[i].g = img[j++];
		art[i].b = img[j++];
	}

    while(1) {
		write_image(art, 1);
    }


	while(1);
	return 0;
}
