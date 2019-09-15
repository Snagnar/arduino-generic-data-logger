#include "led.h"

int LED_PIN = 2;
int BASE_INTERVAL=200;

void executePattern(int length, unsigned long int pattern) {
    for(int x=0; x<length; x++) {
        (pattern&(1<<(length-x))) ? digitalWrite(LED_PIN, HIGH) : digitalWrite(LED_PIN, LOW);
        delay(BASE_INTERVAL);
    }
}
