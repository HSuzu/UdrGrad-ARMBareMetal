#include <stdint.h>

/* See p.249 @ Reference Manual */
#define RCC_BASE_ADDRESS (0x40021000)

#define RCC_AHB1ENR_OFFSET  (0x48)
#define RCC_AHB2ENR_OFFSET  (0x4C)
#define RCC_AHB3ENR_OFFSET  (0x50)
#define RCC_APB1ENR1_OFFSET (0x58)
#define RCC_APB1ENR2_OFFSET (0x5C)
#define RCC_APB2ENR_OFFSET  (0x60)

#define RCC_AHB2ENR (*((volatile uint32_t *) (RCC_BASE_ADDRESS + RCC_AHB2ENR_OFFSET)))
