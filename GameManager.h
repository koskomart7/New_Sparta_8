#pragma once

#include "Monster.h"

class GameManager {
public:
	Monster spawnMonsters();

	void battle(Character* player);

	void bossBattle(Character* player);

	void displayStats(Character* player);

	void displayInv(Character* player);

	void shopping(Character* player);
};