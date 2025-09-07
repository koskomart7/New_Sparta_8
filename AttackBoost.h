#pragma once
#include "Item.h"

class AttackBoost : public Item
{
private:
	int attackIncrease;

public:
	AttackBoost(int attackIncrease = 10, int price = 75, string name = "AttackBoost");
	~AttackBoost() override;

	void Use(Character* character) override;
	void ItemEffect() override;
};