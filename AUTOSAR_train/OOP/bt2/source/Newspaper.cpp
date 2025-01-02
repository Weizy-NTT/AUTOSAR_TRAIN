#include "Newspaper.h"

Newspaper::Newspaper(std::string doccode, std::string publishername, int releasenumber, std::string releasedate)
    : Document(doccode, publishername, releasenumber), ReleaseDate(releasedate) {}

void Newspaper::show_all() {
    Document::show_all();
    std::cout << "Release Date: " << ReleaseDate << std::endl;
}
