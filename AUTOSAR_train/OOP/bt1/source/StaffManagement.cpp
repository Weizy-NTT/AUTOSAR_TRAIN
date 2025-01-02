#include "StaffManagement.h"
#include <iostream>

void StaffManagement::add_member(Staff* ptr) {
    manage.push_back(ptr);
}

void StaffManagement::find(std::string name) {
    int founded_check = 0;
    for (auto it = manage.begin(); it != manage.end(); ++it) {
        if ((*it)->get_name() == name) {
            ++founded_check;
        }
    }
    std::cout << "Found " << founded_check << " staff member(s) with this name!" << std::endl;
}

void StaffManagement::show_all() {
    for (auto it = manage.begin(); it != manage.end(); ++it) {
        (*it)->print_inf();
        std::cout << std::endl;
    }
}
