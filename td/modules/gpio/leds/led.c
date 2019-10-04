#include <gpio/leds/led.h>

void led_init() {
    /* Configuration  of green LED  (PB14) */
    // RCC_AHB2ENR = RCC_AHB2ENR | (1 << 1);
    // GPIOB_MODER = (GPIOB_MODER & ~(3 << 28))|(1 << 28);
	SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN);
	GPIOB->MODER = (GPIOB->MODER & ~(GPIO_MODER_MODE14_Msk)) | GPIO_MODER_MODE14_0;

    /* Configuration of red and green LED (PC9)
     * Input = both leds turn off
     */
    // RCC_AHB2ENR = RCC_AHB2ENR | (1 << 2);
    // GPIOC_MODER = (GPIOC_MODER & ~(3 << 18));
	SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOCEN);
	GPIOC->MODER = (GPIOC->MODER & ~(GPIO_MODER_MODE9_Msk));
}

void led_g_on() {
    GPIOB->BSRR = GPIO_BSRR_BS14;
}
void led_g_off() {
	GPIOB->BSRR = GPIO_BSRR_BR14;
}

void led(LedState state) {
    switch(state) {
        default:
        case LED_OFF : {
            led_g_off();
            /* Input turn LEDs green and yellow off */
            // GPIOC_MODER = (GPIOC_MODER & ~(3 << 18));
			GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE9_Msk);
        } break;
        case LED_GREEN : {
            led_g_on();
            /* Input turn LEDs green and yellow off */
            // GPIOC_MODER = (GPIOC_MODER & ~(3 << 18));
			GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE9_Msk);
        } break;
        case LED_YELLOW : {
            led_g_off();
            /* PC9 high turn led yellow and turn off led blue */
            // GPIOC_MODER = (GPIOC_MODER & ~(3 << 18))|(1 << 18);
            // GPIOC_BSRR = (1 << 9);
			GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE9_Msk) | GPIO_MODER_MODE9_0;
			GPIOC->BSRR = GPIO_BSRR_BS_9;
        } break;
        case LED_BLUE : {
            led_g_off();
            /* PC9 low turn led yellow off and turn on led blue */
            // GPIOC_MODER = (GPIOC_MODER & ~(3 << 18))|(1 << 18);
            // GPIOC_BSRR = (1 << 25);
			GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE9_Msk) | GPIO_MODER_MODE9_0;
			GPIOC->BSRR = GPIO_BSRR_BR_9;
        } break;
    }
}

void ledBlink(LedState color) {
    led(LED_OFF);
    for (int i=0; i<10000000; i++) {
        asm volatile("nop");
    }

    led(color);

    for (int i=0; i<10000000; i++) {
        asm volatile("nop");
    }
}
