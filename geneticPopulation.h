//geneticPopulation.h
#pragma once
#include <vector>
#include "routePlanner.h"
#include "traveler.h"
#include "city.h"

class GPOP {
    public:
        GPOP();
        GPOP(int s, std::vector<City> cities);
        int get_fittest_index();
        int get_second_fittest_index();
        int get_least_fittest_index();
        void print();
        std::vector <RoutePlanner> entities;
    private:
        int size;
        int fittest;
};