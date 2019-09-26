CC = arm-none-eabi-gcc
CFLAGS := -Wall -Werror -g -Og -mthumb

EXE = hello
SOURCES = main.o t1.o libs/stubs.o t2.o
DEP_H = $(subst .o,.d, $(SOURCES))

MYLIBS = -L/opt/mylibs

-include DEP_H

$(EXE) : LDLIBS += -lm
$(EXE) : private CFLAGS = -mthumb
$(EXE) : $(SOURCES)
	$(LINK.o) $(MYLIBS) $(CFLAGS) $^  $(LDLIBS) -o $@

libs/stubs.o: CFLAGS = -g -O2  -mthumb

%.d : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -M -MF $@ -MP $<

clean:
	rm $(SOURCES)
	rm $(EXE)

.PHONY: clean
