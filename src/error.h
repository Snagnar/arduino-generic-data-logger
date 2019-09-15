#ifndef ERROR_LIB
#define ERROR_LIB

#include "led.h"

// all available error codes
enum ErrorCode {NO_ERROR, ERR_SETUP_FAILED, ERR_DATA_CORRUPT, ERR_DATA_WRITE_FAILED, ERR_INVALID_SIGNAL, ERR_INVALID_ERROR_CODE};

//current error code
extern ErrorCode ERR_CODE;

//error function which calls _errorSignal
void error(ErrorCode code = ERR_CODE);

//executes the led pattern depending on the given error code
void _errorSignal(ErrorCode code = ERR_CODE);

#endif //ERROR_LIB
