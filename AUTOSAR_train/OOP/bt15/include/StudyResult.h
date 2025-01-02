#ifndef STUDYRESULT_H
#define STUDYRESULT_H

#include <string>

class StudyResult {
private:
    std::string semesterName;
    double semesterAverage;
public:
    StudyResult(const std::string& name, double average);
    ~StudyResult();
    std::string getSemesterName()const;
    double getSemesterAverage()const;
};


#endif // STUDYRESULT_H
