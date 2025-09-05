#pragma once
#include <string>

using namespace std;

class Item;

class Monster
{
protected:
	string name;
	int health;
	int attack;

public:
	string getName() const;
	int getHealth() const;
	int getAttack() const;

	void takeDamage(int damage);
	//virtual Item* dropItem();
};
