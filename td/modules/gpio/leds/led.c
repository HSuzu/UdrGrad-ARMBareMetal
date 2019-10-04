#include <gpio/leds/led.h>

void led_init() {
    /* Configuration  of green LED  (PB14) */
    RCC_AHB2ENR = RCC_AHB2ENR | (1 << 1);
//    GPIOB_MODER = (GPIOB_MODER & ~(3 << 28))|(1 << 28);
    GPIOB_MODERbits.MODE14 = 1;

    /* Configuration of red and green LED (PC9)
     * Input = both leds turn off
     */
    RCC_AHB2ENR = RCC_AHB2ENR | (1 << 2);
    GPIOC_MODER = (GPIOC_MODER & ~(3 << 18));
}

void led_g_on() {
    GPIOB_BSRR = (1 << 14);
}
void led_g_off() {
    GPIOB_BSRR = (1 << 30);
}

void led(LedState state) {
    switch(state) {
        default:
        case LED_OFF : {
            led_g_off();
            /* Input turn LEDs green and yellow off */
            GPIOC_MODER = (GPIOC_MODER & ~(3 << 18));
        } break;
        case LED_GREEN : {
            led_g_on();
            /* Input turn LEDs green and yellow off */
            GPIOC_MODER = (GPIOC_MODER & ~(3 << 18));
        } break;
        case LED_YELLOW : {
            led_g_off();
            /* PC9 high turn led yellow and turn off led blue */
            GPIOC_MODER = (GPIOC_MODER & ~(3 << 18))|(1 << 18);
            GPIOC_BSRR = (1 << 9);
        } break;
        case LED_BLUE : {
            led_g_off();
            /* PC9 low turn led yellow off and turn on led blue */
            GPIOC_MODER = (GPIOC_MODER & ~(3 << 18))|(1 << 18);
            GPIOC_BSRR = (1 << 25);
        } break;
    }
}

void ledBlink(LedState color) {
    led(LED_OFF);
    for (int i=0; i<200000; i++) {
        asm volatile("nop");
    }

    led(color);

    for (int i=0; i<200000; i++) {
        asm volatile("nop");
    }
}
