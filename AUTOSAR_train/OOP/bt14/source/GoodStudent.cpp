#include "GoodStudent.h"

GoodStudent::GoodStudent(const std::string& fullName, const std::string& doB, const std::string& sex,const std::string& phoneNumber, const std::string& universityName, const std::string& gradeLevel,float gpa, const std::string& bestRewardName):
Student(fullName, doB, sex, phoneNumber, universityName, gradeLevel), gpa(gpa), bestRewardName(bestRewardName) {}



void GoodStudent::ShowMyInfor() const {
    std::cout << "Full Name: " << fullName << std::endl;
    std::cout << "Date of Birth: " << doB << std::endl;
    std::cout << "Sex: " << sex << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "University Name: " << universityName << std::endl;
    std::cout << "Grade Level: " << gradeLevel << std::endl;
    std::cout << "GPA: " << gpa << std::endl;
    std::cout << "bestRewardName: " << bestRewardName << std::endl;
}

float GoodStudent::getGpa(){return gpa;}
