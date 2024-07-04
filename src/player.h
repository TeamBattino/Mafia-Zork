#pragma once

class Player
{
public:
    // Getters & Setter
    double get_balance();

    bool set_balance(int amount);

private:
    double balance = 100;
};
