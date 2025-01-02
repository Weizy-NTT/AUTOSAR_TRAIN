#ifndef NORMALSTUDENT_H
#define NORMALSTUDENT_H

#include "Student.h"

class NormalStudent : public Student {
private:
    float englishScore;
    float entryTestScore;

public:
    NormalStudent(const std::string& fullName, const std::string& doB, const std::string& sex,
                  const std::string& phoneNumber, const std::string& universityName, const std::string& gradeLevel,
                  int englishScore, float entryTestScore);

    void ShowMyInfor() const override;

    float getEntryTestScore() const;
    float getEnglishScore() const;
};

#endif // NORMALSTUDENT_H
