#pragma once

#include "Monster.h"
#include "Character.h"

class GameManager {
private:
	Character* player;

public:
	GameManager(Character*);

	~GameManager();

	Monster* spawnMonsters();

	void battle();

	void bossBattle();

	void displayStats() const;

	void displayInv() const;

	void shopping();
};

Character* characterCreation();

int callMainMenu();

void callPlayerMenu(GameManager&);