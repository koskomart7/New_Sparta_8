#include "AttackBoost.h"


AttackBoost::AttackBoost(int attackIncrease, int price, string name) : Item(price, name)
{
	this->attackIncrease = attackIncrease;
}

void AttackBoost::Use(Character* character)
{
	//character attack 10 add
}