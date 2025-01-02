#include "School.h"
#include "Student.h"

#define ADD 1
#define DISPLAY 2
#define SHOW 3
#define EXIT 4
School School_obj;
int main(){
    int option;
    do {
    
    cout<<"1. Add new student"<<endl;
    cout<<"2. Display student have 20 age"<<endl;
    cout<<"3. Show the number of students got 23 age and Da Nang hometown "<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Enter your option: ";
    cin>>option;
    cin.ignore();
    string name, hometown, class_v;
    unsigned age;

    switch (option) {
        case ADD: {
            // Input details for a new student
            cout << "Enter your name: ";
            getline(cin, name);

            cout << "Enter your age: ";
            cin >> age;
            cin.ignore(); // Clear the newline from input buffer

            cout << "Enter your hometown: ";
            getline(cin, hometown);

            cout << "Enter your class: ";
            getline(cin, class_v);

            // Create a unique_ptr for the new student and add to school
            auto student = std::make_unique<Student>(name, age, hometown, class_v);
            School_obj.add_student(std::move(student));
            break;
        }


        case DISPLAY:{
            // Show students older than 20 years
            School_obj.show_student_20_old();
            break;
        }
        case SHOW:{
            // Show the total number of students
            School_obj.show_number();
            break;
        }
        case EXIT:
            // Exit the loop
            break;

        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        cin>>option;
    cin.ignore();
    }
} while (option != EXIT);

}
