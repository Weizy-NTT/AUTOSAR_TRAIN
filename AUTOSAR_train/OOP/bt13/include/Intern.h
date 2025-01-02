#ifndef INTERN_H
#define INTERN_H

#include<iostream>
#include"Employee.h"
class Intern : public Employee {
private:
    std::string Majors;         // Current major
    std::string Semester;       // Current semester
    std::string University_name; // University name

public:
    Intern(const std::string& id, const std::string& fullName, const std::string& birthDay,
           const std::string& phone, const std::string& email, int type,
           const std::string& majors, const std::string& semester, const std::string& universityName);

    void showMe();
    void set_Majors(string Majors);
    void set_Semester (string Semester);
    void set_University_name(string University_name);

};


#endif