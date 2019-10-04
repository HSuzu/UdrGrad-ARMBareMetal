#include <stdint.h>
#include <gpio/leds/led.h>

int main() {
    led_init();
    while(1) {
        ledBlink(LED_GREEN);
        ledBlink(LED_YELLOW);
        ledBlink(LED_BLUE);
    }

	while(1);
	return 0;
}
