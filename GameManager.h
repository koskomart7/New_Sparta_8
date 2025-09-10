#pragma once

#include <vector>

class Shop;

class Monster;

class Character;

class GameManager {
private:
	Character* player;
	std::vector<int> killLogs;
	bool isBossKilled;

public:
	GameManager(Character*);

	~GameManager();

	void battle();

	void attack(Monster*);

	void beingAttacked(Monster*);

	void displayStats() const;

	void displayInv(bool) const;

	void shoppingBuy(int, Shop&);

	void shoppingSell(int, Shop&);

	void logKill(Monster*);

	inline bool isBossKill() const { return this->isBossKilled; };
};

Character* characterCreation();

int callMainMenu();

void callPlayerMenu(GameManager&);

void callShopMenu(GameManager& game, Shop& shop);