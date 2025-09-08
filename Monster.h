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
	int dropExp;
	int dropGold;
	
public:
	Monster();
	virtual ~Monster();

	string getName() const;
	int getHealth() const;
	int getAttack() const;
	int getDropExp() const;
	int getDropGold() const;

	void setName(string name);
	void setHealth(int health);
	void setAttack(int attack);
	void setDropExp(int dropExp);
	void setDropGold(int dropGold);

	void takeDamage(int damage);
	virtual Item* dropItem() = 0;
};
