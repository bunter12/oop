#ifndef STUDENTGROUP_H
#define STUDENTGROUP_H

#include <vector>
#include <string>
#include "student.hpp"

class StudentGroupSabirzyanov {
private:
    std::vector<StudentSabirzyanov*> students;

public:

    ~StudentGroupSabirzyanov();

    void addStudent();

    void printAll() const;
    void loadFromFile(const std::wstring& filename);
    void saveToFile(const std::wstring& filename) const;
    void clear();
};

#endif // STUDENTGROUP_H
