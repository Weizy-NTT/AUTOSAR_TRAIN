#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "Document.h"

class Magazine : public Document {
private:
    int IssueNumber;
    int IssueMonth;

public:
    Magazine(std::string doccode, std::string publishername, int releasenumber, int issuenumber, int issuemonth);
    void show_all() override;
};

#endif // MAGAZINE_H
