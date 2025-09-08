#pragma once
#include "Item.h"

class AttackBoost : public Item
{
private:
	int attackIncrease;
	int duration;

public:
	AttackBoost(int attackIncrease = 10, int duration = 3, int price = 75, string name = "AttackBoost");
	~AttackBoost() override;

	int getIncreaseValue();
	int getDurationValue();
	void setIncreaseValue(int attackIncrease);
	void setDurationValue(int duration);

	void Use(Character* character) override;
	void ItemEffect() override;
};