# arduino-generic-data-logger
A generic approach to using data loggers to store sensor data. It supports also status and error output over led blinking patterns.


The program retrieves data at a specified interval from attached sensors (sensor initialisation and data retrieval has to be added to arduino-generic-data-logger.ino). This data gets written to an attached sd card data logger.


## LED Debugging
Also you can add an led (pin is specified in src/led.cpp), on which debugging information will be shown in form of blinking patterns.

To display one of those patterns you can call 

    executePattern(int length, unsigned long int pattern);

from src/led.h. The pattern is specified as a bitsequence, the length parameter specifies the number of bits to be included in that bitsequence.

So for example calling

    executePattern(8, 0b11001010);

would make the LED flash for two base intervals (base interval is specified in led.h), then wait for two intervals and then blink twice for one base interval.

## Signals

The predefined signals include
- SETUP_COMPLETE, which is called if the setup completed successfully (LED-Pattern `0b101010001010`)
- IN_LOOP, which is called at the start of every loop cycle (LED-Pattern `0b101000`)
- DATA_COMPLETE, which is called if the data retrieved from the sensors complies with certain validity checks (which have to be implemented) (LED-Pattern `0b111010`)
- WRITE_COMPLETE, which is called if the write to the SD-Card was successful (LED-Pattern `0b100101010100`)

These patterns are defined in src/signals.cpp.

You can call a signal with function 

    signal(Signal);

## Errors

The predefined errors include
- NO_ERROR, no led pattern
- ERR_SETUP_FAILED, called, if setup fails (LED-Pattern `0b11001010001010`)
- ERR_DATA_CORRUPT, called if data fails in data integrity checks (LED-Pattern, `0b1100101000101010`)
- ERR_DATA_WRITE_FAILED, called, if write to SD card failed, (LED-Pattern `0b11001010001010111010`)
- ERR_INVALID_SIGNAL, called, if signal-function is called with invalid signal code (LED-Pattern `0b110010100011101110`)
- ERR_INVALID_ERROR_CODE, called, if error-function is called with invalid error code (LED-Pattern `0b1100101000111011101110`)

These patterns are defined in src/error.cpp.

There is a certain error prefix for every error code for making it easier spotting them: `0b1100101000`. This pattern is present for all error codes, following an individual pattern each code.

You can call an error with function

    error(ErrorCode);