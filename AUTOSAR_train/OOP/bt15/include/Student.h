#ifndef STUDENT_H
#define STUDENT_H

#include "StudyResult.h"
#include <string>
#include <vector>


class Student {
private:
    std::string studentID;
    std::string fullName;
    std::string dateOfBirth;
    int admissionYear;
    double entryScore;
    std::vector<StudyResult> studyResults;

public:
    Student(const std::string& id, const std::string& name, const std::string& dob,
            int year, double score);

    virtual ~Student();
    virtual void showInfor() = 0;
    std::string getStudentID();
    std::string getFullName();
    std::string getDateOfBirth();
    int getAdmissionYear();
    double getEntryScore();
    std::vector<StudyResult> getStudyResult();
    void addStudyResult(std::string semesterName, double semesterAverage);
    double getSemesterAverage( std::string semesterName);
    

};

#endif // STUDENT_H
