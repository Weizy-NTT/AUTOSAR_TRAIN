#include "Fresher.h"

Fresher::Fresher(const std::string& id, const std::string& fullName, const std::string& birthDay,
            const std::string& phone, const std::string& email, int type,
            const std::string& graduationDate, const std::string& graduationRank, const std::string& education)
        : Employee(id, fullName, birthDay, phone, email, type),
          Graduation_date(graduationDate), Graduation_rank(graduationRank), Education(education) {};


void Fresher::showMe(){
  std::cout << "ID: " << Employee::get_Id() << std::endl;
  std::cout << "Full Name: " << Employee::get_Fullname() << std::endl;
  std::cout << "Birth Day: " << Employee::get_BirthDay() << std::endl;
  std::cout << "Phone: " << Employee::get_Phone() << std::endl;
  std::cout << "Email: " << Employee::get_Email() << std::endl;
  cout<< "Graduation_date: "<<Graduation_date<<endl;
  cout<< "Graduation_rank: "<<Graduation_rank<<endl;
  cout<< "Education: "<<Education<<endl;
  Employee::show_Certificate();
}

void Fresher::set_Graduation_date(string Graduation_date){
  this->Graduation_date = Graduation_date;
}

void Fresher::set_Graduation_rank(string Graduation_rank){
  this->Graduation_rank = Graduation_rank;
}

void Fresher::set_Education(string Education){
  this->Education =Education;
}