#include "player.h"

using namespace std;

double Player::get_balance()
{
    return balance;
}

double Player::set_balance(int amount){
    if(amount > 0){
        balance = amount;
    }
}

