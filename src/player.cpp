#include "player.h"

double Player::get_balance()
{
    return balance;
}

bool Player::set_balance(double amount)
{
    if (amount > 0)
    {
        balance = balance + amount;
        return true;
    }
    return false;
}
