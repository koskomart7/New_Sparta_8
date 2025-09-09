#include <iostream>
#include "HealthPotion.h"
#include "Character.h"

HealthPotion::HealthPotion(int healthRestore, int price, string name)
{
	this->healthRestore = healthRestore;
	this->price = price;
	this->name = name;
}

HealthPotion::~HealthPotion()
{
}

int HealthPotion::getRestoreValue()
{
	return healthRestore;
}

void HealthPotion::setRestoreValue(int healthRestore)
{
	this->healthRestore = healthRestore;
}

void HealthPotion::Use(Character* character)
{
	if (character != nullptr)
	{
		cout << "Player use - " << name << " - !\n" << endl;
		character->heal(healthRestore);
	}
}

void HealthPotion::ItemEffect()
{
	cout << "ItemEffect : health increased " << healthRestore << endl;
}
