#pragma once
#include "Header.h"

class CsvReaderWritter {
public:
    // Read
    vector<string> readFile(string path);
    vector<string> splitString(string input, char splitter);
    string getFileName(string path);

    // Write
    void write(string path, string name, string owner, string phoneNumber, string address, string occupation);

    // Clear file
    void clearFile(string path);
};