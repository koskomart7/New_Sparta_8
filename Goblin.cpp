#include "Goblin.h"
#include "rangeRd.h"
#define RANDOM_MIN_ZERO 0
#define RANDOM_MAX_PLUS_10 11
#define RANDOM_MAX_PLUS_5 6

Goblin::Goblin(int level, string name, int health, int attack, int dropExp, int dropGold)
{
	this->name = name;
	this->health = level * randomRange(health, health + RANDOM_MAX_PLUS_10);
	this->attack = level * randomRange(attack, attack + RANDOM_MAX_PLUS_5);
	this->dropExp = dropExp;
	this->dropGold = dropGold + randomRange(RANDOM_MIN_ZERO, RANDOM_MAX_PLUS_10);
}
	

//Item* Goblin::dropItem()
//{
//	return nullptr;
//}
