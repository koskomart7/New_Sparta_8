#include "HealthPotion.h"

HealthPotion::HealthPotion(int healthRestore, int price, string name) : Item(price, name)
{
	this->healthRestore = healthRestore;
}

void HealthPotion::Use(Character* character)
{
	//character hp 50 add
}
