#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
private:
    std::string Name;
    unsigned char Old;
    std::string Job;
    std::string ID;

public:
    Person() = default;
    Person(std::string name, unsigned char old, std::string job, std::string id);
    void show_info() const;
};

#endif
