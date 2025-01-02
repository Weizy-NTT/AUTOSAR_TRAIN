#ifndef REGULARSTUDENT_H
#define REGULARSTUDENT_H

#include "Student.h"

class RegularStudent : public Student {
public:
    RegularStudent(const std::string& id, const std::string& name, const std::string& dob,
                   int year, double score);
    
    ~RegularStudent();
    void showInfor();
};

#endif // REGULARSTUDENT_H
