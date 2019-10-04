#include <gpio/leds/led.h>

void led_init() {
    RCC_AHB2ENR = RCC_AHB2ENR | (1 << 1);
    GPIOB_MODER = (GPIOB_MODER & ~(3 << 28))|(1 << 28);
}

void led_g_on() {
    GPIOB_BSRR = (1 << 14);
}
void led_g_off() {
    GPIOB_BSRR = (1 << 30);
}
