#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <fstream>

class StudentSabirzyanov {
private:
    std::wstring name;
    int age;
    std::wstring specialty;

public:
    StudentSabirzyanov();

    void readFromConsole();
    void printToConsole() const;
    void readFromFile(std::wifstream& fin);
    void writeToFile(std::wofstream& fout) const;
};

#endif // STUDENT_H
