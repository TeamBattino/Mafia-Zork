#pragma once
#include <string>

using namespace std;
class Town
{
private:
    void handleCommand();

public:
    string name;
    int population;
    int reputation;
    int influence;
    int recruits;
    Town();
    Town(string name, int population);
    void dothing();
};