#include "CSVReader.h"
#include <bits/stdc++.h>
using namespace std;

CSVReader::CSVReader(char delimeter_construct)
{
    delimiter = delimeter_construct;
}

char CSVReader::get_delimiter(){
    return delimiter;
}

bool CSVReader::validate(string data)
{
    return count(data.begin(), data.end(), delimiter) == 5;
}

vector<vector<string>> CSVReader::read(string filename)
{
    ifstream file(filename);
    string line;
    getline(file, line);
    vector<vector<string>> result_vector;
    while (getline(file, line))
    {
        string num, flam, acet, melt_str, stinky, result;
        stringstream stream(line);
        getline(stream, num, delimiter);
        getline(stream, flam, delimiter);
        getline(stream, acet, delimiter);
        getline(stream, melt_str, delimiter);
        getline(stream, stinky, delimiter);
        getline(stream, result, delimiter);
        vector<string> line_vector = {num, num, flam, acet, melt_str, stinky, result};
        result_vector.push_back(line_vector);
    }
    file.close();
    return result_vector;
}

void CSVReader::write(string filename, string out_data)
{
        ofstream file(filename);
        file << out_data;
        file.close();
        return;
}
