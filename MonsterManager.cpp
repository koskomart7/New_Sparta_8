#include <iostream>

#include "MonsterManager.h"
#include "rangeRd.h"

#include "Monster.h"
#include "Goblin.h"
#include "Orc.h"
#include "Troll.h"
#include "BossMonster.h"
#include "MonsterManager.h"

Monster* spawnMonster(int playerLevel)
{
	Monster* monster = nullptr;
	int enemyLv = 0;

	if (playerLevel <= 2)
	{
		enemyLv = playerLevel + randomRange(0, 2);
	}

	else
	{
		enemyLv = playerLevel + randomRange(-3, 3);
	}

	while (!monster)
	{
		switch (randomRange(1, 4))
		{
		case 1:
			monster = new Goblin(enemyLv);
			break;

		case 2:
			monster = new Orc(enemyLv);
			break;

		case 3:
			monster = new Troll(enemyLv);
			break;

		default:
			break;
		}
	}
	return monster;
}

Monster* spawnBoss()
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

int monsterType(Monster* target)
{
	int idx;

	if (dynamic_cast<Goblin*>(target))
	{
		idx = 0;
	}

	else if (dynamic_cast<Orc*>(target))
	{
		idx = 1;
	}

	else if (dynamic_cast<Troll*>(target))
	{
		idx = 2;
	}

	return idx;
}
