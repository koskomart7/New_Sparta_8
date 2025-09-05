#include "Goblin.h"
#include <cstdlib>

Goblin::Goblin(int level, string name, int health, int attack, int dropExp, int dropGold)
{
	this->name = name;
	this->health = level * (health + rand() % 11);
	this->attack = level * (attack + rand() % 6);
	this->dropExp = dropExp;
	this->dropGold = dropGold + rand() % 11;
}

//Item* Goblin::dropItem()
//{
//	return nullptr;
//}
