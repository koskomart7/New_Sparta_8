#include "AttackBoost.h"
#include <iostream>

AttackBoost::AttackBoost(int attackIncrease, int price, string name)
{
	this->attackIncrease = attackIncrease;
	this->price = price;
    this->name = name;
}

//void AttackBoost::Use(Character* character)
//{
//	//character attack 10 add
//}
//
//void AttackBoost::ItemEffect()
//{
//	cout << "ItemEffect : Attack power increased " << attackIncrease  << endl;
//}
