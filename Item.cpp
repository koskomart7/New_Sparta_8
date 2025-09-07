#include "Item.h"

Item::Item()
{
	this->price = 0;
	this->name = "";
}

Item::~Item()
{
}

int Item::getPrice() const
{
	return price;
}

string Item::getName() const
{
	return name;
}

void Item::setPrice(int price)
{
	this->price = price;
}

void Item::setName(string name)
{
	this->name = name;
}