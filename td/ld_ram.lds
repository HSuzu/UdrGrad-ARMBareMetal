ENTRY(_start)

MEMORY
	{
		flash (rx) : ORIGIN = 0x00000000, LENGTH = 1M
		sram1 (wx) : ORIGIN = 0x20000000, LENGTH = 96K
		sram2 (w)  : ORIGIN = 0x10000000, LENGTH = 32K
	}

_init_sp = ORIGIN(sram2) + LENGTH(sram2);

SECTIONS
	{
		.irq_table : {
			*(.irq_table)
		} > flash

		.bootloader : {
			*(.bootloader)
		} > flash

		.text : {
			_text_start = .;
			*(.text)
			_text_end = .;
		} > sram1 AT > flash

		.rodata : {
			*(.rodata)
		} > flash

		.data : {
			_data_start = .;
			*(.data)
			_data_end = .;
		} > sram1 AT > flash

		.bss : {
			_bss_start = .;
			*(.bss) *(COMMON)
			_bss_end = .;
		} > sram1
	}

_lma_data_start = LOADADDR(.data);
_lma_text_start = LOADADDR(.text);