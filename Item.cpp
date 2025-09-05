#include "Item.h"

Item::Item(int price, string name)
{
	this->price = price;
	this->name = name;
}

int Item::getPrice() const
{
	return price;
}

string Item::getName() const
{
	return name;
}
