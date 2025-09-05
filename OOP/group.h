#ifndef GROUP_H
#define GROUP_H

#include "student.h"
#include <vector>
#include <iostream>

class GroupSabirzyanov{
private:
    std::shared_ptr<std::vector<StudentSabirzyanov>> members = std::make_shared<std::vector<StudentSabirzyanov>>();
public:
    GroupSabirzyanov();
    ~GroupSabirzyanov();
    
    void addMembersToGroup();
    void clearGroup();
    
    friend std::ostream& operator<<(std::ostream& stream, GroupSabirzyanov group);
    void getMembersFromFile(std::ifstream& stream);
};


#endif //GROUP_H
