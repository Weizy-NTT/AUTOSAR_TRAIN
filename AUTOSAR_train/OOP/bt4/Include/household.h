#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H

#include <iostream>
#include "person.h"
#include <vector>

class Household {
private:
    unsigned char MemberNumber;
    std::string HouseNumber;
    std::vector<Person> Persons; // Vector of Person objects

public:
    Household() = default;
    Household(std::string housenumber);
    void show_infor() const; // Add 'const' here
    void add_member(const Person& person);
};

#endif
