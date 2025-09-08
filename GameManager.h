#pragma once

#include "Monster.h"
#include "Character.h"

class Shop;

class GameManager {
private:
	Character* player;

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

	inline int getPlayerLevel() { return player->getLevel(); }
};

Character* characterCreation();

int callMainMenu();

void callPlayerMenu(GameManager&);

void callShopMenu(GameManager& game, Shop& shop);