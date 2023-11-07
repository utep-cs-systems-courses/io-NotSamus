# makfile configuration
COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: buzzer.elf
#additional rules for files
buzzer.elf: ${COMMON_OBJECTS} buzzer.o buzzerMain.o lcddraw.o lcdutils.o libTimer.a
		${CC} ${CFLAGS} -o $@ $^

load: buzzer.elf
	msp430loader.sh  $^

clean: $^
	rm -f *.o *.elf

lcdutils.c: lcdutils.h
buzzer.c: buzzer.h
lcddraw.c: lcddraw.h
buzzerMain.c: buzzer.h lcdutils.h lcddraw.h


