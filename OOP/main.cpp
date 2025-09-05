#include <iostream>
#include "student.h"
#include <string>
#include <vector>
#include "group.h"
#include <fstream>

int main(int argc, const char * argv[]) {
    int p;
    GroupSabirzyanov AA2308;
    while(1){
        std::cout<<"choose \n";
        std::cout<<"1. Add new student to group \n";
        std::cout<<"2. Remove all students grom group \n";
        std::cout<<"3. Show all students\n";
        std::cout<<"4. Write information about group into file\n";
        std::cout<<"5. Add students to group from file\n";
        std::cout<<"0. Exit\n";
        std::cin>>p;
        switch(p){
            case 0:
                return 0;
            case 1:
                std::cout<<"Enter name, surname and age student\n";
                AA2308.addMembersToGroup();
                break;
            case 2:
                AA2308.clearGroup();
                break;
            case 3:
                std::cout<<AA2308;
                break;
            case 4:{
                std::ofstream out("/Users/kiramsabirzanov/Documents/OOP/OOP/OOP/group.txt");
                if (!out.is_open()){
                    std::cerr<<"Could not open file group.txt";
                    break;
                }
                out<<AA2308;
                out.close();
                break;
            }
            case 5:{
                std::ifstream in("/Users/kiramsabirzanov/Documents/OOP/OOP/OOP/group.txt");
                if(!in.is_open()){
                    std::cerr<<"Could not open file group.txt";
                    break;
                }
                AA2308.clearGroup();
                AA2308.getMembersFromFile(in);
                in.close();
                break;
            }
            default:
                break;
        }
    }
    return 0;
}
