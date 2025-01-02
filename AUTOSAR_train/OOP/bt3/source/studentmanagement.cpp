#include "studentmanagement.h"

void StudentManagement::add_newmember() {
    std::string reg, name, address, grade_s;
    int prior;
    grade grade_v;

    std::cout << "Enter candidate register number: ";
    std::cin >> reg;
    std::cin.ignore();
    std::cout << "Enter candidate name: ";
    std::getline(std::cin, name);
    std::cout << "Enter candidate address: ";
    std::getline(std::cin, address);
    std::cout << "Enter candidate priority level: ";
    std::cin >> prior;
    std::cin.ignore();
    std::cout << "Enter exam group (A, B, or C): ";
    std::getline(std::cin, grade_s);

    if (grade_s == "A") {
        grade_v = A;
    } else if (grade_s == "B") {
        grade_v = B;
    } else if (grade_s == "C") {
        grade_v = C;
    } else {
        std::cout << "Invalid exam group!" << std::endl;
        return;
    }

    std::shared_ptr<Student> ptr = std::make_shared<Student>(reg, name, address, prior, grade_v);
    Student_management.push_back(ptr);
}

void StudentManagement::show_infor() const {
    for (const auto& it : Student_management) {
        it->show_infor();
    }
}

void StudentManagement::find(const std::string& registernumber) const {
    bool Found_check = false;
    for (const auto& it : Student_management) {
        if (it->get_regis() == registernumber) {
            std::cout << "Found" << std::endl;
            it->show_infor();
            Found_check = true;
            break;
        }
    }
    if (!Found_check) {
        std::cout << "Not Found!!!" << std::endl;
    }
}
