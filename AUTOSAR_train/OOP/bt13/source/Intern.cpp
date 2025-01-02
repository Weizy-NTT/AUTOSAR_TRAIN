#include "Intern.h"
Intern::Intern(const std::string& id, const std::string& fullName, const std::string& birthDay,
           const std::string& phone, const std::string& email, int type,
           const std::string& majors, const std::string& semester, const std::string& universityName)
        : Employee(id, fullName, birthDay, phone, email, type),
          Majors(majors), Semester(semester), University_name(universityName) {}


void Intern::showMe(){
  std::cout << "ID: " << Employee::get_Id() << std::endl;
  std::cout << "Full Name: " << Employee::get_Fullname() << std::endl;
  std::cout << "Birth Day: " << Employee::get_BirthDay() << std::endl;
  std::cout << "Phone: " << Employee::get_Phone() << std::endl;
  std::cout << "Email: " << Employee::get_Email() << std::endl;
  cout<<"Majors: "<<Majors<<endl;
  cout<<"Semester: "<<Semester<<endl;
  cout<<"University_name: "<<University_name<<endl;
  Employee::show_Certificate();
}

void Intern::set_Majors(string Major){
  this->Majors = Major;
}

void Intern::set_Semester (string Semester){
  this->Semester = Semester;
}
void Intern::set_University_name(string University_name){
  this->University_name = University_name;
}