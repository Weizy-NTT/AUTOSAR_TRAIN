#include"student.h"
#include"studentmanagement.h"
#include <iostream>

#define ADD 1
#define SHOWINF 2
#define FIND 3
#define EXIT 4


int main(){

    StudentManagement Manage;
    int option;
    std::cout << "\nMenu:" << std::endl;
    std::cout << "1. Add new candidate" << std::endl;
    std::cout << "2. Display all candidates" << std::endl;
    std::cout << "3. Search candidate by ID" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> option;
    std::string regis_number;
    do{
        switch(option){
            case ADD:
                Manage.add_newmember();
                break;
            case SHOWINF:
                Manage.show_infor();
                break;
            case FIND:
                std::cout <<"Enter your registeration number: ";
                std::getline(std::cin, regis_number);
                Manage.find(regis_number);
                break;
            case EXIT:
                std::cout << "Exiting...\n";
                break;
            default:
                break;
        }

    }while(option != 4);
}