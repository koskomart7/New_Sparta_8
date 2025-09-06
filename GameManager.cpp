#include <iostream>
#include <vector>
#include <random>

#include "rangeRd.h"
#include "GameManager.h"
#include "Item.h"
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
	int enemyLv = 0;

	if (player->getLevel() <= 2) 
	{
		enemyLv = player->getLevel() + randomRange(0, 1);
	}

	else
	{
		enemyLv = player->getLevel() + randomRange(-2, 2);
	}

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
	int targetIdx = 0, enemySize = 0, earnedXP = 0, earnedGold = 0;
	int turns = 1;
	int selection;
	vector<Monster*> enemy;

	for (int i = 0; i < randomRange(1, 3); i++)
	{
		enemy.push_back(spawnMonsters());
	}

	while (true) // Battle Logics
	{
		enemySize = enemy.size();

		cout << "===== Battle Turn " << turns << " =====\n" << endl;
		cout << "--- Enemies : " << enemySize <<  " left ---" << endl;

		for (int i = 0; i < enemySize; i++)
		{
			cout << i + 1 << " - " << enemy[i]->getName() << endl;
		}

		cout << "\n===== Behaviors =====\n" << endl;
		cout << "1. Attack" << endl;
		cout << "2. Use Item" << "\n" << endl;
		cout << "Enter selection : ";

		cin >> selection;

		system("cls");

		if (cin.fail() || (selection < 0 || selection > 2))
		{
			cout << " invalid input." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}

		else
		{
			switch (selection)
			{
			case 1:
			{
				while (true)	// Attack Menu
				{
					cout << "===== Attack =====\n" << endl;
					cout << "--- Enemies : " << enemySize << " left ---" << endl;

					for (int i = 0; i < enemySize; i++)
					{
						cout << i + 1 << " - " << enemy[i]->getName() << " | HP : " << enemy[i]->getHealth() << "\n" << endl;
					}

					cout << "select Target : ";

					cin >> targetIdx;

					system("cls");

					if (cin.fail() || (targetIdx <= 0 || targetIdx > enemySize))
					{
						cout << " invalid input." << endl;
						cin.clear();
						cin.ignore(10000, '\n');
					}

					else
					{
						break;
					}
				}	// Attack Menu end

				targetIdx -= 1;

				attack(enemy[targetIdx]);

				if (enemySize < 1) {
					beingAttacked(enemy[randomRange(0, enemySize - 1)]);
				}
				
				else {
					beingAttacked(enemy[targetIdx]);
				}

				++turns;

				break;
			}

			case 2:
				// Item fuction here.
				continue;

			default:
				break;
			}
		}

		if(enemy.at(targetIdx)->getHealth() <= 0)
		{
			//it'll be a part to get level from dead monster then add to earned XP and gold.
			cout << "===== Attack =====\n" << endl;
			cout << "You have killed " << enemy[targetIdx]->getName() << "!\n" << endl;

			earnedXP += (randomRange(50, 80) * enemy[targetIdx]->getHealth());		// Need getLevel() for Monsters.
			earnedGold += (randomRange(20, 150) * enemy[targetIdx]->getHealth());	// Need getLevel() for Monsters.

			delete enemy.at(targetIdx);
			enemy[targetIdx] = nullptr;

			enemy.erase(enemy.begin() + targetIdx);

			system("pause");
			system("cls");
		}

		if(enemy.empty()) /* Winning condition. */
		{
			cout << "===== Battle Result ===== \n" << endl;
			cout << "You have won the battle!" << endl;

			player->addGold(earnedGold);
			player->addExp(earnedXP);

			cout << "You have earned " << earnedXP << " XP, " << earnedGold << " Golds.\n" << endl;

			if (player->canLevelUp()) 
			{
				player->levelUp();
				player->addExp(earnedXP);
			}
			else
			{
				player->addExp(earnedXP);
			}

			system("pause");
			system("cls");

			break;
		}

		if(player->getCurrentHealth() <= 0) /* Losing condition. */
		{
			cout << "===== Battle Result ===== \n" << endl;
			cout << "You have fallen..." << endl;

			player->setCurrentHealth(20);

			for (auto enemyList : enemy)
			{
				delete enemyList;
				enemyList = nullptr;
			}

			enemy.clear();

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

void GameManager::attack(Monster* target)
{
	int damage = player->getAttack();
	// target->setHealth(target->getHealth() - damage);	//placeholder

	cout << "===== Attack ===== \n" << endl;
	cout << "Attacking " << target->getName() << "!" << endl;
	cout << target->getName() << " has taken " << damage << " damage.\n" << endl;

	system("pause");
	system("cls");
}

void GameManager::beingAttacked(Monster* monster)
{
	int damage = monster->getAttack() + randomRange(0, 3);
	//player->setCurrentHealth(player->getCurrentHealth - damamge);	//placeholder

	cout << "===== Attack ===== \n" << endl;
	cout << monster->getName() << " attacked you" << "!" << endl;
	cout << " you have taken " << damage << " damage.\n" << endl;

	system("pause");
	system("cls");
}

void GameManager::displayInv() const
{
	vector<Item*> inv = player->getInventory();

	cout << "===== Inventory ===== \n" << endl;

	if (inv.empty()) 
	{
		cout << "There's nothing in the inventory.\n" << endl;
	}

	else
	{
		for (auto invIt : inv) 
		{
			cout << invIt->getName() << endl;
		}
	}

	system("pause");
	system("cls");
}

void GameManager::displayStats() const
{
	cout << "===== Character Stats =====\n" << endl;
	cout << "Name : " << player->getName() << endl;
	cout << "Level : " << player->getLevel() << endl;
	cout << "Exp : " << player->getExp() << endl;
	cout << "Health : " << player->getMaxHealth() << endl;
	cout << "Attack : " << player->getAttack() << "\n" << endl;

	system("pause");
	system("cls");
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
		

		if (!cin.fail() && !name.empty() && !all_of(name.begin(), name.end(), isspace)) // Checks if name is blank.
		{
			system("cls");
			break;
		}

		cout << "\ninvalid name. Try again." << endl;
		system("pause");
		system("cls");
	}

	player = new Character(name);

	cout << "===== Character Created! =====\n" << endl;
	cout << "Name : " << player->getName() << endl;
	cout << "Level : " << player->getLevel() << endl;
	cout << "Exp : " << player->getExp() << endl;
	cout << "Health : " << player->getMaxHealth() << endl;
	cout << "Attack : " << player->getAttack() << "\n" << endl;

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

void callPlayerMenu(GameManager& game)
{
	int selection;

	while (true)
	{
		cout << "===== Player Menu =====\n" << endl;
		cout << "1. Show Stats" << endl;
		cout << "2. Inventory" << endl;
		cout << "3. Return\n" << endl;
		cout << "Enter selection : ";

		cin >> selection;

		system("cls");

		if (cin.fail() || (selection < 0 || selection > 3))
		{
			cout << " invalid input." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}

		else
		{
			switch (selection)
			{
			case 1:
				game.displayStats();
				break;
			case 2:
				game.displayInv();
				break;
			default:
				break;
			}
		}

		if (selection == 3) {
			break;
		}
	}
}
