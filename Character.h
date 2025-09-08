#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <vector>
#include <algorithm>
#include "Item.h"
using namespace std;

//struct Item
//{
//    string name;
//    int healthBoost;
//    int attackBoost;
//    int price;
//
//    Item(const string& itemName, int health, int attack, int itemPrice)
//        : name(itemName), healthBoost(health), attackBoost(attack), price(itemPrice) {
//    }
//};

class Character
{
private:
    string name;
    int level;
    int currentHealth;
    int maxHealth;
    int attack;
    int exp;
    int gold;
    vector<Item*> inventory;

    static const int EXP_FOR_LEVELUP = 100;
    static const int MAX_LEVEL = 10;

    void updateMaxHealth();
    void updateAttack();
    void validateAndUpdateStats();

public:

    Character(const string& characterName);
    ~Character();

    const string& getName() const { return name; }
    int getLevel() const { return level; }
    int getCurrentHealth() const { return currentHealth; }
    int getMaxHealth() const { return maxHealth; }
    int getAttack() const { return attack; }
    int getExp() const { return exp; }
    int getGold() const { return gold; }
    vector<Item*> getInventory() const { return inventory; }
    size_t getInventorySize() const;

    //setter fuction
    void setName(const string& PlayerName);
    void setLevel(int lvl);
    void setCurrentHealth(int newHealth);
    void setAttack(int newAttack);
    void setExp(int newExp);
    void setGold(int newGold);
    
    //void displayStatus() const;
    bool isAlive() const { return currentHealth > 0; }

    void addExp(int amount) { exp += amount; }
    bool canLevelUp() const { return exp >= EXP_FOR_LEVELUP && level < MAX_LEVEL; }
    void levelUp(); 


    void takeDamage(int damage);
    void heal(int amount); 
    int dealDamage() const { return attack; }


    void addGold(int amount) { gold += amount; }
    bool spendGold(int amount);  

    
    void addItem(Item* item);   // remove Item 추가 구현   
    bool hasItems() const
    {
        return !inventory.empty();
    }
    //void displayInventory() const;
    bool useRandomItem();  //
    bool sellItem(int index, vector<Item*> Inventory) {};  // Modified with a parameter vector inventory

  
};

#endif 