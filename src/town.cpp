#include "town.h"
#include <string>
#include <iostream>

using namespace std;

Town::Town(string name, int population)
{
    cout << "Town Constructor" << std::endl;
    this->name = name;
    this->population = population;
    this->reputation = 100;
    this->influence = 100;
    this->recruits = 0;
}

Town::Town()
{
    cout << "Town Constructor" << std::endl;
    this->name = "Default Town Name";
    this->population = 0;
    this->reputation = 100;
    this->influence = 100;
    this->recruits = 0;
}

void Town::dothing()
{

    cout << name << "Running" << std::endl;

    cout << "Population: " << population << endl;
    cout << "Reputation: " << reputation << endl;
    cout << "Influence: " << influence << endl;
}
