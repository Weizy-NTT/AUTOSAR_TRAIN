#include "Experience.h"
#include <iostream>
Experience::Experience(const std::string& id, const std::string& fullName, const std::string& birthDay,
               const std::string& phone, const std::string& email, int type,
               int expInYear, const std::string& proSkill)
        : Employee(id, fullName, birthDay, phone, email, type), ExpInYear(expInYear), ProSkill(proSkill) {}

void Experience::showMe(){
       std::cout << "ID: " << Employee::get_Id() << std::endl;
       std::cout << "Full Name: " << Employee::get_Fullname() << std::endl;
       std::cout << "Birth Day: " << Employee::get_BirthDay() << std::endl;
       std::cout << "Phone: " << Employee::get_Phone() << std::endl;
       std::cout << "Email: " << Employee::get_Email() << std::endl;
       cout <<"Years of experiences: "<<ExpInYear<<endl;
       cout <<"Proskill: "<<ProSkill<<endl;
       Employee::show_Certificate();
 }

void Experience::set_ExpInYear (int ExpInYear){
       this->ExpInYear = ExpInYear;
}
void Experience::set_Proskill (string Proskill){
       this->ProSkill = Proskill;
}