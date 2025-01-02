#ifndef RECRUITMENTSYSTEM_H
#define RECRUITMENTSYSTEM_H

#include <vector>
#include "GoodStudent.h"
#include "NormalStudent.h"
#include <stdexcept>
#include <algorithm>

class RecruitmentSystem {
private:
    std::vector<Student*> students;

public:
    ~RecruitmentSystem();

    void addStudent(Student* student);
    void showAllStudents() const;
    void recruitCandidates(size_t numOfRecruitments);
    
};

#endif // RECRUITMENTSYSTEM_H
