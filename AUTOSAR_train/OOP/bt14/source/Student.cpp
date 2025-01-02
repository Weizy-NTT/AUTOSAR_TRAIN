#include "Student.h"

Student::Student(const std::string& fullName, const std::string& doB, const std::string& sex,
            const std::string& phoneNumber, const std::string& universityName, const std::string& gradeLevel):
            fullName(fullName), doB(doB), sex(sex), phoneNumber(phoneNumber),universityName(universityName),gradeLevel(gradeLevel){}

 
const std::string& Student::getFullName()const{
    return fullName;
}

const std::string& Student::getPhoneNumber() const{
    return phoneNumber;
}