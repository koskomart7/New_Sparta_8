#pragma once
#include "Monster.h"

class Orc : public Monster
{
public:
	Orc(int level, string name = "Orc", int health = 20, int attack = 5, int dropExp = 50, int dropGold = 10);

	Item* dropItem() override;
};
