#include <vector>
#include <iostream>
#include "geneticPopulation.h"
#include "routePlanner.h"
#include "traveler.h"
#include "city.h"

GPOP::GPOP() {
    
}

GPOP::GPOP(int s, std::vector<City> cities) {
    size = s;
    for (int i = 0; i < size; i++) {
        Traveler temp_traveler;
        temp_traveler.set_cities(cities);
        RoutePlanner temp = RoutePlanner(temp_traveler.get_cities(), temp_traveler);
        temp.generate_route();
        entities.push_back(temp);
    }
}

int GPOP::get_fittest_index() {
    int best = entities[0].get_distance();
    int best_index = 0;

    for(int i = 0; i < entities.size(); i++) {
        if (best >= entities[i].get_distance()) {
            best = entities[i].get_distance();
            best_index = i;
        }
    }
    fittest = entities[best_index].get_distance();
    return best_index;
}

int GPOP::get_second_fittest_index() {
    int best = entities[0].get_distance();
    int best_index = 0;

    for(int i = 0; i < entities.size(); i++) {
        if (best >= entities[i].get_distance()) {
            best = entities[i].get_distance();
            best_index = i;
        }
    }
    return best_index;
}

int GPOP::get_least_fittest_index() {
    int worst = entities[0].get_distance();
    int worst_index = 0;

    for(int i = 0; i < entities.size(); i++) {
        if (worst <= entities[i].get_distance()) {
            worst = entities[i].get_distance();
            worst_index = i;
        }
    }
    return worst_index;
}

void GPOP::print() {
    std::cout << "[ ";
    for (int i = 0; i < entities.size(); i++) {
        std::cout << std::to_string(entities[i].get_distance()) << ", ";
    }
    std::cout << "]" << std::endl;
}