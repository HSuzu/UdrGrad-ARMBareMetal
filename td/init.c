#include <stdint.h>

extern uint8_t _bss_start, _bss_end;
extern uint8_t _lma_data_start, _data_start, _data_end;
extern uint8_t _lma_text_start, _text_start, _text_end;

void _start();

void bootloader() __attribute__ ((section (".bootloader")));

void init_bss() {
	for(uint8_t *i = &_bss_start; i < &_bss_end; i++) {
		*i = 0;
	}
}

void init_data() {
	uint8_t *vma = &_data_start;
	uint8_t *lma = &_lma_data_start;

	while(vma < &_data_end) {
		*(vma++) = *(lma++);
	}
}

void init_memory() {
	init_bss();
	init_data();
}

void bootloader() {
	uint8_t *vma = &_text_start;
	uint8_t *lma = &_lma_text_start;

	while(vma < &_text_end) {
		*(vma++) = *(lma++);
	}
}