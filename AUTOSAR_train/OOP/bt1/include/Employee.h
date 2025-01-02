#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Staff.h"

class Employee : public Staff {
private:
    std::string Job;

public:
    Employee(std::string job, std::string name, int old, std::string gen, std::string address);
    void print_inf() override;
};

#endif // EMPLOYEE_H
