#include "Troll.h"
#include "rangeRd.h"
#include "Item.h"
#include "HealthPotion.h"

#define RANDOM_MIN_ZERO 0
#define RANDOM_MIN_ONE 1
#define RANDOM_MAX_PLUS_10 11
#define RANDOM_MAX_PLUS_5 6

Troll::Troll(int level, string name, int health, int attack, int dropExp, int dropGold)
{
	this->name = name;
	this->health = level * randomRange(health, health + RANDOM_MAX_PLUS_10);
	this->attack = level * randomRange(attack, attack + RANDOM_MAX_PLUS_5);
	this->dropExp = dropExp;
	this->dropGold = dropGold + randomRange(RANDOM_MIN_ZERO, RANDOM_MAX_PLUS_10);
}

Troll::~Troll()
{
}

Item* Troll::dropItem()
{
	Item* item = nullptr;
	if (randomRange(RANDOM_MIN_ONE, RANDOM_MAX_PLUS_10) < 4)
	{
		item = new HealthPotion();
	}
	return item;
}
