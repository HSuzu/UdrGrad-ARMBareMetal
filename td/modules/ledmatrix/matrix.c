#include "matrix.h"
#include "matrix_macros.h"

/* Led matrix:
 *  SB  -> PC5;
 *  LAT	-> PC4;
 *  RST	-> PC3;
 *  SCK	-> PB1;
 *  SDA	-> PA4;
 *  C0	-> PB2;
 *  C1	-> PA15;
 *  C2	-> PA2;
 *  C3	-> PA7;
 *  C4	-> PA6;
 *  C5	-> PA5;
 *  C6	-> PB0;
 *  C7	-> PA3;
 */

void matrix_configPorts() {
    /* Activate clock on GPIO A, B and C */
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN |RCC_AHB2ENR_GPIOBEN | RCC_AHB2ENR_GPIOCEN;

    /* Set port as outputs */
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE2) | GPIO_MODER_MODE2_0;
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE3) | GPIO_MODER_MODE3_0;
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE4) | GPIO_MODER_MODE4_0;
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE5) | GPIO_MODER_MODE5_0;
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE6) | GPIO_MODER_MODE6_0;
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE7) | GPIO_MODER_MODE7_0;
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE15) | GPIO_MODER_MODE15_0;

    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE0) | GPIO_MODER_MODE0_0;
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE1) | GPIO_MODER_MODE1_0;
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE2) | GPIO_MODER_MODE2_0;

    GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE3) | GPIO_MODER_MODE3_0;
    GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE4) | GPIO_MODER_MODE4_0;
    GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE5) | GPIO_MODER_MODE5_0;

    /* Set port speed as high velocity */
    GPIOA->OSPEEDR = (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED2)  | GPIO_OSPEEDR_OSPEED2_1;
    GPIOA->OSPEEDR = (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED3)  | GPIO_OSPEEDR_OSPEED3_1;
    GPIOA->OSPEEDR = (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED4)  | GPIO_OSPEEDR_OSPEED4_1;
    GPIOA->OSPEEDR = (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED5)  | GPIO_OSPEEDR_OSPEED5_1;
    GPIOA->OSPEEDR = (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED6)  | GPIO_OSPEEDR_OSPEED6_1;
    GPIOA->OSPEEDR = (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED7)  | GPIO_OSPEEDR_OSPEED7_1;
    GPIOA->OSPEEDR = (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED15) | GPIO_OSPEEDR_OSPEED15_1;

    GPIOB->OSPEEDR = (GPIOB->OSPEEDR & ~GPIO_OSPEEDR_OSPEED0) | GPIO_OSPEEDR_OSPEED0_1;
    GPIOB->OSPEEDR = (GPIOB->OSPEEDR & ~GPIO_OSPEEDR_OSPEED1) | GPIO_OSPEEDR_OSPEED1_1;
    GPIOB->OSPEEDR = (GPIOB->OSPEEDR & ~GPIO_OSPEEDR_OSPEED2) | GPIO_OSPEEDR_OSPEED2_1;

    GPIOC->OSPEEDR = (GPIOC->OSPEEDR & ~GPIO_OSPEEDR_OSPEED3) | GPIO_OSPEEDR_OSPEED3_1;
    GPIOC->OSPEEDR = (GPIOC->OSPEEDR & ~GPIO_OSPEEDR_OSPEED4) | GPIO_OSPEEDR_OSPEED4_1;
    GPIOC->OSPEEDR = (GPIOC->OSPEEDR & ~GPIO_OSPEEDR_OSPEED5) | GPIO_OSPEEDR_OSPEED5_1;
}

void matrix_initB0() {
    /* Write 1 to the Bank 0 */
    SB(0);
    SDA(1);
    for(int i = 0; i < B0_SIZE; i++) {
        pulse_SCK();
    }
    pulse_LAT();
}

void matrix_init() {
    matrix_configPorts();

    RST(0); LAT(1); SB(1);
    SCK(0); SDA(0);
    C0(0); C1(0); C2(0); C3(0); C4(0); C5(0); C6(0); C7(0);

    /* 100 ms wait */
    mswait(100);

    RST(1);

    matrix_initB0();
}

void pulse_SCK() {
    SCK(0);
    asm volatile("nop");
    SCK(1);
    asm volatile("nop");
}

void pulse_LAT() {
    LAT(1);
    asm volatile("nop");
    LAT(0);
    asm volatile("nop");
}

void cleanBank(int n) {
    SB(n);
    SDA(0);
    for(int i = 0; i < B1_SIZE; i++) {
        pulse_SCK();
    }
    pulse_LAT();
}

void deactivate_rows() {
    C0(0); C1(0); C2(0); C3(0); C4(0); C5(0); C6(0); C7(0);

    cleanBank(1);
}

void activate_row(int row) {
    switch (row) {
        case 0:
            C0(1); C1(0); C2(0); C3(0); C4(0); C5(0); C6(0); C7(0);
        break;
        case 1:
            C0(0); C1(1); C2(0); C3(0); C4(0); C5(0); C6(0); C7(0);
        break;
        case 2:
            C0(0); C1(0); C2(1); C3(0); C4(0); C5(0); C6(0); C7(0);
        break;
        case 3:
            C0(0); C1(0); C2(0); C3(1); C4(0); C5(0); C6(0); C7(0);
        break;
        case 4:
            C0(0); C1(0); C2(0); C3(0); C4(1); C5(0); C6(0); C7(0);
        break;
        case 5:
            C0(0); C1(0); C2(0); C3(0); C4(0); C5(1); C6(0); C7(0);
        break;
        case 6:
            C0(0); C1(0); C2(0); C3(0); C4(0); C5(0); C6(1); C7(0);
        break;
        case 7:
            C0(0); C1(0); C2(0); C3(0); C4(0); C5(0); C6(0); C7(1);
        break;
    }

    /* Write 0 to the Bank 1 */
    cleanBank(1);
}
