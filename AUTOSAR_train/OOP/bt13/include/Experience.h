
#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include"Employee.h"
#include<iostream>
class Experience : public Employee {
private:
    int ExpInYear;       // Number of years of experience
    std::string ProSkill; // Professional skill

public:
    Experience(const std::string& id, const std::string& fullName, const std::string& birthDay,
               const std::string& phone, const std::string& email, int type,
               int expInYear, const std::string& proSkill);

    void showMe();
    void set_ExpInYear (int ExpInYear);
    void set_Proskill (string Proskill);
};



#endif