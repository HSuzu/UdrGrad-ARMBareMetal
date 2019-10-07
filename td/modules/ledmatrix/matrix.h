#include <stm32l475xx.h>
#include <stm32l4xx.h>
#include <stdint.h>

void matrix_init();
void pulse_SCK();
void pulse_LAT();
void deactivate_rows();
void activate_row(int row);
