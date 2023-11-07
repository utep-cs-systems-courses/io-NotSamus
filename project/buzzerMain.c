#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"

int redrawScreen =1;

#define BG_COLOR COLOR_RED

int main(){
    configureClocks();
    lcd_init();	 
    clearScreen(BG_COLOR);
    buzzer_init();
    buzzer_set_period(2000);

    or_sr(0x18);

}