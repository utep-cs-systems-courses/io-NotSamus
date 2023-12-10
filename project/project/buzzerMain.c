#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "lcdtypes.h"
#include "stateMachine.h"
//this is for the change of the color of the screen
#define BG_COLOR_BUTTON1 COLOR_DARK_GREEN //this is for the third button
#define BG_COLOR_BUTTON2 COLOR_GOLD  //This is for the second button
#define BG_COLOR_BUTTON3 COLOR_BROWN //this is for the third button
#define BG_COLOR_BUTTON4 COLOR_PINK //this is for the fourth button

int oddPress1 = 0;
int oddPress2 = 0;
int oddPress3 = 0;
int oddPress4 = 0;
short redrawScreen=0;

void wdt_c_handler(){
  static int clockCount = 0;

  clockCount++;
  if(clockCount >= 63 && oddPress1 == 1){
    buzzer_set_period(0);
    redrawScreen = 1;
    clockCount = 0;
    
  }
  if(clockCount >= 63 && oddPress2 == 1){
    buzzer_set_period(0);
    redrawScreen = 1;
    clockCount = 0;
  }
  if(clockCount >= 63 && oddPress3 == 1){
    redrawScreen = 1;
    clockCount = 0;
  }
  if(clockCount >= 126 && oddPress4 == 1){
    buzzer_set_period(0);
    redrawScreen = 1;
    clockCount = 0;
  }
}

int main(void) {
  red_on(1);
  green_on(1);
  configureClocks(); /* setup master oscillator, CPU and peripharel clocks */
  lcd_init();
  led_init();
  buzzer_init();
  switch_init();
  enableWDTInterrupts();
  or_sr(0x8); /* CPU off, GIE on*/


  clearScreen(COLOR_ORANGE);
  while(1){
    if(redrawScreen) {
    clearScreen(COLOR_CYAN);      
      

    playSong();
    green_on(0);
    or_sr(0x10);
    green_on(1);
  }// end of while
} 
}// end of main