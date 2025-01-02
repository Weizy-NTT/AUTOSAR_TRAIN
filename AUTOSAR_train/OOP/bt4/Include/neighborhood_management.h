#ifndef NEIGHBORHOOD_MANAGEMENT_H
#define NEIGHBORHOOD_MANAGEMENT_H

#include <vector>
#include "household.h"

class NeighborManagement {
private:
    std::vector<Household> NeighManage; // Vector of Household objects

public:
    NeighborManagement() = default;
    void add_neighboor(const Household& household); // Add by reference
    void show_neighboor();
};

#endif
