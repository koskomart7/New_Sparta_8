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
	Item(int price = 0, string name = "");

	int getPrice() const;
	string getName() const;
	virtual void Use(Character* character) = 0;
};
