#include <iostream>
#include "HealthPotion.h"
#include "Character.h"

HealthPotion::HealthPotion(int healthRestore, int price, string name)
{
	this->healthRestore = healthRestore;
	this->price = price;
	this->name = name;
}

void HealthPotion::Use(Character* character)
{
	character->setCurrentHealth(healthRestore);
}

void HealthPotion::ItemEffect()
{
	cout << "ItemEffect : health increased " << healthRestore << endl;
}
