#ifndef LED_LIB
#define LED_LIB

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif

//pin of led
extern int LED_PIN;

//base interval for pattern (time spent on one bit of the pattern)
extern int BASE_INTERVAL;

//function takes 
void executePattern(int, unsigned long int);

#endif //LED_LIB
