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
    int attackBuffAmount;   // 현재 적용된 버프 공격력    
    int buffTurnsRemaining; // 남은 버프 지속 턴 수 

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
    
    // 함수
    
    // 경험치 관련 함수들
    void addExp(int amount) { exp += amount; }
    bool canLevelUp() const { return exp >= EXP_FOR_LEVELUP && level < MAX_LEVEL; }
    void levelUp(); 

    //기본 캐릭터 함수들
    bool isAlive() const { return currentHealth > 0; }
    void takeDamage(int damage);
    void heal(int amount); 
   
    
    // 버프관련
    void advanceTurn(); // 턴이 끝날 때마다 호출
    void dealBuffCalc(int buffAmount, int buffTurns);       // 딜버프 물약 효과 검증 및 계산 함수 
    bool hasActiveBuff() const;

    // 골드관련
    void addGold(int amount) { gold += amount; }
    bool spendGold(int amount);  
    
    // 인벤토리 관련
    void addItem(Item* item);   // remove Item 추가 구현 
    bool removeItem(size_t index); // 인벤토리에서 지정 인덱스의 아이템 삭제
    bool hasItems() const       // 인벤토리가 비었는지 유무 확인 함수 
    {
        return !inventory.empty();
    }
    //void displayInventory() const;
    //bool useRandomItem();  //
    bool sellItem(int index, vector<Item*> Inventory) {};  // Modified with a parameter vector inventory

  
};

#endif 