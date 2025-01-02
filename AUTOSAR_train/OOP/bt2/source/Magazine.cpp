#include "Magazine.h"

Magazine::Magazine(std::string doccode, std::string publishername, int releasenumber, int issuenumber, int issuemonth)
    : Document(doccode, publishername, releasenumber), IssueNumber(issuenumber), IssueMonth(issuemonth) {}

void Magazine::show_all() {
    Document::show_all();
    std::cout << "Issue Number: " << IssueNumber << std::endl
              << "Issue Month: " << IssueMonth << std::endl;
}
