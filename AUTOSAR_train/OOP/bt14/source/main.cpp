#include "GoodStudent.h"
#include "NormalStudent.h"
#include "RecruimentSystem.h"
#include "Student.h"
#include "InputHandler.h"
#include "StudentValidator.h"

#define ADD 1
#define RECRUIT 2
#define DISPLAY 3
#define EXIT 4

int main() {
    RecruitmentSystem system;

    std::cout << "Welcome to the Recruitment System!!!" << std::endl;
    int choice;

    do {
        std::cout << "\n========== MENU ==========" << std::endl;
        std::cout << "1. Press 1 to add a student" << std::endl;
        std::cout << "2. Press 2 to recruit students" << std::endl;
        std::cout << "3. Press 3 to display all students in the list" << std::endl;
        std::cout << "4. Press 4 to exit" << std::endl;
        std::cout << "===========================" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case ADD: { // Add a student
            
                std::string fullName, doB, sex, phoneNumber, universityName, gradeLevel;
                fullName = InputHandler::getValidatedInput("Enter student full name: ",StudentValidator::validateFullName);
                doB = InputHandler::getValidatedInput("Enter student date of birth(YYYY-MM-DD): ",StudentValidator::validateDOB);
                sex = InputHandler::getValidatedInput("Enter student gender(MALE/FEMALE): ",StudentValidator::validSex);
                phoneNumber = InputHandler::getValidatedInput("Enter student phone number: ",StudentValidator::validatePhoneNumber);
                universityName = InputHandler::getValidatedInput("Enter student University (end with university): ",StudentValidator::validUniversityName);
                gradeLevel = InputHandler::getValidatedInput("Enter student grade level(excellent/very good/ good/ average): ",StudentValidator::validGradeLevel);
                int studentType = InputHandler::getValidatedIntInput("Enter student type (1: GoodStudent, 2: NormalStudent): ",StudentValidator::validateIntRange);

                if (studentType == 1) { // GoodStudent
                    float gpa = InputHandler::getValidatedFloatInput("Enter GPA: ", StudentValidator::validateFloatPositive);
                    std::string bestRewardName = InputHandler::getValidatedInput("Enter the name of the best reward(must be got /Award/ at the end) ", StudentValidator::validBestRewardName);
                    system.addStudent(new GoodStudent(fullName, doB, sex, phoneNumber, universityName, gradeLevel, gpa, bestRewardName));
                } else if (studentType == 2) { // NormalStudent
                    float englishScore = InputHandler::getValidatedFloatInput("Enter English score: ", StudentValidator::validateFloatPositive);
                    float entryTestScore =InputHandler::getValidatedFloatInput("Enter entry score: ", StudentValidator::validateFloatPositive);
                    system.addStudent(new NormalStudent(fullName, doB, sex, phoneNumber, universityName, gradeLevel, englishScore, entryTestScore));
                } else {
                    std::cout << "Invalid student type! Please try again." << std::endl;
                }
                break;
            }

            case RECRUIT: { // Recruit students
                int numOfRecruitments = InputHandler::getValidatedIntInputRange("Enter the number of students to recruit (min 11, max 15): ",StudentValidator::IntRange,11,15);
                system.recruitCandidates(numOfRecruitments);
                break;
            }

            case DISPLAY: { // Display all students
                system.showAllStudents();
                break;
            }

            case EXIT: { // Exit program
                std::cout << "Exiting the system. Goodbye!" << std::endl;
                break;
            }

            default: {
                std::cout << "Invalid choice! Please try again." << std::endl;
                break;
            }
        }
    } while (choice != 4);

    return 0;
}