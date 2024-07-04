#include "player.h"

using namespace std;

double Player::get_balance()
{
    return balance;
}

void Player::set_balance(int amount)
{
    if (amount > 0)
    {
        balance = amount;
    }
}
