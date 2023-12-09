#include <string>
#include <vector>
using namespace std;

#ifndef UI_H
#define UI_H

class UI
{
private:
    string author;
    string help_message;
    string header;
    string main_menu;
    string help_menu;
    string about_menu;

    string current_menu;

    void clear_screen();

public:
    UI();
    string get_current_menu();
    int show_main_menu();
    int show_help();
    int show_about_menu();
    int tissue_screen(vector<vector<string> > data, char mode);
    void show_tissue_info(vector<vector<string>> data, int tissue_id);
    void new_tissue_menu(int info_id);
    void wrong();
    ~UI();
};

#endif