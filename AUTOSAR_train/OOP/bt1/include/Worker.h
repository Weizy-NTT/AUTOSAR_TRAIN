#ifndef WORKER_H
#define WORKER_H

#include "Staff.h"

class Worker : public Staff {
private:
    int Level;

public:
    Worker(int level, std::string name, int old, std::string gen, std::string address);
    void print_inf() override;
};

#endif // WORKER_H
