#pragma once
#include "town.h"
#include <vector>
#include "player.h"

using namespace std;
class Game
{
private:
    vector<Town> towns;
    int active_town = 0;
    Player player;

public:
    Game();
    void run();
};