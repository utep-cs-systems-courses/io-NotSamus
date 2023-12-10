#include <msp430.h>

//map for the leds
#include "led.h"

//map for the switches
#include "switches.h"

// initialize the leds on the board
void led_init(){
    P1DIR |= LEDS;
    led_update();
}

/* This is to update the leds*/
void led_update(){
    //Remember: leds initialize to off
    P1OUT &= ~LEDS;
}

void alternate(int on){
    switch (on)
    {
    case 0:
        red_on(1);
        green_on(1);
        break;
    case 1:
        red_on(0);
        green_on(1);
        break;
    default:
    leds_on(0);
        break;
    }
}
void leds_on(int on){
    switch (on)
    {
    case 0:
        P1OUT &= ~LEDS;
        break;
    case 1:
        P1OUT |= LEDS;
        break;
    default:
        P1OUT |= LEDS;
        break;
    }
}

void red_on(int on){
    switch (on)
    {
    case 0:
        P1OUT &= ~LED_RED;
        break;
    case 1:
        P1OUT |= LED_RED;
        break;
    default:
        P1OUT |= LEDS;
        break;
    }
}

void green_on(int on){
    switch (on)
    {
    case 0:
        P1OUT &= ~LED_GREEN;
        break;
    case 1:
        P1OUT |= LED_GREEN;
        break;
    default:
        P1OUT |= LEDS;
        break;
    }
}




