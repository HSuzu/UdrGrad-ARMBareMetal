#include <gpio/registers.h>
#include <rcc/registers.h>

typedef enum {
    LED_OFF,
    LED_YELLOW,
    LED_GREEN,
    LED_BLUE
} LedState;

void led_init(void);
void led_g_on(void);
void led_g_off(void);
void led(LedState);
void ledBlink(LedState);
