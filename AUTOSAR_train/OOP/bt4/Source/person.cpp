#include "person.h"
#include <iostream>
using namespace std;

Person::Person(std::string name, unsigned char old, std::string job, std::string id)
    : Name(name), Old(old), Job(job), ID(id) {}

void Person::show_info() const {
    cout << "Name: " << Name << ", Age: " << (int)Old
         << ", Job: " << Job << ", ID: " << ID << endl;
}
