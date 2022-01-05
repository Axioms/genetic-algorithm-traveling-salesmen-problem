//geneticAlgorithm.cpp
#include <iostream>
#include <vector>
#include <math.h>
#include "geneticPopulation.h"
#include "geneticAlgorithm.h"
#include "routePlanner.h"

GA::GA(int s, std::vector<City> cities, int g) {
    GPOP temp = GPOP(s, cities);
    population = temp;
    generation = 0;
    size = s;
    generations = g;
}

void GA::run_ga() {
    //std::cout << "Generation: " << generation << " Fittest: " + std::to_string(population.entities[population.get_fittest_index()].get_distance()) << std::endl;

    while (generation < generations) {
        generation++;

        selection();
        crossover();

        if (rand()%(size + (size/generations)) < size) {
            mutation();
        }
        add_fittest_offspring();

        //std::cout << "Generation: " << generation << " Fittest: " + std::to_string(population.entities[population.get_fittest_index()].get_distance()) << std::endl;
    }
    std::cout << "Final route distance is: " << std::to_string(population.entities[population.get_fittest_index()].get_distance()) << std::endl;
    std::cout << "Final route is: " << population.entities[population.get_fittest_index()].route_to_string() << std::endl;
}

void GA::selection() {
    fittest_index = population.get_fittest_index();
    second_fittest_index = population.get_second_fittest_index();
}

void GA::crossover() {
    int cross_over_point = (rand() % population.entities.size());
/*     
    City temp = population.entities[fittest_index].get_city(cross_over_point);
    population.entities[fittest_index].set_city(cross_over_point, population.entities[second_fittest_index].get_city(cross_over_point));
    population.entities[second_fittest_index].set_city(cross_over_point, temp);
     */

   for (int i = 0; i < cross_over_point; i++) {
        City temp = population.entities[fittest_index].get_city(i);
        population.entities[fittest_index].set_city(i, population.entities[second_fittest_index].get_city(i));
        population.entities[second_fittest_index].set_city(i, temp);
   }
   
}

void GA::mutation() {
    int cities_len = population.entities[0].get_route().size();
    int mut_point_one = (rand() % cities_len);
    int mut_point_two = (rand() % cities_len);

    while (mut_point_one == mut_point_two) {
        mut_point_two = (rand() % cities_len);
    }

    City temp = population.entities[fittest_index].get_city(mut_point_one);
    population.entities[fittest_index].set_city(mut_point_one, population.entities[fittest_index].get_city(mut_point_two));
    population.entities[fittest_index].set_city(mut_point_two, temp);

    mut_point_one = (rand() % cities_len);
    mut_point_two = (rand() % cities_len);

    while (mut_point_one == mut_point_two) {
        mut_point_two = (rand() % cities_len);
    }

    temp = population.entities[second_fittest_index].get_city(mut_point_one);
    population.entities[second_fittest_index].set_city(mut_point_one, population.entities[second_fittest_index].get_city(mut_point_two));
    population.entities[second_fittest_index].set_city(mut_point_two, temp);
}

int GA::get_firrest_offspring() {
    if (population.entities[fittest_index].get_distance() < population.entities[second_fittest_index].get_distance()) {
        return fittest_index;
    }
    return second_fittest_index;
}

void GA::add_fittest_offspring() {
    //update distance values
    int best_fit_index = population.get_fittest_index();
    int least_fit_index = population.get_least_fittest_index();

    population.entities[least_fit_index] = population.entities[best_fit_index];

}