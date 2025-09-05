#include "HealthPotion.h"

HealthPotion::HealthPotion(int healthRestore)
{
	this->name = "HealthPotion";
	this->healthRestore = healthRestore;
}

void HealthPotion::Use(Character* character)
{
	//character hp 50 add
}
