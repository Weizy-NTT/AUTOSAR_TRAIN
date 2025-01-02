#include "Staff.h"

Staff::Staff(std::string name, int old, std::string gen, std::string address)
    : Name(name), Old(old), Gen(gen), Address(address) {}

std::string Staff::get_name() {
    return Name;
}

int Staff::get_old() {
    return Old;
}

std::string Staff::get_gen() {
    return Gen;
}

std::string Staff::get_address() {
    return Address;
}
