/**
 * Data logger class to wrap sd communication
 */

#ifndef DATA_LOGGER
#define DATA_LOGGER

#include <string.h>
#include <SD.h>

#define DEFAULT_FILENAME "file.csv"

class Data_Logger {
    public:
    //constructor takes cs pin and file name
    Data_Logger(int csPin = -1, String filename = DEFAULT_FILENAME);
    ~Data_Logger();

    bool init();

    //writes content to file. If successful returns true, else false
    bool write(String);

    //reads the last n lines of file
    String read(int n=1);

    //returns status code of data logger
    int status();


    private:
    //stores the file name on the sd card
    String fileName="data.csv";
    int csPin;
    File datafile;
};


#endif //DATA_LOGGER
