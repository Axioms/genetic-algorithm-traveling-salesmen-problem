//geneticAlgorithm.h
#pragma once
#include "geneticPopulation.h"
#include "routePlanner.h"
#include "traveler.h"
#include "city.h"

class GA {
    public:
        GA(int s, std::vector<City> cities, int g);
        void run_ga();
    private:
        void selection();
        void crossover();
        void mutation();
        int get_firrest_offspring();
        void add_fittest_offspring();

        int generation;
        int generations;
        int size;
        int fittest_index;
        int second_fittest_index;
        GPOP population;


};