#include <iostream>               // std::cout, std::cin
#include <string>                 // std::string
#include "LibraryManagement.h"    // Class Library_management
#include "Book.h"                 // Class Book
#include "Magazine.h"             // Class Magazine
#include "Newspaper.h"            // Class Newspaper

#define ADD 1
#define DELETE 2
#define SHOWINF 3
#define FIND 4
#define EXIT 5

int main() {
    Library_management manager;
    int choice;

    do {
        std::cout << "\n====== Library Management ======\n";
        std::cout << "1. Add Document\n";
        std::cout << "2. Delete Document by Code\n";
        std::cout << "3. Display All Documents\n";
        std::cout << "4. Search Document by Type\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case ADD: {
            int type;
            std::cout << "Enter document type (1: Book, 2: Magazine, 3: Newspaper): ";
            std::cin >> type;

            std::string code, publisherName, author, releaseDate;
            int releaseNumber, issueNumber, pageNumber, issueMonth;

            if (type == 1) {
                std::cout << "Enter Book Code: ";
                std::cin >> code;
                std::cout << "Enter Publisher Name: ";
                std::cin.ignore();
                std::getline(std::cin, publisherName);
                std::cout << "Enter Author Name: ";
                std::getline(std::cin, author);
                std::cout << "Enter Number of Pages: ";
                std::cin >> pageNumber;
                manager.add_doc(std::make_shared<Book>(code, publisherName, releaseNumber, author, pageNumber));
            } else if (type == 2) {
                std::cout << "Enter Magazine Code: ";
                std::cin >> code;
                std::cout << "Enter Publisher Name: ";
                std::cin.ignore();
                std::getline(std::cin, publisherName);
                std::cout << "Enter Issue Number: ";
                std::cin >> issueNumber;
                std::cout << "Enter Issue Month: ";
                std::cin >> issueMonth;
                manager.add_doc(std::make_shared<Magazine>(code, publisherName, releaseNumber, issueNumber, issueMonth));
            } else if (type == 3) {
                std::cout << "Enter Newspaper Code: ";
                std::cin >> code;
                std::cout << "Enter Publisher Name: ";
                std::cin.ignore();
                std::getline(std::cin, publisherName);
                std::cout << "Enter Release Date: ";
                std::getline(std::cin, releaseDate);
                manager.add_doc(std::make_shared<Newspaper>(code, publisherName, releaseNumber, releaseDate));
            } else {
                std::cout << "Invalid type!\n";
            }
            break;
        }
        case DELETE: {
            std::string code;
            std::cout << "Enter Document Code to Delete: ";
            std::cin >> code;
            manager.delete_doc(code);
            break;
        }
        case SHOWINF:
            std::cout << "\nAll Documents:\n";
            manager.displayDocuments();
            break;
        case FIND: {
            std::string type;
            std::cout << "Enter Type to Search (Book, Magazine, Newspaper): ";
            std::cin >> type;
            manager.searchDocumentByType(type);
            break;
        }
        case EXIT:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

