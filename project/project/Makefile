# makfile configuration
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS               = msp430-elf-gcc

all: final.elf

#additional rules for files
final.elf: ${COMMON_OBJECTS} buzzerMain.o libTimer.a wdt_handler.o switches.o p2_interrupt_handler.o led.o lcddraw.o lcdutils.o buzzer.o stateMachine.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ 
load: final.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf
