#include "buttons.h"

void button_init(void) {
    /* Activate clock on GPIO C */
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;

    /* Set PC13 as input */
    GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE13);

    /* Configure EXTI */
    EXTI->IMR1 |= EXTI_IMR1_IM13;
    /* Enable Rising edge Interruption */
    EXTI->RTSR1 |= EXTI_RTSR1_RT13;
    /* Disable Falling edge Interruptio */
    EXTI->FTSR1 &= ~EXTI_FTSR1_FT13;

    /* Enable interruption on the EXTI line [15:10] */
    NVIC_EnableIRQ(40);

    SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI13_PC;
}

void EXTI15_10_IRQHandler() {
    EXTI->PR1 |= EXTI_PR1_PIF13;

    led(LED_YELLOW);
	mswait(1000);
	led(LED_OFF);
}
