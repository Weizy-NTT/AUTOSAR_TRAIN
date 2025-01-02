#ifndef SCHOOL_H
#define SCHOOL_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Faculty.h"

class School {
private:
    std::vector<Faculty> faculties; 
    std::string schoolName;

public:
    // Constructor
    School(const std::string& name);

    void addFaculty(const std::string& facultyName);

    void showAllFaculties() ;

    int getTotalRegularStudents() ;

    void findHighestEntryScoreStudent() ;

    std::vector<Student*> findPartTimeStudentsByLocation() ;

    std::vector<Student*> findHighestGPAStudent();

    void sort();

    void displayStatisticsForAllFaculties() const;

    std::vector<Faculty>& getFaculties() ;
    
    
};

#endif // SCHOOL_H
