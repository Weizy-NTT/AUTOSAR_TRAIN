#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;
class Student{
    private:
    string Name;
    unsigned char Age;
    string Hometown;
    string Class;

    public:
    Student(string name, unsigned char age, string hometown, string class_v);
    ~Student();
    unsigned char get_age();
    string get_hometown();
    void showinf();

};

#endif 