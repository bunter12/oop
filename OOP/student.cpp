#include "student.h"
#include <cstring>
#include <stdlib.h>
#include <typeinfo>
#include <fstream>

StudentSabirzyanov::StudentSabirzyanov(char * p_name, char * p_surname, int p_age){
    age = p_age;
    name = (char *) malloc(sizeof(char) * strlen(p_name));
    surname = (char *) malloc(sizeof(char) * strlen(p_surname));
    strcpy(name,p_name);
    strcpy(surname,p_surname);
}

//StudentSabirzyanov::~StudentSabirzyanov(){
//    free(name);
//    free(surname);
//}

char* StudentSabirzyanov::getName(){
    return name;
}

char* StudentSabirzyanov::getSurname(){
    return surname;
}

void StudentSabirzyanov::setSurname(char * p_surname){
    if(surname!=nullptr){
        free(surname);
    }
    surname = (char *) malloc(sizeof(char) * strlen(p_surname));
    strcpy(surname,p_surname);
}

void StudentSabirzyanov::setName(char * p_name){
    if(name!=nullptr){
        free(name);
    }
    name = (char *) malloc(sizeof(char) * strlen(p_name));
    strcpy(name,p_name);
}


std::ostream& operator<<(std::ostream& stream, StudentSabirzyanov& student){
    
    if (dynamic_cast<std::ofstream*>(&stream)){
        stream<<student.getName()<<"\n";
        stream<<student.getSurname()<<"\n";
        stream<<student.getAge()<<"\n";
    }
    else{
        stream<<"Name: "<<student.getName()<<" \n";
        stream<<"Surname: "<<student.getSurname()<<" \n";
        stream<<"Age: "<<student.getAge()<<" \n";
    }
    return stream;
}

std::istream& operator>>(std::istream& stream, StudentSabirzyanov& student){
    char p_name[100];
    char p_surname[100];
    int p_age;
    
    stream>>p_name;
    stream>>p_surname;
    stream>>p_age;
    
    student.setName(p_name);
    student.setSurname(p_surname);
    student.setAge(p_age);
    
    return stream;
}

void StudentSabirzyanov::setAge(int p_age){
    age=p_age;
}

int StudentSabirzyanov::getAge(){
    return age;
}

StudentSabirzyanov::StudentSabirzyanov(){
}
