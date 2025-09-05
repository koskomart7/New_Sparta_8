#pragma once
#include "Item.h"

class AttackBoost : public Item
{
private:
	int attackIncrease;

public:
	AttackBoost(int attackIncrease = 10);
	void Use(Character* character) override;
};