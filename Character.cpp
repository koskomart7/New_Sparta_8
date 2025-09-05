#include "Character.h"
#include <iostream>
#include <random>
#include <algorithm>

Character::Character(const string& characterName)
	:name(characterName), level(1),currentHealth(200), 
	maxHealth(200),attack(30), exp(0), gold(0)
{
	
}

//setter function

void Character::setName(const string& PlayerName)
{
	name = PlayerName;
}

void Character::setLevel(int lvl)
{
    if (lvl < 1) 
    {
        cout << "Warning: The level cannot be less than 1" << endl;
        return;
    }

    if (lvl > MAX_LEVEL) {
        cout << " Warning: Level cannot exceed 10. "<< endl;
        return;
    }
    int oldLevel = level;
    level = lvl;

    updateAttack();
    updateMaxHealth();

    if (currentHealth > maxHealth)
    {
        currentHealth = maxHealth;
    }
    cout << "Level has changed from" << oldLevel << "to" << endl;
    cout << "New Maximum Health: " << maxHealth << ", New Maximum Attack Power " << attack << endl;
}

void Character::setCurrentHealth(int newHealth)
{
    if (newHealth < 0) 
    {
        cout << "Warning: Health cannot be less than 0. Setting to 0." << endl;
        currentHealth = 0;
    }
    else if (newHealth > maxHealth) 
    {
        cout << "Warning: Your current health exceeds maximum health" << maxHealth << "Setting to maximum." << endl;
        currentHealth = maxHealth;
    }
    else 
    {
        currentHealth = newHealth;
    }

    cout << "Your current health has been set to" << currentHealth << endl;

}

void Character::setAttack(int newAttack)
{
    if (newAttack < 0) {
        cout << "Warning: Attack power cannot be less than 0." << endl;
        return;
    }

    if (newAttack > 1000) { 
        cout << " Warning: Attack power is too high. Limit to 1000." << endl;
        newAttack = 1000;
    }

    int oldAttack = attack;
    attack = newAttack;
    cout << "Attack power changed from " << oldAttack << "to " << attack << endl;
}

void Character::setExp(int newExp)
{
    if (newExp < 0) 
    {
        cout << "Warning: Your experience cannot be less than 0." << endl;
        return;
    }

    int oldExp = exp;
    exp = newExp;
    cout << "Experience value set from " << oldExp << " to " << exp << endl;

    while (canLevelUp()) 
    {
        levelUp();
    }
}

void Character::setGold(int newGold)
{
    if (newGold < 0) 
    {
        cout << "Warning: Gold cannot be less than 0." << endl;
        gold = 0;
    }
    else 
    {
        gold = newGold;
    }

    cout << "Gold is set to " << gold << endl;
}

// Function
void Character::levelUp()
{
    if (!canLevelUp())
    {
        return;
    }

    exp -= EXP_FOR_LEVELUP;
    level++;
    
    //only for printing 
    int oldMaxHealth = maxHealth;
    int oldAttack = attack;

    updateAttack();
    updateMaxHealth();
    // Full recovery of HP
    currentHealth = maxHealth;

    cout << "\n Level UP! " << name << "This level " << level << "has been reached!" << endl;
    cout << "Maximum Health: " << oldMaxHealth << " → " << maxHealth
        << " (+" << (maxHealth - oldMaxHealth) << ")" << endl;
    cout << "Attack Power : " << oldAttack << " → " << attack
        << " (+" << (attack - oldAttack) << ")" << endl;
    cout << "Your stamina has been fully restored!!" << endl;
}

void Character::updateMaxHealth()
{
    maxHealth = 200 + (level - 1) * 20;
}
void Character::updateAttack()
{
    attack = 30 + (level - 1) * 5;
}

void Character::validateAndUpdateStats()
{
    if (currentHealth > maxHealth)
    {
        currentHealth = maxHealth;
    }

    //Level-based stat recalculation
    updateMaxHealth();
    updateAttack();
}

void Character::takeDamage(int damage)
{
    currentHealth = max(0, currentHealth - damage);
    cout << name << "has received " << damage << " damage. " 
        << "Remain HP : " << currentHealth << endl;
}

void Character::heal(int amount)
{

}




