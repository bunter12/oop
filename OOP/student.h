#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class StudentSabirzyanov{
private:
    char * name = nullptr;
    char * surname = nullptr;
    int age;
public:
    StudentSabirzyanov();
    StudentSabirzyanov(const StudentSabirzyanov& other);
    StudentSabirzyanov(char * p_name, char * p_surname, int p_age);
    ~StudentSabirzyanov();
    
    void setName(char* p_name);
    void setSurname(char* p_surname);
    void setAge(int p_age);
    
    char* getName();
    char* getSurname();
    int getAge();
};

std::ostream& operator<<(std::ostream& stream, StudentSabirzyanov& student);
std::istream& operator>>(std::istream& stream, StudentSabirzyanov& student);

#endif //STUDENT_H
