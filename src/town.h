#pragma once
#include "drug.h"
#include <string>
#include <vector>

using namespace std;
class Town
{
private:
    void handleCommand();

public:
    vector<Drug> local_drugs;
    string name;
    int population;
    int reputation;
    int influence;
    int recruits;
    Town();
    Town(string name, int population, vector<Drug> local_drugs);
    void dothing();
};