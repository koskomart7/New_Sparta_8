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
	virtual ~Item();

	int getPrice() const;
	string getName() const;

	void setPrice(int price);
	void setName(string name);

	virtual void Use(Character* character) = 0;
	virtual void ItemEffect() = 0;
};
