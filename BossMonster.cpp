#include "BossMonster.h"
#include <cstdlib>

BossMonster::BossMonster(int level, string name, int health, int attack, int dropExp, int dropGold)
{
	this->name = name;
	this->health = (int)(level * (health + rand() % 11) * (1 + (rand() % 6 * 0.1f)));
	this->attack = (int)(level * (attack + rand() % 6) * (1 + (rand() % 6 * 0.1f)));
	this->dropExp = dropExp;
	this->dropGold = dropGold + rand() % 11;
}

Item* BossMonster::dropItem()
{
	return nullptr;
}
