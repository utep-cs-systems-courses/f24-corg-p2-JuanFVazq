#ifndef switches_included

#define switches_included



#define SW1 BIT0  // Switch 1 is P2.0

#define SW2 BIT1  // Switch 2 is P2.1

#define SW3 BIT2  // Switch 3 is P2.2

#define SW4 BIT3  // Switch 4 is P2.3



#define SWITCHES (SW1 | SW2 | SW3 | SW4)  // All four switches



void switch_init();

void switch_interrupt_handler();



// Flags to track the state of each function

extern char green_led_on;

extern char red_led_on;

extern char buzzer_on;

extern char alternate_mode;



#endif // included

