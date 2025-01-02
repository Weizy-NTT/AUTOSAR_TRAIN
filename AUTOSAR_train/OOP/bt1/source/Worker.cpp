#include "Worker.h"

Worker::Worker(int level, std::string name, int old, std::string gen, std::string address)
    : Staff(name, old, gen, address), Level(level) {}

void Worker::print_inf() {
    std::cout << "Name : " << get_name() << std::endl;
    std::cout << "Old : " << get_old() << std::endl;
    std::cout << "Gen : " << get_gen() << std::endl;
    std::cout << "Address : " << get_address() << std::endl;
    std::cout << "Level : " << Level << std::endl;
}
