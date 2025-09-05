#include "Monster.h"

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

void Monster::takeDamage(int damage)
{
	if (health <= damage)
	{
		health = 0;
		return;
	}
	health -= damage;
}
