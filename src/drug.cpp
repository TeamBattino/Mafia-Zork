#include "drug.h"
#include <string>

using namespace std;

Drug::Drug(string name, int quantity, float purchase_price, float sale_price)
{
    this->name = name;
    this->quantity = quantity;
    this->purchase_price = purchase_price;
    this->sale_price = sale_price;
};