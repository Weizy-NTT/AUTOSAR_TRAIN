#ifndef FRESHER_H
#define FRESHER_H

#include<iostream>
#include"Employee.h"

class Fresher : public Employee {
private:
    std::string Graduation_date; // Graduation date
    std::string Graduation_rank; // Graduation rank
    std::string Education;       // School name

public:
    Fresher(const std::string& id, const std::string& fullName, const std::string& birthDay,
            const std::string& phone, const std::string& email, int type,
            const std::string& graduationDate, const std::string& graduationRank, const std::string& education);

    void showMe();
    void set_Graduation_date(string Graduation_date);
    void set_Graduation_rank(string Graduation_rank);
    void set_Education(string Education);
};
#endif