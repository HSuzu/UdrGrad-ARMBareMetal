#include <stdint.h>

extern uint8_t _bss_start, _bss_end;

void init_bss() {
	for(uint8_t *i = &_bss_start; i < &_bss_end; i++) {
		*i = 0;
	}
}
