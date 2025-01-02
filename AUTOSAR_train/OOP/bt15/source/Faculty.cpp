#include"Faculty.h"
#include <algorithm>
Faculty::Faculty(const std::string& name) : facultyName(name) {}

void Faculty::addStudent() {
    int studentType = InputHandler::getValidatedIntInputRange("Enter the type of student to add (1 - Regular, 2 - Part-Time): ",Validator::IntRange,1,2);

    // Variables to store student information
    std::string id, name, dob, location;
    int admissionYear;
    double entryScore;

    // Input basic student details
    id=InputHandler::getValidatedInput("Enter Student ID: ",Validator::validateID);
    name = InputHandler::getValidatedInput("Enter Full Name: ",Validator::validateFullName);
    dob = InputHandler::getValidatedInput("Enter Date of Birth (YYYY-MM-DD): ", Validator::validateDOB);
    admissionYear = InputHandler::getValidatedIntInputRange("Enter Admission Year: ",Validator::IntRange,1900,2025);
    entryScore = InputHandler::getValidatedDoubleInput("Enter Entry Score: ",Validator::validateDoublePositive);

    // Create a unique_ptr for the new student
    std::unique_ptr<Student> newStudent;

    // Check the type of student to create
    if (studentType == 1) {
        // Create a RegularStudent and store it in newStudent
        newStudent = std::make_unique<RegularStudent>(id, name, dob, admissionYear, entryScore);
    } else if (studentType == 2) {
        // Input additional details for PartTimeStudent
        location = InputHandler::getValidatedInput("Enter Training Location: ",Validator::validLocation);

        // Create a PartTimeStudent and store it in newStudent
        newStudent = std::make_unique<PartTimeStudent>(id, name, dob, admissionYear, entryScore, location);
    } else {
        // Handle invalid input for student type
        std::cerr << "Invalid student type selected!" << std::endl;
        return;
    }

    // Input study results
    int numResults = InputHandler::getValidatedIntInputRange("Enter the number of study results: ",Validator::IntRange,0,12);
    if(numResults ==0){
        newStudent->addStudyResult(0, 0);
    }

    for (int i = 0; i < numResults; ++i) {
        std::string semesterName = InputHandler::getValidatedInput("Enter Semester Name with format \"Semester \" followed by alphanumeric characters only ",Validator::validSemesterName);
        double semesterAverage = InputHandler::getValidatedDoubleInput("Enter Semester Average: ",Validator::validateDoublePositive);
        newStudent->addStudyResult(semesterName, semesterAverage);
    }

    // Add the new student to the students vector
    students.push_back(std::move(newStudent));
    std::cout << "Student added successfully!" << std::endl;
}

int Faculty::getRegularStudentCount() {
    int regularCount = 0;
    for (const auto& it : students) {
        if (dynamic_cast<RegularStudent*>(it.get())) {
            regularCount++;
        }
    }
    return regularCount;
}

void Faculty::defineRegularStudent(std::string ID){
    int checkRegularStudent = 0;
    for (auto &it : students){
        if(it->getStudentID() == ID&& dynamic_cast<RegularStudent*>(it.get())!= NULL){
            checkRegularStudent = 1;
        }
    }
    if (checkRegularStudent ==1){
        std::cout<<"It is regulr student"<<std::endl;
    }
    else{
        std::cout<<"It is not regulr student"<<std::endl;
    }
}

void Faculty::showInfor(){
    if (students.empty()) {
        std::cout << "No students in faculty \"" << facultyName << "\"." << std::endl;
        return;
    }

    std::cout << "Faculty: " << facultyName << std::endl;
    std::cout << "Number of students: " << students.size() << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    for (const auto& student : students) {
        if (student) {
            student->showInfor(); // Gọi phương thức showInfo() của mỗi sinh viên
        }
    }
    std::cout << "--------------------------------------" << std::endl;
}

void Faculty::findTopEntryScore() {
    if (students.empty()) {
        std::cout << "No students in faculty \"" << facultyName << "\"." << std::endl;
        return;
    }

    Student* topStudent = nullptr;
    double highestScore = 0.0;

    for (const auto& it : students) {
        if (it->getEntryScore() > highestScore) {
            highestScore = it->getEntryScore();
            topStudent = it.get();
        }
    }

    if (topStudent) {
        std::cout << "Top Entry Score Student in Faculty \"" << facultyName << "\":" << std::endl;
        topStudent->showInfor(); 
        std::cout << "Entry Score: " << highestScore << std::endl;
    }
}

std::string Faculty::getFacultyName()const{
    return facultyName;
}


std::vector<Student*> Faculty::findPartTimeStudentsByLocationInFaculty (const std::string& location){
    std::vector<Student*> studentList;
    for (const auto& student : students) {
        if (auto* partTime = dynamic_cast<PartTimeStudent*>(student.get())) {
            if (partTime->get_Location() == location) {
                    studentList.push_back(partTime);
            }
        }
    }

    return studentList;
}

Student* Faculty::findHighestStudent() {
    Student* topStudent = nullptr; 
    double highestAverage = 0.0;   

    for (const auto& student : students) {
        
        std::vector<StudyResult> studyResults = student->getStudyResult();

        double maxAverage = 0.0;
        for (const auto& result : studyResults) {
            if (result.getSemesterAverage() > maxAverage) {
                maxAverage = result.getSemesterAverage();
            }
        }

        if (maxAverage > highestAverage) {
            highestAverage = maxAverage;
            topStudent = student.get(); 
        }
    }

    return topStudent; 
}

void Faculty::sortStudents() {
    std::sort(students.begin(), students.end(), [](const std::unique_ptr<Student>& a, const std::unique_ptr<Student>& b) {
        
        bool isARegular = dynamic_cast<RegularStudent*>(a.get()) != nullptr;
        bool isBRegular = dynamic_cast<RegularStudent*>(b.get()) != nullptr;

        if (isARegular != isBRegular) {
            return isARegular; // RegularStudent xếp trước PartTimeStudent
        }

        return a->getAdmissionYear() > b->getAdmissionYear();
    });
}

std::map<int, int> Faculty::getStatisticsByYear() const{
    std::map<int, int> yearStatistics;
    for (const auto& student : students) {
        int admissionYear = student->getAdmissionYear(); // Lấy năm vào học
        yearStatistics[admissionYear]++; // Tăng số lượng sinh viên cho năm tương ứng
    }

    return yearStatistics;
}

void Faculty::displayStatisticsByYear() const {
    auto statistics = getStatisticsByYear();

    std::cout << "Statistics by year for Faculty \"" << facultyName << "\":" << std::endl;
    for (const auto& entry : statistics) {
        std::cout << "Year " << entry.first << ": " << entry.second << " students" << std::endl;
    }
}

const std::vector<std::unique_ptr<Student>>& Faculty::getStudents() const {
    return students;
}

std::vector<Student*> Faculty::findHighGPAStudentsInLastSemester(const std::vector<std::unique_ptr<Student>>& students, double minGpa) const {
    std::vector<Student*> result;

    for (const auto& student : students) {
        const auto& studyResults = student->getStudyResult();
        if (!studyResults.empty() && studyResults.back().getSemesterAverage() >= minGpa) {
            result.push_back(student.get()); // Use raw pointer
        }
    }

    return result;
}