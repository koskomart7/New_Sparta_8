#pragma once

#include "Monster.h"
#include "Character.h"

class GameManager {
public:
	Monster* spawnMonsters(Character* player);

	void battle(Character* player);

	void bossBattle(Character* player);

	void displayStats(Character& player) const;

	void displayInv(Character& player) const;

	void shopping(Character* player);
};

//Character* characterCreation(string name);

int callMainMenu();