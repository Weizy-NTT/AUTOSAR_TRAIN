#ifndef EMPLOYEE_MANAGEMENT
#define EMPLOYEE_MANAGEMENT
#include <vector>
#include<iostream>
#include "Employee.h"

class EmployeeManagement{
    private:
    vector<Employee*> EmployeeList;

    public:
    EmployeeManagement();
    ~EmployeeManagement();
    void addEmployee();
    void changeInfor(string Id);
    void Delete(string Id);
    void findIntern();
    void findExperience();
    void findFresher();
    void showAll();
    bool validID(std::string ID);
};


#endif