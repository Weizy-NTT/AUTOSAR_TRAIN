#ifndef PARTTIMESTUDENT_H
#define PARTTIMESTUDENT_H

#include "Student.h"
#include <iostream>

class PartTimeStudent : public Student {
private:
    std::string trainingLocation;

public:
    PartTimeStudent(const std::string& id, const std::string& name, const std::string& dob,
                    int year, double score, const std::string& location);
    ~PartTimeStudent() ;
    void showInfor();
    std::string get_Location();
};

#endif // PARTTIMESTUDENT_H
