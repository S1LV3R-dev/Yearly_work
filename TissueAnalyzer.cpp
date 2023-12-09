#include "TissueAnalyzer.h"

TissueAnalyzer::TissueAnalyzer(vector<vector<string>> tissue_data_construct)
{
    tissue_data = tissue_data_construct;
}
vector<vector<string>> TissueAnalyzer::get_data()
{
    return tissue_data;
}
vector<vector<string>> TissueAnalyzer::add_data(vector<string>data)
{
    tissue_data.push_back(data_in);
    return tissue_data;
}