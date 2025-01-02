#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <string>

class Document {
private:
    std::string DocCode;
    std::string PublisherName;
    int ReleaseNumber;

public:
    Document(std::string doccode, std::string publishername, int releasenumber);
    virtual void show_all();
    std::string get_docCode();
    virtual ~Document();
};

#endif // DOCUMENT_H

