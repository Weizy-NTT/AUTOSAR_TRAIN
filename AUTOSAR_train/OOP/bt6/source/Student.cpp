#include"Student.h"
using namespace std;

Student::Student(string name, unsigned char age, string hometown, string class_v):Name(name),Age(age),Hometown(hometown),Class(class_v){}
Student::~Student(){};
unsigned char Student::get_age(){return Age;}
string Student::get_hometown(){return Hometown;}
void Student::showinf(){
    cout<< "Name : "<<Name<<endl;
    cout<< "Age : "<<Age<<endl;
    cout<< "Hometown : "<<Hometown<<endl;
    cout<< "Class : "<<Class<<endl;
}