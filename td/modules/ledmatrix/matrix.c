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

void matrix_init() {
    matrix_configPorts();

    RST(0); LAT(1); SB(1);
    SCK(0); SDA(0);
    C0(0); C1(0); C2(0); C3(0); C4(0); C5(0); C6(0); C7(0);

    /* 100 ms wait */
    mswait(100);

    RST(1);

    init_bank0();
}

void init_bank0() {
    /* Write 1 to the Bank 0 */
    SB(0);
    SDA(1);
    for(int i = 0; i < B0_SIZE; i++) {
        pulse_SCK();
    }
    pulse_LAT();
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

void deactivate_rows() {
    C0(0); C1(0); C2(0); C3(0); C4(0); C5(0); C6(0); C7(0);

	/* Write 0 to Bank 1 */
	SB(1);
    SDA(0);
    for(int i = 0; i < B1_SIZE; i++) {
        pulse_SCK();
    }
    pulse_LAT();
}

void activate_row(int row) {
    switch (row) {
        case 0:
            ROW0(1);
        break;
        case 1:
            ROW1(1);
        break;
        case 2:
            ROW2(1);
        break;
        case 3:
            ROW3(1);
        break;
        case 4:
            ROW4(1);
        break;
        case 5:
            ROW5(1);
        break;
        case 6:
            ROW6(1);
        break;
        case 7:
            ROW7(1);
        break;
    }
}

void send_byte(uint8_t val, int bank) {
	SB(bank);
	for(int i = 7; i >= 0; i--) {
		SDA((val & (1 << i)) >> i);
        pulse_SCK();
    }
}

void mat_set_row(int row, const rgb_color *val) {
	for(int i = 7; i >=0; i--) {
		send_byte(val[i].b, 1);
		send_byte(val[i].g, 1);
		send_byte(val[i].r, 1);
	}
	pulse_LAT();

	activate_row(row);
}

void test_pixels() {
	rgb_color col[8];

	for(int j = 0; j < 8; j++) {
		for(int i = 0; i < 8; i++) {
			col[i].b = (0xFF >> (7-i))*(8-j)/8;
			col[i].g = (0xFF >> (7-j))*(1-(8-j)/8);
			col[i].r = 0;
		}
		mat_set_row(j, col);
		mswait(200);
	}

	for(int j = 0; j < 8; j++) {
		for(int i = 0; i < 8; i++) {
			col[i].b = 0;
			col[i].g = (0xFF >> (7-i))*(8-j)/8;
			col[i].r = (0xFF >> (7-j))*(1-(8-j)/8);
		}
		mat_set_row(j, col);
		mswait(200);
	}

	for(int j = 0; j < 8; j++) {
		for(int i = 0; i < 8; i++) {
			col[i].b = (0xFF >> (7-j))*(1-(8-j)/8);
			col[i].g = 0;
			col[i].r = (0xFF >> (7-i))*(8-j)/8;
		}
		mat_set_row(j, col);
		mswait(200);
	}
}

void write_image(rgb_color *img, int ms_pxwait) {
	for(int j = 0; j < 8; j++) {
		mat_set_row(j, &(img[j*8]));
		mswait(ms_pxwait);
	}
}
