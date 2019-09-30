MEMORY
  {
    flash (rx) : ORIGIN=0x80000000, LENGTH = 1MB
    sram1 (wx) : ORIGIN=0x20000000, LENGTH = 96KB
    sram2 (w)  : ORIGIN=0x10000000, LENGTH = 32KB
  }

SECTIONS
  {
    .text {
      *(.text)
    } > sram1

    .rodata {
      *(.rodata)
    } > sram1

    .data {
      *(.data)
    } > sram1

    .bss {
      *(.bss) *(COMMON)
    } > sram1
  }
