#include "Troll.h"
#include <cstdlib>

Troll::Troll(int level)
{
	this->name = "Troll";
	this->health = level * (20 + rand() % 11);
	this->attack = level * (5 + rand() % 6);
}

//Item* Troll::dropItem()
//{
//	return nullptr;
//}
