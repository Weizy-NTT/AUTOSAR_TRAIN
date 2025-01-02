#ifndef CERTIFICATE_H
#define CERTIFICATE_H

#include<iostream>
using namespace std;
class Certificate {
private:
    std::string CertificatedID;
    std::string CertificateName;
    std::string CertificateRank;
    std::string CertificatedDate;

public:
    Certificate(const std::string& id, const std::string& name, const std::string& rank, const std::string& date);

    void showInf();
    void set_CertificatedID(string CertificatedID);
    void set_CertificateName(string CertificateName);
    void set_CertificateRank(string CertificateRank);
    void set_CertificatedDate(string CertificatedDate);

    string get_CertificatedID();
    string get_CertificateName();
    string get_CertificateRank();
    string get_CertificatedDate();

    
};

#endif