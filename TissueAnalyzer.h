#include <vector>
#include <string>
using namespace std;

class TissueAnalyzer
{
private:
    vector<vector<string >> tissue_data;

public:
    // Default constructor
    TissueAnalyzer(vector<vector<string >> tissue_data_construct);
    vector<vector<string >> get_data();
    vector<vector<string >> add_data(string data_in);
    string analyze(vector<string > analyze_data);
};