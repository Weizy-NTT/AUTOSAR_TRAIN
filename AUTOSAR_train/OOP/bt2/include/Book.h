#ifndef BOOK_H
#define BOOK_H

#include "Document.h"

class Book : public Document {
private:
    std::string AuthorName;
    int PageNumber;

public:
    Book(std::string doccode, std::string publishername, int releasenumber, std::string authorname, int pagenumber);
    void show_all() override;
};

#endif // BOOK_H
