#include <msp430.h>

#include "led.h"



char green_led_state = 0;

char red_led_state = 0;



void led_init() {

  P1DIR |= LEDS; 

  led_update();

}



void led_update() {

  char ledFlags = 0;



  if (red_led_state) {

    ledFlags |= LED_RED;

  }

  if (green_led_state) {

    ledFlags |= LED_GREEN;

  }



  P1OUT &= (0xFF ^ LEDS);

  P1OUT |= ledFlags;     
}



void update_green_led(char state) {

  green_led_state = state;

  led_update();

}



void update_red_led(char state) {

  red_led_state = state;

  led_update();

}

