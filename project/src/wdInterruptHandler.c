#include <msp430.h>

#include "stateMachines.h"

#include "switches.h"



void __interrupt_vec(WDT_VECTOR) WDT() {  // 250 interrupts/sec

  static char blink_count = 0;



  if (++blink_count == 125) {  // Approximately every 0.5 seconds

    blink_count = 0;

    state_advance();           // Advance the state machine

  }

}

