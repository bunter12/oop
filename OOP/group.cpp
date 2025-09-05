#include "group.h"
#include "student.h"
#include <fstream>
#include <typeinfo>

GroupSabirzyanov::GroupSabirzyanov(){}
GroupSabirzyanov::~GroupSabirzyanov(){}

void GroupSabirzyanov::addMembersToGroup(){
    StudentSabirzyanov student;
    std::cin>>student;
    members->push_back(student);
}

void GroupSabirzyanov::clearGroup(){
    members->clear();
}

std::ostream& operator<<(std::ostream& stream, GroupSabirzyanov group){
    if (dynamic_cast<std::ofstream*>(&stream)){
        stream<<group.members->size()<<"\n";
    }
    for(int i = 0; i < group.members->size(); i++)
        stream<<(*group.members)[i];
    return stream;
}

void GroupSabirzyanov::getMembersFromFile(std::ifstream& stream){
    int size;
    stream>>size;
    for (int i = 0 ; i<size; i++){
        members->emplace_back();
        stream>>members->back();
    }
}
