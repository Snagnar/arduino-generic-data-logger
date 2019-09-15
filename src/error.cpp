#include "error.h"

ErrorCode ERR_CODE = 0;

//sets error code and calls error signal
void error(ErrorCode code=ERR_CODE) {
    ERR_CODE=code;
    _errorSignal(code);
}

// execute led pattern depending on error code.
// 0b1100101000 (len: 10) is the error prefix
void _errorSignal(ErrorCode code = ERR_CODE) {
    switch (code) {
        case NO_ERROR:
            //do nothing
            break;
        case ERR_SETUP_FAILED:
            executePattern(14, 0b11001010001010);
            break;
        case ERR_DATA_CORRUPT:
            executePattern(16, 0b1100101000101010);
            break;
        case ERR_DATA_WRITE_FAILED:
            executePattern(20, 0b11001010001010111010);
            break;
        case ERR_INVALID_SIGNAL:
            executePattern(18, 0b110010100011101110);
            break;
        case ERR_INVALID_ERROR_CODE:
            executePattern(22, 0b1100101000111011101110);
            break;
        default:
            //call error with valid error code (that the previous one was invalid...)
            error(ERR_INVALID_ERROR_CODE);
            break;
    }
}
