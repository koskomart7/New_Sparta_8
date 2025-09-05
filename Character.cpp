#include "Character.h"
#include <iostream>


Character::Character(const string& characterName)
	:name(characterName), level(1),currentHealth(200), 
	maxHealth(200),attack(30), exp(0), gold(0)
{
	
}
