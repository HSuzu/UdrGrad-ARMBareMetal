CC := arm-none-eabi-gcc
AS := arm-none-eabi-as
CFLAGS := -nostdlib -Wall -Wextra -Werror \
					-c -g -O1 \
#					-mfloat-abi=hard -mfpu=fpv4-sp-d16

CPPFLAGS := -Imodules/

TARGET_ARCH := -mcpu=cortex-m4 -mthumb
LDFLAGS := -T ld_ram.lds -nostdlib

EXE = main
SOURCES = main.c modules/gpio/leds/led.c init.c
S_SOURCES = crt0.s

OBJ := $(subst .c,.o,$(SOURCES))
S_OBJ := $(subst .s,.o,$(S_SOURCES))

DEP := $(subst .c,.d,$(SOURCES))

$(EXE): $(OBJ) $(S_OBJ)
	$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@

startgdbserver:
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly

clean:
	rm -f $(EXE) $(OBJ) $(S_OBJ) $(DEP)

#-include $(DEP)

%.d : %.c
	echo $(DEP)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -M -MF $@ -MP $<

.PHONY: startgdbserver clean
