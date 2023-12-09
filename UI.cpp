#include "UI.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void UI::clear_screen()
{
#ifdef _WIN32
    system("cls");
#endif
#ifdef __unix__
    system("clear");
#endif
    cout << header;
}

UI::UI()
{
    author = "";
    help_message = "";
    header = "********************************************************************************\n*                                                                              *\n*                       Идентификация химических волокон                       *\n*                                                                              *\n********************************************************************************\n\n";
    main_menu = "1. Помощь\n2. Добавить новое волокно\n3. Вывсести все волокна\n4. Вывести информацию о волокне\n5. Идентифицировать волокно\n6. Сведения о программе\n";
    help_menu = help_message + "\n0. Главное меню\n";
    about_menu = "Автор: " + author + "\nДата: 08.12.23\n0. Главное меню\n";
}

string UI::get_current_menu()
{
    return current_menu;
}

int UI::show_main_menu()
{
    UI::clear_screen();
    cout << main_menu;
    current_menu = "main";
    int range = 6;
    return range;
}

int UI::show_help()
{
    UI::clear_screen();
    cout << help_menu;
    current_menu = "help";
    int range = 0;
    return range;
}

int UI::show_about_menu()
{
    UI::clear_screen();
    cout << about_menu;
    current_menu = "about";
    int range = 0;
    return range;
}

int UI::tissue_screen(vector<vector<string>> data, char mode)
{
    if (mode == 'a')
    {
        current_menu = "tissue_all";
        for (int i = 0; i < data.size(); i++)
        {
            printf("%2s, %5s, %5s, %5s, %5s, %s\n", data[i][0], data[i][1], data[i][2], data[i][3], data[i][4], data[i][5]);
        }
        cout << "1. Добавить новое волокно\n0. Главное меню\n";
        return 1;
    }
    else if (mode == 's')
    {
        current_menu = "tissue_single";
        for (int i = 0; i < data.size(); i++)
        {
            cout << i + 1 << " " << data[i][5] << "\n";
        }
        cout << "Выберите волокно: ";
        int range = data.size();
        return range;
    }
}

void UI::show_tissue_info(vector<vector<string>> data, int tissue_id)
{
    printf("%2s, %5s, %5s, %5s, %5s, %s\n", data[tissue_id][0], data[tissue_id][1], data[tissue_id][2], data[tissue_id][3], data[tissue_id][4], data[tissue_id][5]);
    ;
    return;
}

void UI::new_tissue_menu(int info_id)
{
    if (info_id == 1)
        cout << "Горит быстро: ";
    if (info_id == 2)
        cout << "Растворяется в ацетоне: ";
    if (info_id == 3)
        cout << "Из расплава можно вытянуть нити: ";
    if (info_id == 4)
        cout << "При горении ощущается запах: ";
    if (info_id == 5)
        cout << "Волокно (результат распознавания): ";
    return;
}

void UI::wrong()
{
    cout << "ОШИБКА: убедитесь в правильности введённой информации";
    return;
}

UI::~UI()
{
    delete &main_menu;
    delete &help_menu;
    delete &current_menu;
}