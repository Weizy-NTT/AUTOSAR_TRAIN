#include "student.h"

Student::Student(std::string regis, std::string name, std::string address, int number, grade grade_v)
    : RegisNumber(regis), Name(name), Address(address), PriorLevel(number), Grade(grade_v) {}

Student::Student() {}

std::string Student::get_regis() const {
    return RegisNumber;
}

void Student::show_infor() const {
    std::cout << "Name : " << Name << std::endl;
    std::cout << "RegisNumber : " << RegisNumber << std::endl;
    std::cout << "Address : " << Address << std::endl;
    std::cout << "PriorLevel : " << PriorLevel << std::endl;
    std::cout << "Grade : " << Grade << std::endl;
}
