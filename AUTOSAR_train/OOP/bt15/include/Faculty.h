#ifndef FACULTY_H
#define FACULTY_H

#include "RegularStudent.h"
#include "PartTimeStudent.h"
#include "InputHandler.h"
#include "InputValidate.h"
#include <vector>
#include <memory>
#include <map>

class Faculty {
private:
    std::string facultyName;
    std::vector<std::unique_ptr<Student>> students;

public:
    Faculty(const std::string& name);
    const std::vector<std::unique_ptr<Student>>& getStudents() const;
    std::string getFacultyName() const ;
    
    void addStudent();
    int getRegularStudentCount();
    void defineRegularStudent(std::string ID);
    void showInfor();
    void findTopEntryScore();
    std::vector<Student*> findPartTimeStudentsByLocationInFaculty(const std::string& location);
    Student * findHighestStudent();
    void sortStudents();
    std::map<int, int> getStatisticsByYear() const;
    void displayStatisticsByYear() const;
    std::vector<Student*> findHighGPAStudentsInLastSemester(const std::vector<std::unique_ptr<Student>>& students, double minGpa) const;
};

#endif // FACULTY_H
