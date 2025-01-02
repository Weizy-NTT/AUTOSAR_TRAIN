#include "Employee.h"
#include "ValidationExceptions.h" // Contains validation functions
#include "InputHandler.h"
Employee::Employee(const std::string& id, const std::string& fullName, const std::string& birthDay,
             const std::string& phone, const std::string& email, int type)
        : ID(id), FullName(fullName), BirthDay(birthDay), Phone(phone), Email(email), Employee_type(type) {
        ++Employee_count;
    }

string Employee::get_Id(){return ID;}
int Employee::get_Employee_type(){return Employee_type;}
string Employee::get_Fullname(){return FullName;}
string Employee::get_BirthDay(){return BirthDay;}
string Employee::get_Phone(){return Phone;}
string Employee::get_Email(){return Email;}


int Employee::Employee_count = 0;


void Employee::addCertificate(){
    string certificatedID, certificateName, certificateRank, certificatedDate;
    
    certificatedID = InputHandler::getValidatedInput("\nEnter Certificate ID: ",Validator::validateID);
    certificateName = InputHandler::getValidatedInput("Enter Certificate Name: ",Validator::validateIDnew);
    certificateRank = InputHandler::getValidatedInput("Enter Certificate Rank(Must be 'Excellent', 'Very Good', 'Good', or 'Average'): ",Validator::validGradeLevel);
    certificatedDate = InputHandler::getValidatedInput("Enter Certificate Date (YYYY-MM-DD): ",Validator::validateBirthDay);
    Certificates.push_back(Certificate(certificatedID,certificateName,certificateRank,certificatedDate));
}

Employee::~Employee() {};

void Employee::set_Fullname(string fullname){
    this->FullName = fullname;
}

void Employee::set_Birthday(string birthday){
    this->BirthDay = birthday;
}

void Employee::set_Phone(string phone){
    this->Phone = phone;
}

void Employee::set_Email(string email){
    this->Email = email;
}

void Employee::set_ID(string Id){
    this->ID = Id;
}

void Employee::set_EmployeeType(int type){
    this->Employee_type = type;
}


void Employee::show_Certificate(){
    std::string type;
       switch (Employee::get_Employee_type()) {
              case 0: type = "Experience"; break;
              case 1: type = "Fresher"; break;
              case 2: type = "Intern"; break;
              default: type = "Unknown"; break;
       }
       std::cout << "Employee Type: " << type << std::endl;

       std::cout << "Number of Certificates: " << Certificates.size() << std::endl;
       if (!Certificates.empty()) {
              std::cout << "Certificates Details: " << std::endl;
              for ( auto& cert : Certificates) {
              std::cout << "  Certificate ID: " << cert.get_CertificatedID() << std::endl;
              std::cout << "  Certificate Name: " << cert.get_CertificateName() << std::endl;
              std::cout << "  Certificate Rank: " << cert.get_CertificateRank() << std::endl;
              std::cout << "  Certificate Date: " << cert.get_CertificatedDate() << std::endl;
              std::cout << "---------------------" << std::endl;
              }
       } else {
              std::cout << "No certificates available." << std::endl;
       }
}