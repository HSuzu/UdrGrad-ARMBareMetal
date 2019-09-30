ENTRY(main)

MEMORY
  {
    flash (rx) : ORIGIN = 0x80000000, LENGTH = 1M
    sram1 (wx) : ORIGIN = 0x20000000, LENGTH = 96K
    sram2 (w)  : ORIGIN = 0x10000000, LENGTH = 32K
  }

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
      *(.bss) *(COMMON)
    } > sram1
  }
