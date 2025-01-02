#include "neighborhood_management.h"
#include <iostream>
using namespace std;

void NeighborManagement::add_neighboor(const Household& household) {
    NeighManage.push_back(household);
}

void NeighborManagement::show_neighboor() {
    for (const auto& household : NeighManage) {
        household.show_infor();
    }
}
