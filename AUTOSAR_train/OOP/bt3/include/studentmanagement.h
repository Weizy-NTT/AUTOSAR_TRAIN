#ifndef STUDENTMANAGEMENT_H
#define STUDENTMANAGEMENT_H

#include <vector>
#include <memory>
#include "student.h"

class StudentManagement {
private:
    std::vector<std::shared_ptr<Student>> Student_management;

public:
    void add_newmember();
    void show_infor() const;
    void find(const std::string& registernumber) const;
};
#endif // STUDENTMANAGEMENT_H