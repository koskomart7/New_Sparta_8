#pragma once
#include "Monster.h"

class Goblin : public Monster
{
public:
	Goblin(int level, string name = "Goblin", int health = 20, int attack = 5, int dropExp = 50, int dropGold = 10);
	Item* dropItem() override;
};