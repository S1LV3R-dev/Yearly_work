#include <string>
#include <vector>
using namespace std;

#ifndef CSVREADER_H
#define CSVREADER_H

class CSVReader
{
private:
    char delimiter;

public:
    CSVReader(char delimeter_construct);
    char get_delimiter();
    bool validate(string data);
    vector<vector<string>> read(string filename);
    void write(string filename, string out_data);
};

#endif