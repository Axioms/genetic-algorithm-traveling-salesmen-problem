//traveler.h
#pragma once
#include <vector>
#include "city.h"

class Traveler {
    public:
        void add_city(City city);
        void set_cities(std::vector<City> cities);
        City get_city(int i);
        std::vector<City> get_cities();
        int cities();
    private:
        std::vector<City> destinations;
};