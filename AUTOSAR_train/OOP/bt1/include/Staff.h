#ifndef STAFF_H
#define STAFF_H

#include <string>
#include <iostream>

class Staff {
private:
    std::string Name;
    int Old;
    std::string Gen;
    std::string Address;

public:
    Staff(std::string name, int old, std::string gen, std::string address);
    virtual ~Staff() = default;

    std::string get_name();
    int get_old();
    std::string get_gen();
    std::string get_address();

    virtual void print_inf() = 0; // Pure virtual function
};

#endif // STAFF_H