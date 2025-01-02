#ifndef LIBRARY_MANAGEMENT_H
#define LIBRARY_MANAGEMENT_H

#include <vector>
#include <memory>
#include "Document.h"
#include "Book.h"
#include "Magazine.h"
#include "Newspaper.h"

class Library_management {
private:
    std::vector<std::shared_ptr<Document>> LibraryManage;

public:
    void add_doc(std::shared_ptr<Document> member);
    void delete_doc(std::string doccode);
    void searchDocumentByType(std::string type);
    void displayDocuments();
    ~Library_management();
};

#endif // LIBRARY_MANAGEMENT_H
