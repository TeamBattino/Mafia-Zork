#pragma once

class Player
{
public:
    // Constructors
    Player();

    // Getters
    double get_balance();

    bool set_balance(int amount);

private:
    double balance = 100;
};
