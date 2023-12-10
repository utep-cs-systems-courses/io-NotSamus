#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
//here we are going to include the notes
#include "notes.h"

static int toggle_red = 0;
static int toggle_green = 0;

void playSong(){
    static char currNote =0;
  int notes[26] = {FSH, 0, 0, D, 0, 0, D, E, F, E, 0, D, CSH, D, E, FSH, 0, B, B4, CSH, D, E, D, CSH, A, G};
  int n = 26;
  if (currNote < n){
    buzzer_set_period(notes[currNote]);
    currNote++;
  }
  else{
    currNote = 0;
  }
}