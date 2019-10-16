#include "uart_img.h"

rgb_color art[64];
int ptnPixel;
int ptnLed;

enum err_t {
	NO_ERR,
	ERR_DETECTED,
	ERR_WAIT_FRAME
};

volatile enum err_t err = NO_ERR;

void uimg_init() {
    for(int i = 0; i < 64; i++) {
        art[i].r = 0;
        art[i].g = 0;
        art[i].b = 0;
    }

    ptnPixel = 0;
    ptnLed = 0;
}

void setNextLed(uint8_t value) {
    switch (ptnLed) {
    default:
    /* RED light */
    case 0: {
        art[ptnPixel].r = value;
        ptnLed = 1;
    } break;
    /* GREEN light */
    case 1: {
        art[ptnPixel].g = value;
        ptnLed = 2;
    } break;
    /* BLUE light */
    case 2: {
        art[ptnPixel].b = value;
        ptnLed = 0;

        if(ptnPixel < 64) {
            ptnPixel++;
        } else {
            ptnPixel = 0;
        }
    } break;
    }
}

void showPicture() {
    write_image(art, 1);
}

void resetPtn() {
    ptnLed = 0;
    ptnPixel = 0;
}

void USART1_IRQHandler() {
	uint8_t rcv = 0;

	if(USART1->ISR & USART_ISR_ORE) {
		/* Clear the overrun flag */
		USART1->ICR |= USART_ICR_ORECF;

		err = ERR_DETECTED;
	}

	if(USART1->ISR & USART_ISR_FE) {
		/* Clear the frame error flag */
		USART1->ICR |= USART_ICR_FECF;

		err = ERR_DETECTED;
	}

	if(USART1->ISR & USART_ISR_RXNE) {
		/* Reads the information */
		rcv = USART1->RDR;
	}

	switch(err) {
		default:
		case ERR_DETECTED: {
			led(LED_YELLOW);
			/* Discart the information */
			err = ERR_WAIT_FRAME;
		} break;
		case ERR_WAIT_FRAME: {
			if(rcv == 0xFF) {
				resetPtn();

				err = NO_ERR;
			}
		} break;
		case NO_ERR: {
			led(LED_OFF);

			if(rcv == 0xFF) {
				resetPtn();
			} else {
				setNextLed(rcv);
			}
		} break;
	}
}
