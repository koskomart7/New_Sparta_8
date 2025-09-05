#pragma once
#include "Item.h"

class HealthPotion : public Item
{
private:
	int healthRestore;

public:
	HealthPotion(int healthRestore = 50);
	void Use(Character* character) override;
};
