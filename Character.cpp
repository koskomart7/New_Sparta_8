#include "Character.h"
#include <iostream>


Character::Character(const string& characterName)
	:name(characterName), level(1),currentHealth(200), 
	maxHealth(200),attack(30), exp(0), gold(0)
{
	
}

//setter function

void Character::setName(const string& PlayerName)
{
}

void Character::setLevel(int lvl)
{
}

void Character::setCurrentHealth(int newHealth)
{
}

void Character::setAttack(int newAttack)
{
}

void Character::setExp(int newExp)
{
}

void Character::setGold(int newGold)
{
}
