#include <stm32l475xx.h>
#include <stm32l4xx.h>
#include <utils.h>
#include <stdint.h>

typedef struct {
	uint8_t r;
	uint8_t g;
	uint8_t b;
} rgb_color;

void matrix_init();
void init_bank0();
void pulse_SCK();
void pulse_LAT();
void deactivate_rows();
void activate_row(int row);

void send_byte(uint8_t val, int bank);
void mat_set_row(int row, const rgb_color *val);

void test_pixels();
