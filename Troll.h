#pragma once
#include "Monster.h"

class Troll : public Monster
{
public:
	Troll(int level, string name = "Troll", int health = 20, int attack = 5, int dropExp = 50, int dropGold = 10);
	~Troll() override;
	//Item* dropItem() override;
};
