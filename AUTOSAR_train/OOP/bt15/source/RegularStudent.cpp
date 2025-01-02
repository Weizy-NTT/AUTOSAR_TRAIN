#include "RegularStudent.h"
#include <iomanip> 
#include <iostream>

RegularStudent::RegularStudent(const std::string& id, const std::string& name, const std::string& dob,
                   int year, double score)
        : Student(id, name, dob, year, score) {}

RegularStudent::~RegularStudent(){}

void RegularStudent::showInfor(){
        // Header
        std::cout << "================== Student Information ==================" << std::endl;
        std::cout << "Student ID:       " << getStudentID() << std::endl;
        std::cout << "Full Name:        " << getFullName() << std::endl;
        std::cout << "Date of Birth:    " << getDateOfBirth() << std::endl;
        std::cout << "Admission Year:   " << getAdmissionYear() << std::endl;
        std::cout << "Entry Score:      " << std::fixed << std::setprecision(2) << getEntryScore() << std::endl;
        // Study Results
        std::cout << "------------------- Study Results -----------------------" << std::endl;
        if (getStudyResult().empty()) {
            std::cout << "No study results available." << std::endl;
        } else {
            std::cout << std::setw(20) << std::left << "Semester Name"
                    << std::setw(10) << "Average" << std::endl;
            std::cout << "--------------------------------------------------------" << std::endl;
            for (const auto& result : getStudyResult()) {
                std::cout << std::setw(20) << std::left << result.getSemesterName()
                        << std::setw(10) << std::fixed << std::setprecision(2) << result.getSemesterAverage()
                        << std::endl;
            }
        }

        // Footer
        std::cout << "========================================================" << std::endl;
    }
