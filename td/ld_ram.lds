ENTRY(_start)

MEMORY
	{
		flash (rx) : ORIGIN = 0x08000000, LENGTH = 1M
		sram1 (wx) : ORIGIN = 0x20000000, LENGTH = 96K
		sram2 (w)  : ORIGIN = 0x10000000, LENGTH = 32K
	}

_init_sp = ORIGIN(sram2) + LENGTH(sram2) - 1;

SECTIONS
	{
		.text : {
			*(.text)
		} > sram1

		.rodata : {
			*(.rodata)
		} > sram1

		.data : {
			*(.data)
		} > sram1

		.bss : {
			_bss_start = .;
			*(.bss) *(COMMON)
			_bss_end = .;
		} > sram1
	}
