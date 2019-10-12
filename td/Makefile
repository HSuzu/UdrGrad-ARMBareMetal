CC := arm-none-eabi-gcc
AS := arm-none-eabi-as
LD := arm-none-eabi-ld
GDB := arm-none-eabi-gdb
CFLAGS := -nostdlib -Wall -Wextra -Werror \
          -c -g -O1 \
          -mfloat-abi=hard -mfpu=fpv4-sp-d16

CPPFLAGS := -Imodules/ \
            -Iutils/ \
            -ICMSIS/Device/ST/STM32L4xx/Include \
            -ICMSIS/Include

TARGET_ARCH := -mcpu=cortex-m4 -mthumb
LDFLAGS := -T ld_ram.lds -nostdlib

EXE = main
SOURCES = main.c \
          init.c \
          modules/gpio/leds/led.c \
          modules/uart/uart.c \
          modules/ledmatrix/matrix.c \
          utils/utils.c \
		  modules/irq/irq.c

S_SOURCES = crt0.s
O_SOURCES = modules/clocks/clocks.o
# Raw data sources
R_SOURCES = image.raw

OBJ := $(subst .c,.o,$(SOURCES))
S_OBJ := $(subst .s,.o,$(S_SOURCES))
R_OBJ := $(subst .raw,.o,$(R_SOURCES))

DEP := $(subst .c,.d,$(SOURCES))

$(EXE): $(OBJ) $(S_OBJ) $(O_SOURCES) $(R_OBJ)

$(R_OBJ) : $(R_SOURCES)
	$(LD) -r -b binary $< -o $@

startgdbserver:
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly

startgdb:
	make
	$(GDB) $(EXE)

starttio:
	tio -b 115200 -d 8 -s 1 -p none /dev/ttyACM0

clean:
	rm -f $(EXE) $(OBJ) $(S_OBJ) $(R_OBJ) $(DEP)

-include $(DEP)

%.d : %.c
	echo $(DEP)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -M -MF $@ -MP $<

.PHONY: startgdbserver clean startgdb starttio
