#include "Book.h"

Book::Book(std::string doccode, std::string publishername, int releasenumber, std::string authorname, int pagenumber)
    : Document(doccode, publishername, releasenumber), AuthorName(authorname), PageNumber(pagenumber) {}

void Book::show_all() {
    Document::show_all();
    std::cout << "Author Name: " << AuthorName << std::endl
              << "Page Number: " << PageNumber << std::endl;
}
