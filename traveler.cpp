//traveler.cpp
#include "traveler.h"

void Traveler::add_city(City city) {
    destinations.push_back(city);
}

void Traveler::set_cities(std::vector<City> cities) {
    destinations.clear();
    destinations = cities;
}

City Traveler::get_city(int i) {
    return destinations[i];
}

std::vector<City> Traveler::get_cities() {
    return destinations;
}

int Traveler::cities() {
    return destinations.size();
}