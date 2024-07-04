#pragma once

class Player
{
public:
    double get_balance();

    bool set_balance(int amount);

private:
    double balance = 100;
};
