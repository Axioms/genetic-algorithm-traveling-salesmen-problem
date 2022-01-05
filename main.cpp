// main.cpp
#include <iostream>
#include <chrono>
#include <vector>
#include "routePlanner.h"
#include "traveler.h"
#include "city.h"
#include "geneticPopulation.h"
#include "geneticAlgorithm.h"
#include "routePlannerSimulatedAnnealing.h"

void print_cities(std::vector<City> cities) {
    std::cout << "start -> "; 
    for(int i=0; i < cities.size(); i++){
        std::cout << cities[i].city_cords_to_string() << " -> ";
    }
    std::cout << "end" << std::endl;
}

void test(int cities_len) {
    std::cout << "testing The Traveling sales man problem 10 times with the same " << cities_len << " cities" << std::endl;

    RPSA aaaa = RPSA(cities_len);
    std::vector<City> cities_list = aaaa.get_cities();
    Traveler temp_travler;
    temp_travler.set_cities(cities_list);
    RoutePlanner temp_route_planner = RoutePlanner(temp_travler);
    std::cout << "starting distance is: " << std::to_string(temp_route_planner.get_distance()) << std::endl;
    std::cout << "staring route is: ";
    print_cities(cities_list);

    std::cout << "starting test" << std::endl;
    std::cout << "genetic algorithm has a inital population of 100 and 100 generations" << std::endl << std::endl;

    for(int i = 0; i < 10; i++ ) {
        GA bbbb = GA(100, cities_list, 100);
        auto start = std::chrono::high_resolution_clock::now();
        bbbb.run_ga();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        std::cout << "genetic algorithm took " << duration.count() << "μs for run #" << i+1 << std::endl << std::endl;

        RPSA cccc = RPSA(cities_len);

        start = std::chrono::high_resolution_clock::now();
        cccc.set_cities(cities_list);
        cccc.run_sa();
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        std::cout << "simulated annealing took " << duration.count() << "μs for run #" << i+1 << std::endl << std::endl << std::endl;
    }
}

int main()
{
    // init random
    srand(time(NULL));
    test(10);
    test(100);
    test(1000);
    test(10000);
    
    return 0;
}