#include <msp430.h>
//basically this is the definition of the switches
//instead of having a bunch of declarations,
//its a file that is reusable
#include "switches.h"
#include "led.h"


int sw1Down = 0;
int sw2Down = 0;
int sw3Down = 0;
int sw4Down = 0;

static char switch_update_interrupt_sense(){
    //we are going to do the same that we where doing with the
    //button that its on the board, but now with the one with the 
    //launchpad
    char p2val = P2IN;

    P2IES |= (p2val & SWITCHES);
    P2IES &= (p2val | ~SWITCHES);

    return p2val;
}
// The initializer for the switches
void switch_init(){
    P2REN |= SWITCHES;
    P2IE |= SWITCHES;
    P2OUT |= SWITCHES;
    P2DIR &= ~SWITCHES;
    switch_update_interrupt_sense();
    led_update();
}



//this is the handler 
void switch_interrupt_handler(){
    //this will get the button feedback
    char p2val = switch_update_interrupt_sense();

    //this is just a map of the previous state
    int prev1 = sw1Down;
    int prev2 = sw2Down;
    int prev3 = sw3Down;
    int prev4 = sw4Down;

    sw1Down = (p2val & SW1) ? 0 : 1;
    sw2Down = (p2val & SW2) ? 0 : 1;
    sw3Down = (p2val & SW3) ? 0 : 1;
    sw4Down = (p2val & SW4) ? 0 : 1;

    if(prev1 != sw1Down && sw1Down){
        oddPress1 ^= 1;

        oddPress2=0, oddPress3=0, oddPress4=0;
    }
    else if(prev2 != sw2Down && sw2Down){
        oddPress2 ^= 1;

        oddPress1=0, oddPress3=0, oddPress4=0;
    }
    else if(prev3 != sw3Down && sw3Down){
        oddPress3 ^= 1;

        oddPress1=0, oddPress2=0, oddPress4=0;
    }
    else if(prev4 != sw4Down && sw4Down){
        oddPress4 ^= 1;

        oddPress1=0, oddPress2=0, oddPress3=0;
    }




}

