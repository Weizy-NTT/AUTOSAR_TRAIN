#ifndef STAFFMANAGEMENT_H
#define STAFFMANAGEMENT_H

#include <vector>
#include <string>
#include "Staff.h"

class StaffManagement {
private:
    std::vector<Staff*> manage;

public:
    void add_member(Staff* ptr);
    void find(std::string name);
    void show_all();
};

#endif // STAFFMANAGEMENT_H
