#include "StudyResult.h"

StudyResult::StudyResult(const std::string& name, double average)
        : semesterName(name), semesterAverage(average) {}

StudyResult::~StudyResult(){}

std::string StudyResult::getSemesterName()const{
        return semesterName;
}

double StudyResult::getSemesterAverage()const{
        return semesterAverage;
}