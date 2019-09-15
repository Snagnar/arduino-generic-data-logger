/**
 * Contains implementation of data logger
 */

#include "data_logger.h"

//constructor
Data_Logger::Data_Logger(int cs = -1, String fn = DEFAULT_FILENAME) {
    csPin = cs;
    fileName = fn;
}


//closes stuff, if it is still open (which should not happen)
Data_Logger::~Data_Logger() {
    datafile.close();
}

//initiates the sd card
bool Data_Logger::init() {
    return SD.begin((csPin==-1) ? : csPin);
}

//writes stuff to file
bool Data_Logger::write(String content) {
    datafile = SD.open(fileName, FILE_WRITE);
    if(!datafile)
        return false;
    datafile.println(content);
    datafile.close();
    return true;
}

String Data_Logger::read(int n=1) {
    //we don't actually need that, do we?
}

int Data_Logger::status() {
    //neither do we need this one...
}
