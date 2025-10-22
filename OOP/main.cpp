#include <iostream>
#include <locale>
#include "group.hpp"
#include <clocale>


void setup_unicode_console() {
    try {
        std::locale utf8_loc("ru_RU.UTF-8");
        std::locale::global(utf8_loc);
        std::wcin.imbue(utf8_loc);
        std::wcout.imbue(utf8_loc);
    } catch (...) {
        std::locale sys_loc("");
        std::locale::global(sys_loc);
        std::wcin.imbue(sys_loc);
        std::wcout.imbue(sys_loc);
        std::wcerr << L"Не удалось установить ru_RU.UTF-8, используется системная локаль\n";
    }
}



void printMenu() {
    std::wcout << L"\n===== Меню Картотеки Студентов =====" << std::endl;
    std::wcout << L"1. Добавить студента" << std::endl;
    std::wcout << L"2. Показать всех студентов" << std::endl;
    std::wcout << L"3. Сохранить данные в файл" << std::endl;
    std::wcout << L"4. Загрузить данные из файла" << std::endl;
    std::wcout << L"5. Очистить список" << std::endl;
    std::wcout << L"0. Выход" << std::endl;
    std::wcout << L"======================================" << std::endl;
    std::wcout << L"Выберите опцию: ";
}

int main() {
    
    setup_unicode_console();
    
    StudentGroupSabirzyanov group;
    int choice;
    bool running = true;

    while (running) {
        printMenu();
        std::wcin >> choice;

        if (std::wcin.fail()) {
            std::wcin.clear();
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
            std::wcerr << L"Ошибка: введено не число. Попробуйте снова." << std::endl;
            continue;
        }

        switch (choice) {
            case 1:
                std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n'); 
                group.addStudent();
                break;
            case 2:
                group.printAll();
                break;
            case 3: {
                std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
                std::wstring filename;
                std::wcout << L"Введите имя файла для сохранения (например, data.txt): ";
                std::getline(std::wcin, filename);
                group.saveToFile(filename);
                break;
            }
            case 4: {
                std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
                std::wstring filename;
                std::wcout << L"Введите имя файла для загрузки (например, data.txt): ";
                std::getline(std::wcin, filename);
                group.loadFromFile(filename);
                break;
            }
            case 5:
                group.clear();
                std::wcout << L"Список был очищен." << std::endl;
                break;
            case 0:
                running = false;
                break;
            default:
                std::wcout << L"Неверный выбор. Пожалуйста, выберите опцию от 0 до 5." << std::endl;
                break;
        }
    }

    std::wcout << L"Программа завершена." << std::endl;

    return 0;
}
