#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

enum grade { A, B, C };

class Student {
private:
    std::string RegisNumber;
    std::string Name;
    std::string Address;
    int PriorLevel;
    grade Grade;

public:
    Student(std::string regis, std::string name, std::string address, int number, grade grade_v);
    Student();
    std::string get_regis() const;
    void show_infor() const;
};

#endif