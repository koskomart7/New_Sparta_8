#pragma once

#include "Monster.h"
#include "Character.h"

class Shop;

class GameManager {
private:
	Character* player;
	vector<int> killLogs;

public:
	GameManager(Character*);

	~GameManager();

	Monster* spawnMonsters();

	Monster* spawnBoss();

	void battle();

	void attack(Monster*);

	void beingAttacked(Monster*);

	void displayStats() const;

	void displayInv(bool) const;

	void shoppingBuy(int, Shop&);

	void shoppingSell(int, Shop&);

	void logKill(Monster*);
};

Character* characterCreation();

int callMainMenu();

void callPlayerMenu(GameManager&);

void callShopMenu(GameManager& game, Shop& shop);