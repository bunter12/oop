#include "student.hpp"
#include <iostream>
#include <string>
#include <codecvt>
#include <locale>
#include <limits>

StudentSabirzyanov::StudentSabirzyanov() : age(0) {}

static std::wstring utf8_to_wstring(const std::string& str) {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv;
    return conv.from_bytes(str);
}
static std::string wstring_to_utf8(const std::wstring& wstr) {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv;
    return conv.to_bytes(wstr);
}

void StudentSabirzyanov::readFromConsole() {
    std::string input;

    std::cout << "Введите имя студента: ";
    std::getline(std::cin, input);
    name = utf8_to_wstring(input);

    std::cout << "Введите возраст студента: ";
    std::getline(std::cin, input);
    try {
        age = std::stoi(input);
    } catch (...) {
        std::cerr << "Ошибка: некорректный возраст. Установлено значение 0." << std::endl;
        age = 0;
    }

    std::cout << "Введите специальность: ";
    std::getline(std::cin, input);
    specialty = utf8_to_wstring(input);
}

void StudentSabirzyanov::printToConsole() const {
    std::cout << "Имя: " << wstring_to_utf8(name)
              << ", Возраст: " << age
              << ", Специальность: " << wstring_to_utf8(specialty)
              << std::endl;
}

void StudentSabirzyanov::readFromFile(std::wifstream& fin) {
    std::getline(fin, name);
    fin >> age;
    fin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
    std::getline(fin, specialty);
}

void StudentSabirzyanov::writeToFile(std::wofstream& fout) const {
    fout << name << std::endl;
    fout << age << std::endl;
    fout << specialty << std::endl;
}
