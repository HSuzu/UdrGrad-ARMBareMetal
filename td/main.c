#include <stdint.h>
#include <gpio/leds/led.h>

int main() {
    led_init();
    while(1) {
        led_g_on();
        for (int i=0; i<200000; i++) {
            asm volatile("nop");
        }

        led_g_off();

        for (int i=0; i<20000; i++) {
            asm volatile("nop");
        }
    }

	while(1);
	return 0;
}
