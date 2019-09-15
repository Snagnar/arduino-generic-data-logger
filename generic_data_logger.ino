/**
 * @file example script for data collection and storing.
 *  It displays its current state by letting the attached led
 *  blink at certain patterns.
 * @author Paul Mattes
 */

#include <SPI.h>
#include <SD.h>
#include "src/error.h"
#include "src/signal.h"
#include "src/data_logger.h"

//enables/disables some serial output
#define DEBUG true 

//interval at which sensor data is collected and written to sd card
#define RETRIEVAL_INTERVAL 1000 

using namespace std;

Data_Logger dLog(4, "file.csv");



String getDataFromSources() {

    // get the data from sources and convert them to string

    //...

    return "hello, mister";
}

bool isValid(String data) {

    //check if provided data string is valid 

    //...

    return true;
}

//setup function
void setup() {

    //setup serial if debug mode is enabled
    if(DEBUG) {
        Serial.begin(9600);
    }

    //setup data sources

    //...


    if(DEBUG)
        Serial.println("Data sources set up!");

    //setup data logger communication
    if(!dLog.init()) {
        error(ERR_SETUP_FAILED);
        return;
    }

    if(DEBUG)
        Serial.println("Data Logger set up!");

    //signal successful setup
    signal(SETUP_COMPLETE);
}


void loop() {
    //say that youre in loop
    signal(IN_LOOP);

    //retrieve data
    String data = getDataFromSources();

    //check data consitency
    if(isValid(data))
        signal(DATA_COMPLETE);
    else
        error(ERR_DATA_CORRUPT);

    //write that data
    if(dLog.write(data))
        signal(WRITE_COMPLETE);
    else
        error(ERR_DATA_WRITE_FAILED);
    
    //wait for specified interval
    delay(RETRIEVAL_INTERVAL);
}
