#pragma once
#include <vector>
#include "town.h"
#include "player.h"
#include "drug.h"
#include <string>
class Game
{
private:
    // Members
    vector<Town> towns;
    Player player;
    int active_town = 0;

    // Print Functions
    bool random_by_chance(int chance);
    void handle_base_command(string command);
    void print_stock();

public:
    // Constructor
    Game();

    // Functions
    void process_round();
    void print_stats();
    void print_help();
    void print_ascend();

    void run();
    string get_command();
    void recruit();
    void recruit_bribe(int amount);
    void recruit_force();
    void buy_drug(string drug_name, int amount);
    void sell_drug(string drug_name, int amount);
};