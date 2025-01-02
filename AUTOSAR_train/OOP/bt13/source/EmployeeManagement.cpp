#include "ValidationExceptions.h" // Contains validation functions
#include "InputHandler.h"
#include "EmployeeManagement.h"
#include "Experience.h"
#include "Fresher.h"
#include "Intern.h"
#include <memory>


// Constructor for EmployeeManagement
EmployeeManagement::EmployeeManagement() {}

// Destructor for EmployeeManagement
EmployeeManagement::~EmployeeManagement() {}

// Add a new employee with exception handling
void EmployeeManagement::addEmployee() {
    Employee* ptr;
    std::string id, fullname, birthday, phone, email;
    int employeetype;

    // Input employee ID (no validation required for ID)
    do{
        id = InputHandler::getValidatedInput("Enter student ID: ", Validator::validateID);
    }while(EmployeeManagement::validID(id));
    
    // Input and validate Full Name
    fullname = InputHandler::getValidatedInput("Enter Full Name: ", Validator::validateFullName);

    // Input and validate Birth Day
    birthday = InputHandler::getValidatedInput("Enter Birth Day (YYYY-MM-DD): ", Validator::validateBirthDay);

    // Input and validate Phone
    phone = InputHandler::getValidatedInput("Enter Phone: ", Validator::validatePhone);

    // Input and validate Email
    email = InputHandler::getValidatedInput("Enter Email: ", Validator::validateEmail);

    employeetype = InputHandler::getValidatedIntInputRange("Enter Employee Type (0: Experience, 1: Fresher, 2: Intern): ",Validator::IntRange,0,2);

    // Handle employee type-specific data
    if (employeetype == 0) { // Experience employee
        std::string proskill =InputHandler::getValidatedInput("Enter Proskill: ",Validator::validProskill);
        int expinyear = InputHandler::getValidatedIntInputRange("How many years of experience: ",Validator::IntRange,0,30);

        // Create Experience object
        ptr = new Experience(id, fullname, birthday, phone, email, employeetype, expinyear, proskill);

    } else if (employeetype == 1) { // Fresher employee
        std::string graduationDate, graduationRank, education;

        // Input and validate graduation date
        graduationDate = InputHandler::getValidatedInput("Enter graduation date (YYYY-MM-DD): ", Validator::validateBirthDay);

        // Input graduation rank
        graduationRank = InputHandler::getValidatedInput("Enter graduation rank(Excellent/very good/good/average): ",Validator::validGradeLevel);

        // Input education level
        education = InputHandler::getValidatedInput("Enter education level (e.g., Bachelor, Master, etc.): ",Validator::validEducationLevel);
        // Create Fresher object
        ptr = new Fresher(id, fullname, birthday, phone, email, employeetype, graduationDate, graduationRank, education);

    } else if (employeetype == 2) { // Intern employee
        std::string majors, semester, universityName;

        // Input major
        majors=InputHandler::getValidatedInput("Enter your current major: \nCS(Computer Science)\nIT(Information Technology)\nME(Mechanical Engineering),",Validator::validMajor);

        // Input semester
        semester = InputHandler::getValidatedInput("Enter your current semester (e.g., Semester 1, Semester 2, ...):",Validator::validSemester);

        // Input university name
        universityName = InputHandler::getValidatedInput("Enter your university name(must be end with \"University\"): ",Validator::validUniversity);

        // Create Intern object
        ptr = new Intern(id, fullname, birthday, phone, email, employeetype, majors, semester, universityName);

    } else { // Invalid employee type
        std::cout << "Invalid type !!!!" << std::endl;
        return;
    }

    // Input certificates for the employee
    int number = InputHandler::getValidatedIntInputRange("How many certificates you have: ",Validator::IntRange,0,2);
    for (int i = 0; i < number; i++) {
        ptr->addCertificate();
    }

    // Add employee to the list
    EmployeeList.push_back(ptr);
}

// Update employee information with exception handling
void EmployeeManagement::changeInfor(std::string Id) {
    int option, employee_type;
    std::string parameter;

    // Iterate through the employee list to find the matching ID
    for (auto& it : EmployeeList) {
        if (it->get_Id() == Id) {
            std::cout << "Which information do you want to change?\n";
            std::cout << "1. ID\n";
            std::cout << "2. Fullname\n";
            std::cout << "3. BirthDay\n";
            std::cout << "4. Phone\n";
            std::cout << "5. Email\n";
            std::cout << "6. Employee_type\n";
            std::cin >> option;
            std::cin.ignore();

            try {
                // Handle user selection
                switch (option) {
                    case 1: // Change ID
                        do{
                            parameter = InputHandler::getValidatedInput("Enter new student ID: ", Validator::validateID);
                        }while(EmployeeManagement::validID(parameter));
                        it->set_ID(parameter);
                        break;
                    case 2: // Change Full Name
                        parameter = InputHandler::getValidatedInput("Enter new Full Name: ", Validator::validateFullName);
                        it->set_Fullname(parameter);
                        break;
                    case 3: // Change Birthday
                        parameter = InputHandler::getValidatedInput("Enter new Birthday (YYYY-MM-DD): ", Validator::validateBirthDay);
                        it->set_Birthday(parameter);
                        break;
                    case 4: // Change Phone
                        parameter = InputHandler::getValidatedInput("Enter new Phone: ", Validator::validatePhone);
                        it->set_Phone(parameter);
                        break;
                    case 5: // Change Email
                        parameter = InputHandler::getValidatedInput("Enter new Email: ", Validator::validateEmail);
                        it->set_Email(parameter);
                        break;
                    case 6: // Change Employee Type
                        std::cout << "Enter new Employee type: ";
                        std::cin >> employee_type;
                        it->set_EmployeeType(employee_type);
                        break;
                    default: // Invalid option
                        std::cerr << "Invalid option!!!\n";
                }
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << "\n";
            }
        }
        else{
            std::cout <<"This student ID doesnot exit!!";
        }
    }
}

// Delete an employee based on ID
void EmployeeManagement::Delete(std::string Id) {
        bool found = false;
        for (auto it = EmployeeList.begin(); it != EmployeeList.end();) {
            if ((*it)->get_Id() == Id) {
                delete *it; // Free memory
                it = EmployeeList.erase(it); // Remove from list
                found = true;
            } else {
                ++it;
            }
        }
        if (!found) {
            std::cout << "ID not exist: " << Id << std::endl;
        }
    }


// Find and display all Intern employees
void EmployeeManagement::findIntern() {
    for (auto& it : EmployeeList) {
        if (it->get_Employee_type() == 2) {
            it->showMe();
        }
    }
}

// Find and display all Fresher employees
void EmployeeManagement::findFresher() {
    for (auto& it : EmployeeList) {
        if (it->get_Employee_type() == 1) {
            it->showMe();
        }
    }
}

// Find and display all Experience employees
void EmployeeManagement::findExperience() {
    for (auto& it : EmployeeList) {
        if (it->get_Employee_type() == 0) {
            it->showMe();
        }
    }
}

// Display all employees
void EmployeeManagement::showAll() {
    for (auto& it : EmployeeList) {
        it->showMe();
    }
}

bool EmployeeManagement::validID(std::string ID) {
    for (const auto& it : EmployeeList) {
        if (ID == it->get_Id()) {
            std::cout << "This ID already exists! Please enter a different ID.\n";
            return true; // ID is a duplicate
        }
    }
    return false; // ID is unique
}