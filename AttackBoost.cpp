#include <iostream>
#include "AttackBoost.h"
#include "Character.h"

AttackBoost::AttackBoost(int attackIncrease, int duration, int price, string name)
{
	this->attackIncrease = attackIncrease;
	this->duration = duration;
	this->price = price;
    this->name = name;
}

AttackBoost::~AttackBoost()
{
}

int AttackBoost::getIncreaseValue()
{
	return attackIncrease;
}

int AttackBoost::getDurationValue()
{
	return duration;
}

void AttackBoost::setIncreaseValue(int attackIncrease)
{
	this->attackIncrease = attackIncrease;
}

void AttackBoost::setDurationValue(int duration)
{
	this->duration = duration;
}

void AttackBoost::Use(Character* character)
{
	if (character != nullptr)
	{
		character->setAttack(attackIncrease);
	}
}

void AttackBoost::ItemEffect()
{
	cout << "ItemEffect : Attack power increased " << attackIncrease  << endl;
}
