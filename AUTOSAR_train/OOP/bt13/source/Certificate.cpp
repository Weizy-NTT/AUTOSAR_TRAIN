#include "Certificate.h"

Certificate::Certificate(const std::string& id, const std::string& name, const std::string& rank, const std::string& date)
        : CertificatedID(id), CertificateName(name), CertificateRank(rank), CertificatedDate(date) {};


void Certificate::showInf(){
    std::cout << "Certificate ID: " << CertificatedID << "\n"
              << "Certificate Name: " << CertificateName << "\n"
              << "Certificate Rank: " << CertificateRank << "\n"
              << "Certificate Date: " << CertificatedDate << "\n"
              << "-------------------------\n";
}

void Certificate::set_CertificatedID(string CertificatedID){
    this->CertificatedID = CertificatedID;
}
void Certificate::set_CertificateName(string CertificateName){
    this->CertificateName = CertificateName;
}
void Certificate::set_CertificateRank(string CertificateRank){
    this->CertificateRank = CertificateRank;
}
void Certificate::set_CertificatedDate(string CertificatedDate){
    this->CertificatedDate = CertificatedDate;
}

string Certificate::get_CertificatedID(){
    return CertificatedID;
}
string Certificate::get_CertificateName(){
    return CertificateName;
}
string Certificate::get_CertificateRank(){
    return CertificateRank;
}
string Certificate::get_CertificatedDate(){
    return CertificatedDate;
}