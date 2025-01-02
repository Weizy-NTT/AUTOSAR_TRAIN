#include "School.h"


void School::addFaculty(const std::string& facultyName) {
    faculties.emplace_back(facultyName);
    std::cout << "Faculty \"" << facultyName << "\" added successfully!" << std::endl;
}
School::School(const std::string& name) : schoolName(name) {}


void School::showAllFaculties(){
    for(auto &it : faculties){
        it.showInfor();
    }
}

int School::getTotalRegularStudents(){
    int sum =0;
    for (auto &it : faculties){
        sum = sum + it.getRegularStudentCount();
    }
    return sum;
}

void School::findHighestEntryScoreStudent(){
    for (auto &it : faculties){
        std::cout<<"Top entry score in "<<it.getFacultyName()<<" Faculty"<<std::endl;
        it.findTopEntryScore();
    }
}

std::vector<Student*> School::findPartTimeStudentsByLocation() {
    std::vector<Student*> result;
    std::string facultyName = InputHandler::getValidatedInput("Enter the name of the faculty(It must start with \"Faculty of\"): ",Validator::validFaculty);

    // Find the specified faculty
    for (auto& faculty : faculties) {
        if (faculty.getFacultyName() == facultyName) {
            std::string location = InputHandler::getValidatedInput("Enter Training Location: ",Validator::validLocation);
            // Get part-time students at the specified location
            result = faculty.findPartTimeStudentsByLocationInFaculty(location);

            // Display the results
            if (result.empty()) {
                std::cout << "No part-time students found at location \"" << location 
                          << "\" in faculty \"" << facultyName << "\"." << std::endl;
            } else {
                std::cout << "Part-time students at location \"" << location 
                          << "\" in faculty \"" << facultyName << "\":" << std::endl;
                for (const auto& student : result) {
                    student->showInfor();
                }
            }
            break;
        }
    }

    if (result.empty()) {
        std::cout << "Faculty \"" << facultyName << "\" not found." << std::endl;
    }

    return result;
}

std::vector<Student*> School::findHighestGPAStudent() {
    std::vector<Student*> result;
    for (auto& faculty : faculties) {
        Student* student = faculty.findHighestStudent();
        if (student) {
            result.push_back(student);
        }
    }
    return result;
}

void School::sort (){
    for( auto &it : faculties){
        it.sortStudents();
    }
}

void School::displayStatisticsForAllFaculties() const {
    if (faculties.empty()) {
        std::cout << "No faculties in school \"" << schoolName << "\"." << std::endl;
        return;
    }

    std::cout << "Statistics by year for all faculties in school \"" << schoolName << "\":" << std::endl;

  
    for (const auto& faculty : faculties) {
        faculty.displayStatisticsByYear(); 
        std::cout << "--------------------------------------" << std::endl;
    }
}

 std::vector<Faculty>& School::getFaculties()  {
    return faculties;
}

