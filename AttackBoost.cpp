#include <iostream>
#include "AttackBoost.h"
#include "Character.h"

AttackBoost::AttackBoost(int attackIncrease, int price, string name)
{
	this->attackIncrease = attackIncrease;
	this->price = price;
    this->name = name;
}

void AttackBoost::Use(Character* character)
{
	character->setAttack(attackIncrease);
}

void AttackBoost::ItemEffect()
{
	cout << "ItemEffect : Attack power increased " << attackIncrease  << endl;
}
