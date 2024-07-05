#include "town.h"
#include "drug.h"
#include <string>
#include <iostream>

using namespace std;

Town::Town(string name, int population, vector<Drug> local_drugs)
{
    cout << "Town Constructor" << std::endl;
    this->name = name;
    this->population = population;
    this->reputation = 100;
    this->influence = 100;
    this->recruits = 0;
    this->local_drugs = local_drugs;
}

Town::Town()
{
    cout << "Town Constructor" << std::endl;
    this->name = "Default Town Name";
    this->population = 0;
    this->reputation = 100;
    this->influence = 100;
    this->recruits = 0;
    this->local_drugs = {Drug("Dopamine", 50, 100, 0), Drug("Serotonin", 50, 100, 0), Drug("Adrenaline", 50, 100, 0), Drug("Endorphin", 50, 100, 0)};
}

int Town::get_drug_index(const std::string &drug_name)
{
    for (int i = 0; i < local_drugs.size(); i++)
    {
        if (local_drugs[i].name == drug_name)
        {
            return i;
        }
    }
    return -1;
}
