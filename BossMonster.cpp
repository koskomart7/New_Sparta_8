#include "BossMonster.h"
#include "rangeRd.h"
#define RANDOM_MIN_ZERO 0
#define RANDOM_MAX_PLUS_10 11
#define RANDOM_MAX_PLUS_5 6
#define BOSS_RANDOM_MIN 1.0
#define BOSS_RANDOM_MAX 1.6


BossMonster::BossMonster(int level, string name, int health, int attack, int dropExp, int dropGold)
{
	this->name = name;
	this->health = (int)(level * randomRange(health, health + RANDOM_MAX_PLUS_10) * randomRange(BOSS_RANDOM_MIN, BOSS_RANDOM_MAX));
	this->attack = (int)(level * randomRange(attack, attack + RANDOM_MAX_PLUS_5) * randomRange(BOSS_RANDOM_MIN, BOSS_RANDOM_MAX));
	this->dropExp = dropExp;
	this->dropGold = dropGold + randomRange(RANDOM_MIN_ZERO, RANDOM_MAX_PLUS_10);

	this->health = level * randomRange(health, health + RANDOM_MAX_PLUS_10);
	this->attack = level * randomRange(attack, attack + RANDOM_MAX_PLUS_5);

}

//Item* BossMonster::dropItem()
//{
//	return nullptr;
//}
