#include "household.h"
#include "neighborhood_management.h"
#include "person.h"

#include <iostream>
using namespace std;

int main() {
    NeighborManagement Neibor;
    int number;
    string housenumber, name, job, id;
    unsigned char old, membernumber;

    cout << "How many neighbors you want to add:" << endl;
    cin >> number;

    for (int i = 0; i < number; i++) {
        cout << "What is this house number: " << endl;
        cin >> housenumber;

        Household household(housenumber);

        cout << "How many persons: " << endl;
        cin >> membernumber;
        cin.ignore(); // Ignore newline character

        for (int j = 0; j < membernumber; j++) {
            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter Age (Old): ";
            cin >> old;
            cin.ignore();

            cout << "Enter Job: ";
            getline(cin, job);

            cout << "Enter ID: ";
            getline(cin, id);

            household.add_member(Person(name, old, job, id));
        }

        Neibor.add_neighboor(household);
    }

    Neibor.show_neighboor();
    return 0;
}
