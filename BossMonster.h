#pragma once
#include "Monster.h"

class BossMonster : public Monster
{
public:
	BossMonster(int level);

	Item* dropItem() override;
};
