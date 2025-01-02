#include "Student.h"

Student::Student(const std::string& id, const std::string& name, const std::string& dob,
            int year, double score)
        : studentID(id), fullName(name), dateOfBirth(dob),
          admissionYear(year), entryScore(score) {}

Student::~Student(){}

std::string Student::getStudentID(){return studentID;}
std::string Student::getFullName() {return fullName;}
std::string Student::getDateOfBirth(){return dateOfBirth;}
int Student::getAdmissionYear(){return admissionYear;}
double Student::getEntryScore(){return entryScore;}
std::vector<StudyResult> Student::getStudyResult(){return studyResults;}
void Student::addStudyResult(std::string semesterName, double semesterAverage){
  studyResults.push_back(StudyResult(semesterName,semesterAverage ));
}

double Student::getSemesterAverage( std::string semesterName){
  for(auto &it : studyResults){
    if(it.getSemesterName() == semesterName){
      return it.getSemesterAverage();
    }
  }
  return 0.0;
}