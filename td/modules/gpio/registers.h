#include <stdint.h>
/* See Table 2 p.82 @ Reference manual */
#define GPIOA_BASE_ADDRESS (0x48000000)
#define GPIOB_BASE_ADDRESS (0x48000400)
#define GPIOC_BASE_ADDRESS (0x48000800)
#define GPIOD_BASE_ADDRESS (0x48000C00)
#define GPIOE_BASE_ADDRESS (0x48001000)
#define GPIOF_BASE_ADDRESS (0x48001400)
#define GPIOG_BASE_ADDRESS (0x48001800)
#define GPIOH_BASE_ADDRESS (0x48001C00)

#define GPIO_MODER_OFFSET   (0x00) /* A to I */
#define GPIO_OTYPER_OFFSET  (0x04) /* A to I */
#define GPIO_OSPEEDR_OFFSET (0x08) /* A to I */
#define GPIO_PUPDR_OFFSET   (0x0C) /* A to I */
#define GPIO_IDR_OFFSET     (0x10) /* A to I */
#define GPIO_ODR_OFFSET     (0x14) /* A to I */
#define GPIO_BSRR_OFFSET    (0x18) /* A to I */
#define GPIO_LCKR_OFFSET    (0x1C) /* A to I */
#define GPIO_AFRL_OFFSET    (0x20) /* A to I */
#define GPIO_AFRH_OFFSET    (0x24) /* A to I */
#define GPIO_BRR_OFFSET     (0x28) /* A to I */
#define GPIO_ASCR_OFFSET    (0x2C) /* A to H */

#define GPIOB_MODER (*((volatile uint32_t *)(GPIOB_BASE_ADDRESS + GPIO_MODER_OFFSET)))
#define GPIOC_MODER (*((volatile uint32_t *)(GPIOC_BASE_ADDRESS + GPIO_MODER_OFFSET)))

#define GPIOB_BSRR (*((volatile uint32_t *)(GPIOB_BASE_ADDRESS + GPIO_BSRR_OFFSET)))
#define GPIOC_BSRR (*((volatile uint32_t *)(GPIOC_BASE_ADDRESS + GPIO_BSRR_OFFSET)))

/** WIP **/
#define GPIO_REG(x, name) (*((volatile uint32_t *)(GPIO##x##_BASE_ADDRESS + GPIO_##name##_OFFSET)))
