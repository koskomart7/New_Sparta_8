#pragma once
#include <string>

using namespace std;

class Character;

class Item
{
protected:
	int price;
	string name;

public:
	Item();

	int getPrice() const;
	string getName() const;

	// virtual void Use(Character* character) = 0;
	// virtual void ItemEffect() = 0;
};
