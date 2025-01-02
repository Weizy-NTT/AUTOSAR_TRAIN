#include "Document.h"

Document::Document(std::string doccode, std::string publishername, int releasenumber)
    : DocCode(doccode), PublisherName(publishername), ReleaseNumber(releasenumber) {}

void Document::show_all() {
    std::cout << "Document Code: " << DocCode << std::endl
              << "Publisher Name: " << PublisherName << std::endl
              << "Release Number: " << ReleaseNumber << std::endl;
}

std::string Document::get_docCode() {
    return DocCode;
}

Document::~Document() {}
