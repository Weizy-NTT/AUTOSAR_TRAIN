#ifndef ENGINEER_H
#define ENGINEER_H

#include "Staff.h"

class Engineer : public Staff {
private:
    std::string Field;

public:
    Engineer(std::string field, std::string name, int old, std::string gen, std::string address);
    void print_inf() override;
};

#endif // ENGINEER_H
