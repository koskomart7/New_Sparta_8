#include "Monster.h"

Monster::Monster()
{
	this->name = "";
	this->health = 0;
	this->attack = 0;
	this->dropExp = 0;
	this->dropGold = 0;
}

string Monster::getName() const
{
	return name;
}

int Monster::getHealth() const
{
	return health;
}

int Monster::getAttack() const
{
	return attack;
}

int Monster::getDropExp() const
{
	return dropExp;
}

int Monster::getDropGold() const
{
	return dropGold;
}

void Monster::takeDamage(int damage)
{
	if (health <= damage)
	{
		health = 0;
		return;
	}
	health -= damage;
}
