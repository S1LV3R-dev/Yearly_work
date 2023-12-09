#include "CSVReader.h"
#include "TissueAnalyzer.h"
#include "UI.h"

#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>

void add_new_tissue(UI ui, CSVReader csv, TissueAnalyzer &analyzer)
{
    vector<string> res_vector;
    string str, res_str;
    while (true)
    {
        res_vector.clear();
        char delimiter = csv.get_delimiter();
        res_str = "";
        for (int i = 1; i <= 5; i++)
        {
            ui.new_tissue_menu(i);
            cin >> str;
            if (str == "0")
            {
                return;
            }
            else{
                res_str += str + delimiter;
                res_vector.push_back(str);
            }
        }
        res_str += '\b';
        cout << res_str;
        if (!csv.validate(res_str))
            ui.wrong();
        else
        {
            csv.write("in.csv", res_str);
            analyzer.add_new_tissue(res_vector);
            break;
        }
    }
}

int main()
{

#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif

    setlocale(LC_ALL, "rus");
    CSVReader csv(',');
    UI ui;
    TissueAnalyzer analyzer(csv.read("in.csv"));
    int variants_range = ui.show_main_menu(), selected_variant;
    while (true)
    {
        while (true)
        {
            cin >> selected_variant;
            if (variants_range < selected_variant or selected_variant < 0)
                ui.wrong();
            else
                break;
        }
        string cur_menu = ui.get_current_menu();
        if (selected_variant == 0)
            variants_range = ui.show_main_menu();
        else if (cur_menu == "main")
        {
            if (selected_variant == 1)
                variants_range = ui.show_help();
            if (selected_variant == 2)
                add_new_tissue(ui, csv, analyzer);
            if (selected_variant == 3)
                variants_range = ui.tissue_screen(analyzer.get_data(), 'a');
            if (selected_variant == 4)
                variants_range = ui.tissue_screen(analyzer.get_data(), 's');
            if (selected_variant == 5)
                cout << "doesn't work yet";
            // analyzer.analyze();
            if (selected_variant == 6)
                variants_range = ui.show_about_menu();
        }
        else if(cur_menu = "tissue_all"){
            if (selected_variant == 1){
                ui.tissue_screen(add_new_tissue(ui, csv, analyzer), 'a');
            }
        }
    }
    return 0;
}