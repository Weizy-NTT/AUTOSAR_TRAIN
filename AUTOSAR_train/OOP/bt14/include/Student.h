#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student {
protected:
    std::string fullName;
    std::string doB;
    std::string sex;
    std::string phoneNumber;
    std::string universityName;
    std::string gradeLevel;

public:
    Student(const std::string& fullName, const std::string& doB, const std::string& sex,
            const std::string& phoneNumber, const std::string& universityName, const std::string& gradeLevel);

    virtual ~Student() = default;

    virtual void ShowMyInfor() const = 0;

    const std::string& getFullName() const;
    const std::string& getPhoneNumber() const;
};

#endif // STUDENT_H
