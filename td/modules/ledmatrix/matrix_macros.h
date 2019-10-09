#include <stm32l475xx.h>
#include <stm32l4xx.h>

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

#define B0_SIZE (144)
#define B1_SIZE (192)


#define RST(x) do { ((x)? (GPIOC->BSRR = GPIO_BSRR_BS_3) : (GPIOC->BSRR = GPIO_BSRR_BR_3));   } while (0);
#define SB(x)  do { ((x)? (GPIOC->BSRR = GPIO_BSRR_BS_5) : (GPIOC->BSRR = GPIO_BSRR_BR_5));   } while (0);
#define LAT(x) do { ((x)? (GPIOC->BSRR = GPIO_BSRR_BS_4) : (GPIOC->BSRR = GPIO_BSRR_BR_4));   } while (0);
#define SCK(x) do { ((x)? (GPIOB->BSRR = GPIO_BSRR_BS_1) : (GPIOB->BSRR = GPIO_BSRR_BR_1));   } while (0);
#define SDA(x) do { ((x)? (GPIOA->BSRR = GPIO_BSRR_BS_4) : (GPIOA->BSRR = GPIO_BSRR_BR_4));   } while (0);
#define C0(x)  do { ((x)? (GPIOB->BSRR = GPIO_BSRR_BS_2) : (GPIOB->BSRR = GPIO_BSRR_BR_2));   } while (0);
#define C1(x)  do { ((x)? (GPIOA->BSRR = GPIO_BSRR_BS_15) : (GPIOA->BSRR = GPIO_BSRR_BR_15)); } while (0);
#define C2(x)  do { ((x)? (GPIOA->BSRR = GPIO_BSRR_BS_2) : (GPIOA->BSRR = GPIO_BSRR_BR_2));   } while (0);
#define C3(x)  do { ((x)? (GPIOA->BSRR = GPIO_BSRR_BS_7) : (GPIOA->BSRR = GPIO_BSRR_BR_7));   } while (0);
#define C4(x)  do { ((x)? (GPIOA->BSRR = GPIO_BSRR_BS_6) : (GPIOA->BSRR = GPIO_BSRR_BR_6));   } while (0);
#define C5(x)  do { ((x)? (GPIOA->BSRR = GPIO_BSRR_BS_5) : (GPIOA->BSRR = GPIO_BSRR_BR_5));   } while (0);
#define C6(x)  do { ((x)? (GPIOB->BSRR = GPIO_BSRR_BS_0) : (GPIOB->BSRR = GPIO_BSRR_BR_0));   } while (0);
#define C7(x)  do { ((x)? (GPIOA->BSRR = GPIO_BSRR_BS_3) : (GPIOA->BSRR = GPIO_BSRR_BR_3));   } while (0);
