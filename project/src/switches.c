#include <msp430.h>

#include "switches.h"

#include "led.h"

#include "buzzer.h"

#include "stateMachines.h"



char green_led_on = 0;

char red_led_on = 0;

char buzzer_on = 0;

char alternate_mode = 0;



static char switch_update_interrupt_sense() {

  char p2val = P2IN;

  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);

  return p2val;

}



void switch_init() {

  P2REN |= SWITCHES;  

  P2IE |= SWITCHES;   

  P2OUT |= SWITCHES;  

  P2DIR &= ~SWITCHES; 
  switch_update_interrupt_sense();

}



void switch_interrupt_handler() {

  char p2val = switch_update_interrupt_sense();



  if (!(p2val & SW1)) {

    green_led_on ^= 1; 

    alternate_mode = 0;

    update_green_led(green_led_on);

  }



  if (!(p2val & SW2)) {
    red_led_on ^= 1;   
    alternate_mode = 0;
    update_red_led(red_led_on);
  }

  if (!(p2val & SW3)) { 
    buzzer_on ^= 1;     
    alternate_mode = 0; 
    if (buzzer_on) {
      buzzer_set_period(1000);
    } else {
      buzzer_off();
    }
  }

  if (!(p2val & SW4)) { 
    alternate_mode ^= 1;
    green_led_on = 0;
    red_led_on = 0;
    buzzer_on = alternate_mode;
    if (buzzer_on) {
      buzzer_set_period(1000); 
    } else {
      buzzer_off();
    }
  }
}
