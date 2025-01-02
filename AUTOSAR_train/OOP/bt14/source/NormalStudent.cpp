#include "NormalStudent.h"

NormalStudent::NormalStudent(const std::string& fullName, const std::string& doB, const std::string& sex,
                  const std::string& phoneNumber, const std::string& universityName, const std::string& gradeLevel,
                  int englishScore, float entryTestScore):Student(fullName, doB, sex, phoneNumber, universityName, gradeLevel), englishScore(englishScore),entryTestScore(entryTestScore){}


void NormalStudent::ShowMyInfor()const{
    std::cout << "Full Name: " << fullName << std::endl;
    std::cout << "Date of Birth: " << doB << std::endl;
    std::cout << "Sex: " << sex << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "University Name: " << universityName << std::endl;
    std::cout << "Grade Level: " << gradeLevel << std::endl;
    std::cout << "englishScore: " << englishScore << std::endl;
    std::cout << "entryTestScore: " << entryTestScore << std::endl;
}

float NormalStudent::getEntryTestScore() const{
    return entryTestScore;
}

float NormalStudent::getEnglishScore() const{
    return englishScore;
}