#include "Engineer.h"

Engineer::Engineer(std::string field, std::string name, int old, std::string gen, std::string address)
    : Staff(name, old, gen, address), Field(field) {}

void Engineer::print_inf() {
    std::cout << "Name : " << get_name() << std::endl;
    std::cout << "Old : " << get_old() << std::endl;
    std::cout << "Gen : " << get_gen() << std::endl;
    std::cout << "Address : " << get_address() << std::endl;
    std::cout << "Field : " << Field << std::endl;
}
