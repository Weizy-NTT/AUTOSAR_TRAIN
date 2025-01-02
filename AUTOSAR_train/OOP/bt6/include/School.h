#ifndef SCHOOL
#define SCHOOL

#include<iostream>
#include<vector>
#include <memory>
#include "Student.h"
using namespace std;
class School{
    private: 
    vector<unique_ptr<Student>> school_list;
    
    public:
    School();
    ~School();

    void add_student(unique_ptr<Student> ptr );
    void show_student_20_old();
    void show_number();
};


#endif
