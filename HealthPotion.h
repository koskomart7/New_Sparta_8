#pragma once
#include "Item.h"

class HealthPotion : public Item
{
private:
	int healthRestore;

public:
	HealthPotion(int healthRestore = 50, int price = 50, string name = "HealthPotion");

	// void Use(Character* character) override;
	// void ItemEffect() override;
};
