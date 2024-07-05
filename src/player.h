#pragma once

class Player
{
public:
    // Getters & Setter
    double get_balance();

    bool set_balance(double amount);

private:
    double balance = 100;
};
