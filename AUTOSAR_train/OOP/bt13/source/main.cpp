#include "Certificate.h"
#include "Employee.h"
#include "EmployeeManagement.h"
#include "Experience.h"
#include "Fresher.h"
#include "Intern.h"
#include "ValidationExceptions.h" // Contains validation functions
#include "InputHandler.h"

#define ADD 1
#define EDIT 2
#define DELETE 3
#define FIND_INTERS 4
#define FIND_EXPERIENCE 5
#define FIND_FRESHER 6
#define DISPLAY 7
#define EXIT 0

int main(){
    EmployeeManagement management;
    int choice;

     do {
        std::cout << "================== Employee Management System ==================\n";
        std::cout << "1. Add a new employee\n";
        std::cout << "2. Edit an employee\n";
        std::cout << "3. Delete an employee\n";
        std::cout << "4. Find all Interns\n";
        std::cout << "5. Find all Experience employees\n";
        std::cout << "6. Find all Freshers\n";
        std::cout << "7. Display all employees\n";
        std::cout << "0. Exit\n";
        std::cout << "============================================================\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear newline character from the input buffer

        switch (choice) {
        case ADD: {
            std::cout << "Adding a new employee...\n";
            management.addEmployee();
            break;
        }
        case EDIT: {
            std::cout << "Editing an existing employee...\n";
            std::string id = InputHandler::getValidatedInput("Enter student ID: ", Validator::validateID);
            management.changeInfor(id);
            break;
        }
        case DELETE: {
            std::cout << "Deleting an employee...\n";
            std::string id = InputHandler::getValidatedInput("Enter student ID: ", Validator::validateID);
            management.Delete(id);
            break;
        }
        case FIND_INTERS: {
            std::cout << "Finding all Interns...\n";
            management.findIntern();
            break;
        }
        case FIND_EXPERIENCE: {
            std::cout << "Finding all Experience employees...\n";
            management.findExperience();
            break;
        }
        case FIND_FRESHER: {
            std::cout << "Finding all Freshers...\n";
            management.findFresher();
            break;
        }
        case DISPLAY: {
            std::cout << "Displaying all employees...\n";
            management.showAll();
            break;
        }
        case EXIT: {
            std::cout << "Exiting the program...\n";
            break;
        }
        default: {
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
        }
    } while (choice != 0);

    return 0;
}


