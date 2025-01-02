#include "household.h"
#include <iostream>
using namespace std;

Household::Household(std::string housenumber) : HouseNumber(housenumber) {}

void Household::add_member(const Person& person) {
    Persons.push_back(person);
    MemberNumber = Persons.size();
}

void Household::show_infor() const { // Ensure the method is const
    cout << "House Number: " << HouseNumber << ", Members: " << (int)MemberNumber << endl;
    for (const auto& person : Persons) {
        person.show_info();
    }
}
