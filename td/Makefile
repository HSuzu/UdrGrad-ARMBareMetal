CC := arm-none-eabi-gcc
CFLAGS := -nostdlib -Wall -Wextra -Werror \
 					-c -g -O1 -mcpu=cortex-m4 -mthumb \
#					-mfloat-abi=hard -mfpu=fpv4-sp-d16

LDFLAGS := -T ld_ram.lds -nostdlib
EXE = main
SOURCES = main.c

OBJ := $(subst .c,.o,$(SOURCES))

-include $(subst .c,.d,$(SOURCES))

$(EXE): $(OBJ)
	$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@

runJLink:
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly

clean:
	rm -f $(EXE) $(OBJ)

%.d : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -M -MF $@ -MP $<

.PHONY: runJLink
