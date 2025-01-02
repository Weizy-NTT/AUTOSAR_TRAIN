#include "LibraryManagement.h"

void Library_management::add_doc(std::shared_ptr<Document> member) {
    for (auto &it : LibraryManage) {
        if ((it)->get_docCode() == member->get_docCode()) {
            std::cout << "Error: Document with code \"" << member->get_docCode() << "\" already exists!\n";
            return;
        }
    }
    LibraryManage.push_back(member);
    std::cout << "Document added successfully!\n";
}

void Library_management::delete_doc(std::string doccode) {
    for (auto it = LibraryManage.begin(); it != LibraryManage.end(); ++it) {
        if (doccode == (*it)->get_docCode()) {
            LibraryManage.erase(it);
            std::cout << "Document with code \"" << doccode << "\" has been deleted successfully.\n";
            return;
        }
    }
    std::cout << "Error: Document with code \"" << doccode << "\" not found.\n";
}

void Library_management::searchDocumentByType(std::string type) {
    if (type == "book") {
        for (auto &it : LibraryManage) {
            if (std::dynamic_pointer_cast<Book>(it)) {
                it->show_all();
            }
        }
    } else if (type == "magazine") {
        for (auto &it : LibraryManage) {
            if (std::dynamic_pointer_cast<Magazine>(it)) {
                it->show_all();
            }
        }
    } else if (type == "newspaper") {
        for (auto &it : LibraryManage) {
            if (std::dynamic_pointer_cast<Newspaper>(it)) {
                it->show_all();
            }
        }
    } else {
        std::cout << "Invalid type!!!" << std::endl;
    }
}

void Library_management::displayDocuments() {
    for (auto &it : LibraryManage) {
        it->show_all();
    }
}

Library_management::~Library_management() {}
