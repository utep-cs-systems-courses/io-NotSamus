#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"


#define BG_COLOR COLOR_BLACK

int main(){
    configureClocks();
    lcd_init();
    buzzer_init();

    clearScreen(BG_COLOR);
    buzzer_set_period(2000);

    or_sr(0x18);

}
