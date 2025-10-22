#include "group.hpp"
#include <iostream>
#include <fstream>
#include <locale>
#include <codecvt>

StudentGroupSabirzyanov::~StudentGroupSabirzyanov() {
    this->clear();
}

void StudentGroupSabirzyanov::clear() {
    for (StudentSabirzyanov* s : students) {
        delete s;
    }
    students.clear();
}

void StudentGroupSabirzyanov::addStudent() {
    StudentSabirzyanov* newStudent = new StudentSabirzyanov();
    newStudent->readFromConsole();
    students.push_back(newStudent);
    std::wcout << L"Студент успешно добавлен." << std::endl;
}

void StudentGroupSabirzyanov::printAll() const {
    if (students.empty()) {
        std::wcout << L"Список студентов пуст." << std::endl;
        return;
    }

    std::wcout << L"--- Список студентов ---" << std::endl;
    for (size_t i = 0; i < students.size(); ++i) {
        std::wcout << i + 1 << L". ";
        students[i]->printToConsole();
    }
    std::wcout << L"------------------------" << std::endl;
}

void StudentGroupSabirzyanov::saveToFile(const std::wstring& filename) const {
    std::wofstream fout;
    fout.open(filename);
    if (!fout) {
        std::wcerr << L"Ошибка: не удалось открыть файл для записи: " << filename << std::endl;
        return;
    }

    fout << students.size() << std::endl;

    for (const StudentSabirzyanov* s : students) {
        s->writeToFile(fout);
    }

    fout.close();
    std::wcout << L"Данные успешно сохранены в файл " << filename << std::endl;
}

void StudentGroupSabirzyanov::loadFromFile(const std::wstring& filename) {
    std::wifstream fin;
    fin.open(filename);
    if (!fin) {
        std::wcerr << L"Ошибка: не удалось открыть файл для чтения: " << filename << std::endl;
        return;
    }

    this->clear();

    int count = 0;
    fin >> count;
    fin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');

    for (int i = 0; i < count; ++i) {
        StudentSabirzyanov* newStudent = new StudentSabirzyanov();
        newStudent->readFromFile(fin);
        students.push_back(newStudent);
    }

    fin.close();
    std::wcout << L"Данные успешно загружены из файла " << filename << std::endl;
}
