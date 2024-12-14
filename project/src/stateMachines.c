#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"

static char led_alternate_state = 0;
static unsigned int alternate_counter = 0;

void state_advance() {
  if (alternate_mode) {
    alternate_leds();
  }
}

void alternate_leds() {
  alternate_counter++;
  if (alternate_counter >= 250) {
    alternate_counter = 0;
    led_alternate_state ^= 1;
    if (led_alternate_state) {
      update_green_led(1);
      update_red_led(0);
    } else {
      update_green_led(0);
      update_red_led(1);
    }
  }
}
