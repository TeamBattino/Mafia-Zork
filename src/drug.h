#pragma once
#include <string>

using namespace std;

class Drug
{
public:
    string name;
    int quantity;
    float purchase_price;
    float sale_price;
    Drug(string name, int quantity, float purchase_price, float sale_price);
};