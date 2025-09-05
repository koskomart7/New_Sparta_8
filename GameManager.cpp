#include <iostream>
#include <vector>
#include <random>

#include "rangeRd.h"
#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "Goblin.h"
#include "Troll.h"
#include "Orc.h"

using namespace std;

Monster* GameManager::spawnMonsters(Character* player)
{
	Monster* monster = nullptr;
	int enemyLv = player->getLevel() + randomRange(-2, 2);

	while (!monster)
	{
		switch (randomRange(1,3))
		{
		case 1:
			// create goblin
			monster = new Goblin(enemyLv);
			break;

		case 2:
			// create Orc
			monster = new Orc(enemyLv);
			break;

		case 3:
			// create Troll
			monster = new Troll(enemyLv);
			break;

		default:
			break;
		}
	}

	return monster;
}

void GameManager::battle(Character* player) 
{
	int turns = 0, targetIdx = 0, enemySize = 0;
	vector<Monster*> enemy;

	for (int i = 0; i < 3; i++) // will make it random(1 ~ 3) later.
	{
		enemy.push_back(spawnMonsters(player));
	}

	enemySize = enemy.size();

	while (true)
	{
		++turns;

		// battle Logic here

		if(enemy[targetIdx]->getHealth() <= 0)
		{
			//enemy.erase(targetIdx);
			delete enemy.at(targetIdx);
			enemy.at(targetIdx) = nullptr;
		}

		if(enemy.empty())
		{
			cout << "You have won the battle!" << endl;

			/* codes for winning condition. */
			
			int earnedXP = (rand() * player->getLevel());  // rand() is placeholder.
			int earnedGold = (rand() * player->getLevel());// rand() is placeholder.

			player->addGold(earnedGold);
			player->addExp(earnedXP);

			cout << "You have earned " << earnedXP << " XP, " << earnedGold << " Golds." << endl;

			if (player->canLevelUp()) 
			{
				//player->levelUp();
				player->addExp(earnedXP);
			}
			else
			{
				player->addExp(earnedXP);
			}

			break;
		}

		if(player->getCurrentHealth() <= 0)
		{
			cout << "You have fallen..." << endl;

			/* codes for losing condition. */
			
			break;
		}
	}
}

void GameManager::bossBattle(Character* player) 
{
	//Monster boss;
}

void GameManager::displayInv(Character& player) const
{
	// displayInv Logic
}

void GameManager::displayStats(Character& player) const
{
	// displayStats Logic
}

void GameManager::shopping(Character* player)
{
	// shop
}

int callMainMenu() {
	int selection;

	while (true) {
		std::cout << "===== ⚗️ Main Menu =====\n" << std::endl;
		std::cout << "1. Player Menu" << std::endl;
		std::cout << "2. Raid Dungeon" << std::endl;
		std::cout << "3. Visit Shop" << std::endl;
		std::cout << "4. Exit\n" << std::endl;
		std::cout << "Enter selection : ";

		std::cin >> selection;

		if (std::cin.fail() || (selection < 0 || selection > 4)) {
			std::cout << " invalid input." << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		else {
			return selection;
		}
		system("cls");
	}
}