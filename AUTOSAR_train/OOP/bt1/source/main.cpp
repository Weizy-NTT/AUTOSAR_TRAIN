#include <iostream>      // Dùng cho std::cout, std::cin
#include <string>        // Dùng cho std::string
#include <vector>        // Dùng cho std::vector
#include "StaffManagement.h" // Class StaffManagement
#include "Worker.h"      // Class Worker
#include "Engineer.h"    // Class Engineer
#include "Employee.h"    // Class Employee

#define ADD 1
#define FIND 2
#define SHOWINF 3
#define EXIT 4

int main() {
    StaffManagement staffManagement;
    int choice;

    do {
        std::cout << "\n====== Staff Management ======\n";
        std::cout << "1. Add Member\n";
        std::cout << "2. Find Member by Name\n";
        std::cout << "3. Show All Members\n";
        std::cout << "4. Exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice) {
        case ADD: {
            int type;
            std::cout << "\nEnter the type of Staff (1: Worker, 2: Engineer, 3: Employee): ";
            std::cin >> type;

            std::string name, gender, address, job, field;
            int age, level;

            std::cout << "Enter Name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Enter Age: ";
            std::cin >> age;
            std::cout << "Enter Gender: ";
            std::cin.ignore();
            std::getline(std::cin, gender);
            std::cout << "Enter Address: ";
            std::getline(std::cin, address);

            if (type == 1) { // Add Worker
                std::cout << "Enter Level: ";
                std::cin >> level;
                staffManagement.add_member(new Worker(level, name, age, gender, address));
            } else if (type == 2) { // Add Engineer
                std::cout << "Enter Field: ";
                std::cin.ignore();
                std::getline(std::cin, field);
                staffManagement.add_member(new Engineer(field, name, age, gender, address));
            } else if (type == 3) { // Add Employee
                std::cout << "Enter Job: ";
                std::cin.ignore();
                std::getline(std::cin, job);
                staffManagement.add_member(new Employee(job, name, age, gender, address));
            } else {
                std::cout << "Invalid type!\n";
            }
            break;
        }
        case FIND: {
            std::string name;
            std::cout << "\nEnter Name to Find: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            staffManagement.find(name);
            break;
        }
        case SHOWINF:
            std::cout << "\nAll Members:\n";
            staffManagement.show_all();
            break;
        case EXIT:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
