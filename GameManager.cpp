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

GameManager::GameManager(Character* newPlayer) : player(newPlayer) {};

GameManager::~GameManager() 
{
	delete this->player;
	this->player = nullptr;
};

Monster* GameManager::spawnMonsters()
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

void GameManager::battle() 
{
	int turns = 0, targetIdx = 0, enemySize = 0;
	vector<Monster*> enemy;

	for (int i = 0; i < randomRange(1, 3); i++)
	{
		enemy.push_back(spawnMonsters());
	}

	enemySize = enemy.size();

	while (true)
	{
		++turns;

		// battle Logic here

		if(enemy[targetIdx]->getHealth() <= 0)
		{
			//it'll be a part to get level from dead monster then add to earned XP and gold.

			delete enemy.at(targetIdx);
			enemy.at(targetIdx) = nullptr;
		}

		if(enemy.empty())
		{
			cout << "===== Battle Result ===== \n" << endl;
			cout << "You have won the battle!" << endl;

			/* codes for winning condition. */
			
			int earnedXP = (randomRange(50, 100) * player->getLevel());  // randomRange() is placeholder.
			int earnedGold = (randomRange(80, 150) * player->getLevel());// randomRange() is placeholder.

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
			/* codes for losing condition. */

			cout << "===== Battle Result ===== \n" << endl;
			cout << "You have fallen..." << endl;

			system("pause");
			system("cls");

			break;
		}
	}
}

void GameManager::bossBattle() 
{
	//Monster boss;
}

void GameManager::displayInv() const
{
	// displayInv Logic
}

void GameManager::displayStats() const
{
	// displayStats Logic
}

void GameManager::shopping()
{
	// shop
}

Character* characterCreation() 
{
	string name;
	Character* player;

	while(true)
	{
		cout << "===== Create Character =====\n" << endl;
		cout << "Enter name : ";

		getline(cin, name);
		system("cls");

		if (!cin.fail()) 
		{
			break;
		}

		cout << "\ninvalid name. Try again.";
		system("pause");
		system("cls");
	}

	player = new Character(name);

	cout << "===== Character Created! =====\n" << endl;
	cout << "Name : " << player->getName() << endl;
	cout << "Level : " << player->getLevel() << endl;
	cout << "Exp : " << player->getExp() << endl;
	cout << "Health : " << player->getMaxHealth() << endl;
	cout << "Attack : " << player->getAttack() << endl;

	system("pause");
	system("cls");

	return player;
}

int callMainMenu() 
{
	int selection;

	while (true) 
	{
		cout << "===== Main Menu =====\n" << endl;
		cout << "1. Player Menu" << endl;
		cout << "2. Raid Dungeon" << endl;
		cout << "3. Visit Shop" << endl;
		cout << "4. Exit\n" << endl;
		cout << "Enter selection : ";

		cin >> selection;

		system("cls");

		if (cin.fail() || (selection < 0 || selection > 4)) 
		{
			cout << " invalid input." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else 
		{
			return selection;
		}
	}
}