#include <iostream>
#include "School.h"
#include <limits>
#include "InputHandler.h"
#include "InputValidate.h"

#define ADDFACULTY 1
#define DISPLAYFACLUTY 2
#define ADDSTUDENT 3
#define TOTAL_REGULAR_STUDENT 4
#define FIND_STUDENT_WITH_HIGHEST_ENTRY_SCORE 5
#define GET_LIST_PARTIME_STUDENT_FROM_LOCATION 6
#define GET_STUDENT_WITH_GPA_GREATERTHAN_8 7
#define FIND_STUDENT_WITH_HIGHEST_GPA_EACH_FACULTY 8
#define SORT 9 
#define DISPLAY_BY_FACULTY 10
#define EXIT 0





void displayMenu() {
    std::cout << "========== MENU ==========" << std::endl;
    std::cout << "1. Add a new faculty" << std::endl;
    std::cout << "2. Display all faculties" << std::endl;
    std::cout << "3. Add a student to a faculty" << std::endl;
    std::cout << "4. Get total number of regular students" << std::endl;
    std::cout << "5. Find the student with the highest entry score in each faculty" << std::endl;
    std::cout << "6. Get a list of part-time students by location" << std::endl;
    std::cout << "7. Get students with a GPA of 8.0 or higher in the last semester" << std::endl;
    std::cout << "8. Find the student with the highest average GPA in each faculty" << std::endl;
    std::cout << "9. Sort students in each faculty" << std::endl;
    std::cout << "10. Display statistics of students by admission year" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "==========================" << std::endl;
    std::cout << "Choose an option: ";
}

int main() {
    School school("FPT University");
    int option;

    do {
        displayMenu();
        std::cin >> option;
        std::cin.ignore();
        switch (option) {
            case ADDFACULTY: {
                std::string facultyName = InputHandler::getValidatedInput("Enter the name of the faculty(It must start with \"Faculty of\"): ",Validator::validFaculty);
                school.addFaculty(facultyName);
                break;
            }
            case DISPLAYFACLUTY: {
                school.showAllFaculties();
                break;
            }
            case ADDSTUDENT: {
                std::string facultyName = InputHandler::getValidatedInput("Enter the name of the faculty(It must start with \"Faculty of\"): ",Validator::validFaculty);
                for (auto& faculty : school.getFaculties()) {
                    if (faculty.getFacultyName() == facultyName) {
                        faculty.addStudent();
                    }
                }
                break;
            }
            case TOTAL_REGULAR_STUDENT: {
                std::cout << "Total number of regular students: " << school.getTotalRegularStudents() << std::endl;
                break;
            }
            case FIND_STUDENT_WITH_HIGHEST_ENTRY_SCORE: {
                school.findHighestEntryScoreStudent();
                break;
            }
            case GET_LIST_PARTIME_STUDENT_FROM_LOCATION: {
                school.findPartTimeStudentsByLocation();
                break;
            }
            case GET_STUDENT_WITH_GPA_GREATERTHAN_8: {
                double minGPA = 8.0;
                bool hasStudents = false; 
                for (auto& faculty : school.getFaculties()) {
                    auto students = faculty.findHighGPAStudentsInLastSemester(faculty.getStudents(), minGPA);
                    if (students.empty()) {
                        std::cout << "Faculty " << faculty.getFacultyName() << ": Empty list\n";
                    } else {
                        std::cout << "Faculty " << faculty.getFacultyName() << ":\n";
                        for (const auto& student : students) {
                            student->showInfor();
                            hasStudents = true; 
                        }
                    }
                }
                if (!hasStudents) {
                    std::cout << "No students found with GPA >= " << minGPA << " in the last semester.\n";
                }
                break;
            }
            case FIND_STUDENT_WITH_HIGHEST_GPA_EACH_FACULTY: {
                for(auto &it :school.findHighestGPAStudent()){
                    it->showInfor();
                };
                break;
            }
            case SORT: {
                school.sort();
                break;
            }
            case DISPLAY_BY_FACULTY: {
                school.displayStatisticsForAllFaculties();
                break;
            }
            case EXIT:
                std::cout << "Exiting the program!" << std::endl;
                break;
            default:
                std::cout << "Invalid option. Please try again!" << std::endl;
        }
    } while (option != 0);

    return 0;
}
