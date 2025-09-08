#pragma once
#include "Monster.h"

class BossMonster : public Monster
{
public:
	BossMonster(int level, string name = "BossMonster", int health = 20, int attack = 5, int dropExp = 50, int dropGold = 10);
	~BossMonster() override;
	Item* dropItem() override;
};
