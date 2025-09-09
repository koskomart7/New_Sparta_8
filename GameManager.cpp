#include <iostream>
#include <vector>
#include <random>

#include "rangeRd.h"
#include "GameManager.h"

#include "Item.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

#include "Shop.h"
#include "Character.h"

#include "Monster.h"
#include "BossMonster.h"
#include "Goblin.h"
#include "Troll.h"
#include "Orc.h"

using namespace std;

GameManager::GameManager(Character* newPlayer) : player(newPlayer) 
{
	killLogs.assign(3, 0);
};

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
		enemyLv = player->getLevel() +randomRange(0, 2);
	}

	else
	{
		enemyLv = player->getLevel() +randomRange(-3, 3);
	}

	while (!monster)
	{
		switch (randomRange(1,4))
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

Monster* GameManager::spawnBoss()
{
	Monster* boss = new BossMonster(12);

	cout << endl;
	cout << "\n===== WARNING =====" << endl;
	cout << "Entering Boss Battle!" << endl;
	cout << "===================\n" << endl;
	
	system("pause");
	system("cls");

	return boss;
}

void GameManager::battle() 
{
	int targetIdx = 0, enemySize = 0, earnedXP = 0, earnedGold = 0;
	int turns = 1;
	int selection;
	vector<Monster*> enemy;

	if (player->getLevel() >= 10) {
		enemy.push_back(spawnBoss());
	}

	else
	{
		for (int i = 0; i < randomRange(1, 4); i++)
		{
			enemy.push_back(spawnMonsters());
		}
	}

	while (true) // Battle Logics
	{
		enemySize = enemy.size();

		cout << "===== Battle Turn " << turns << " =====\n" << endl;
		cout << "--- Enemies : " << enemySize <<  " left ---" << endl;

		for (int i = 0; i < enemySize; i++)
		{
			cout << i + 1 << ". ";
			enemy.at(i)->displayStats();
		}
		cout << "\n--- Player ---"  << endl;
		cout << "ATK : " << player->getAttack() << endl;
		cout << "HP : " << player->getCurrentHealth() << endl;

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
				targetIdx = randomRange(0, enemySize);

				//while (true)	// Attack Menu; Will be automated.
				//{
				//	cout << "===== Attack =====\n" << endl;
				//	cout << "--- Enemies : " << enemySize << " left ---" << endl;

				//	for (int i = 0; i < enemySize; i++)
				//	{
				//		cout << i + 1 << ". ";
				//		enemy.at(i)->displayStats();
				//	}
				//	cout << "\n--- Player ---" << endl;
				//	cout << "ATK : " << player->getAttack() << endl;
				//	cout << "HP : " << player->getCurrentHealth() << endl;

				//	cout << "\nselect Target : ";

				//	cin >> targetIdx;

				//	system("cls");

				//	if (cin.fail() || (targetIdx <= 0 || targetIdx > enemySize))
				//	{
				//		cout << " invalid input." << endl;
				//		cin.clear();
				//		cin.ignore(10000, '\n');
				//	}

				//	else
				//	{
				//		break;
				//	}
				//}	// Attack Menu end

				//targetIdx -= 1;

			attack(enemy[targetIdx]);

			if (enemy.at(targetIdx)->getHealth() <= 0)
			{
				cout << "===== Attack =====\n" << endl;
				cout << "You have killed " << enemy[targetIdx]->getName() << "!\n" << endl;

				logKill(enemy[targetIdx]);

				earnedXP += enemy[targetIdx]->getDropExp();
				earnedGold += enemy[targetIdx]->getDropGold();
				Item* dropItem = enemy[targetIdx]->dropItem();

				if (dropItem != nullptr)
				{
					cout << enemy[targetIdx]->getName() << " dropped a " << dropItem->getName() << "!\n" << endl;
					player->addItem(dropItem);
				}

				delete enemy.at(targetIdx);
				enemy[targetIdx] = nullptr;

				enemy.erase(enemy.begin() + targetIdx);

				system("pause");
				system("cls");
			}

			else
			{
				beingAttacked(enemy[targetIdx]);
			}

			/*if (enemySize <= 1) 
			{
				beingAttacked(enemy.at(0));
			}
				
			else 
			{
				beingAttacked(enemy[targetIdx]);
			}*/

			player->advanceTurn();

			++turns;

			break;

			case 2:
			{
				int itemIdx;

				while (true)	// Item Menu
				{	
					bool isEmpty = !player->hasItems();

					displayInv(isEmpty);

					if (isEmpty)
					{
						break;
					}

					cout << "Type '0' to return." << endl;
					cout << "select Item : ";

					cin >> itemIdx;

					--itemIdx;

					system("cls");

					if (itemIdx == -1)
					{
						break;
					}

					if (cin.fail() || (itemIdx + 1 < 0 || itemIdx + 1 > player->getInventorySize()))
					{
						cout << " invalid input." << endl;
						cin.clear();
						cin.ignore(10000, '\n');
					}

					else
					{
						vector<Item*> inv = player->getInventory();

						inv[itemIdx]->Use(player);
						
						player->removeItem(++itemIdx);

						break;
					}
				}
			}	// Item Menu End
				break;

			default:
				break;
			}
		}

		/*if(enemy.at(targetIdx)->getHealth() <= 0)
		{
			cout << "===== Attack =====\n" << endl;
			cout << "You have killed " << enemy[targetIdx]->getName() << "!\n" << endl;

			logKill(enemy[targetIdx]);

			earnedXP += enemy[targetIdx]->getDropExp();
			earnedGold += enemy[targetIdx]->getDropGold();

			delete enemy.at(targetIdx);
			enemy[targetIdx] = nullptr;

			enemy.erase(enemy.begin() + targetIdx);

			system("pause");
			system("cls");
		}*/

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
			}

			system("pause");
			system("cls");

			break;
		}

		if(!player->isAlive()) /* Losing condition. */
		{
			cout << "===== Battle Result ===== \n" << endl;
			cout << "You have fallen...\n" << endl;

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

void GameManager::attack(Monster* target)
{
	int damage = player->getAttack();
	target->takeDamage(damage);

	cout << "===== Attack ===== \n" << endl;
	cout << "Attacking " << target->getName() << "!" << endl;
	cout << target->getName() << " has taken " << damage << " damage.\n" << endl;
	
	system("pause");
	system("cls");
}

void GameManager::beingAttacked(Monster* monster)
{
	int damage = monster->getAttack() + randomRange(-4, 4);
	player->takeDamage(damage);

	cout << "===== Attack ===== \n" << endl;
	cout << monster->getName() << " attacked you" << "!" << endl;
	cout << "You have taken " << damage << " damage." << endl;
	cout << "HP remaining : " << player->getCurrentHealth() << "\n" << endl;

	system("pause");
	system("cls");
}

void GameManager::displayInv(bool isPaused) const
{
	vector<Item*> inv = player->getInventory();

	cout << "===== Inventory ===== \n" << endl;

	if (inv.empty()) 
	{
		cout << "There's nothing in the inventory.\n" << endl;
	}

	else
	{
		int idx = 1;
		for (auto invIt : inv) 
		{
			cout << idx << " - " << invIt->getName() << endl;
			++idx;
		}
	}

	cout << "\nGold : " << player->getGold() << "\n" << endl;

	if (isPaused) {
		system("pause");
		system("cls");
	}
}

void GameManager::displayStats() const
{
	cout << "===== Character Stats =====\n" << endl;
	cout << "Name : " << player->getName() << endl;
	cout << "Level : " << player->getLevel() << endl;
	cout << "Exp : " << player->getExp() << endl;
	cout << "Health : " << player->getCurrentHealth() << " / " << player->getMaxHealth() << endl;
	cout << "Attack : " << player->getAttack() << "\n" << endl;

	cout << "===== Play Log =====\n" << endl;
	cout << "Goblin killed : " << killLogs[0] << endl;
	cout << "Orc killed : " << killLogs[1] << endl;
	cout << "Troll killed : " << killLogs[2] << "\n" << endl;

	system("pause");
	system("cls");
}

void GameManager::shoppingBuy(int idx, Shop& shop)
{
	shop.buyItem(idx, player);
}

void GameManager::shoppingSell(int idx, Shop& shop)
{
	shop.sellItem(idx, player);
}

void GameManager::logKill(Monster* target)
{
	if (dynamic_cast<Goblin*>(target))
	{
		++killLogs[0];
	}

	else if (dynamic_cast<Orc*>(target))
	{
		++killLogs[1];
	}

	else if (dynamic_cast<Troll*>(target))
	{
		++killLogs[2];
	}
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
				game.displayInv(true);
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

void callShopMenu(GameManager& game, Shop& shop)
{
	int selection;

	while (true)
	{
		cout << "===== Shop =====\n" << endl;
		//shop.displayItems();
		cout << "\n1. Buy Item" << endl;
		cout << "2. Sell Item" << endl;
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
			{
				while (true)
				{
					cout << "===== Shop =====\n" << endl;
					shop.displayItems();
					cout << "\n" << endl;
					game.displayInv(false);
					cout << "\nType '0' to return." << endl;
					cout << "Select item to buy : ";

					cin >> selection;

					system("cls");

					if (selection == 0)
					{
						break;
					}

					else if (cin.fail())
					{
						cout << " invalid input." << endl;
						cin.clear();
						cin.ignore(10000, '\n');
					}

					else
					{
						game.shoppingBuy(selection, shop);
						break;
					}
				}
				break;
			}
				
			case 2:
			{
				while (true)
				{
					cout << "===== Shop =====\n" << endl;
					shop.displayItems(60);
					cout << "\n" << endl;
					game.displayInv(false);
					cout << "\nType '0' to return." << endl;
					cout << "Select item to Sell : ";

					cin >> selection;

					system("cls");

					if (selection == 0)
					{
						break;
					}

					else if (cin.fail())
					{
						cout << " invalid input." << endl;
						cin.clear();
						cin.ignore(10000, '\n');
					}

					else
					{
						game.shoppingSell(selection, shop);
						break;
					}
				}
				break;
			}
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
