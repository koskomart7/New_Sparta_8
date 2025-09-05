#include "Orc.h"
#include <cstdlib>

Orc::Orc(int level)
{
	this->name = "Orc";
	this->health = level * (20 + rand() % 11);
	this->attack = level * (5 + rand() % 6);
}

Item* Orc::dropItem()
{
	return nullptr;
}
