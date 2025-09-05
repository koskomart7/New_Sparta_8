#include "Item.h"

Item::Item()
{
	this->price = 0;
	this->name = "";
}

int Item::getPrice() const
{
	return price;
}

string Item::getName() const
{
	return name;
}
