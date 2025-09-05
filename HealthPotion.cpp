#include "HealthPotion.h"
#include <iostream>

HealthPotion::HealthPotion(int healthRestore, int price, string name)
{
	this->healthRestore = healthRestore;
	this->price = price;
	this->name = name;
}

void HealthPotion::Use(Character* character)
{
	//character hp 50 add
}

void HealthPotion::ItemEffect()
{
	cout << "ItemEffect : health increased " << healthRestore << endl;
}
