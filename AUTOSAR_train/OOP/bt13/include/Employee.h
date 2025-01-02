#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include"Certificate.h"
#include<iostream>
#include <vector>

using namespace std;
class Employee {
private:
    std::string ID;
    std::string FullName;
    std::string BirthDay;
    std::string Phone;
    std::string Email;
    int Employee_type; // 0: Experience, 1: Fresher, 2: Intern
    static int Employee_count; // Static field to count employees
    std::vector<Certificate> Certificates; // Has-A relationship for certificates

public:
    Employee(const std::string& id, const std::string& fullName, const std::string& birthDay,const std::string& phone, const std::string& email, int type);
    virtual ~Employee() ;
    virtual void showMe() = 0;
    void addCertificate();
    string get_Id();
    int get_Employee_type();
    string get_Fullname();
    string get_BirthDay();
    string get_Phone();
    string get_Email();


    void set_Fullname(string fullname);
    void set_Birthday(string birthday);
    void set_Phone(string phone);
    void set_Email(string email);
    void set_ID(string Id);
    void set_EmployeeType(int type);

    void show_Certificate();
    
};

#endif