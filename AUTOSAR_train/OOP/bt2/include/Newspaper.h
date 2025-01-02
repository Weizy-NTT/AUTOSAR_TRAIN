#ifndef NEWSPAPER_H
#define NEWSPAPER_H

#include "Document.h"

class Newspaper : public Document {
private:
    std::string ReleaseDate;

public:
    Newspaper(std::string doccode, std::string publishername, int releasenumber, std::string releasedate);
    void show_all() override;
};

#endif // NEWSPAPER_H
