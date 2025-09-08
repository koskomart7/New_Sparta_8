#include "Shop.h"
#include "Character.h"
#include "Item.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include <iostream>

using namespace std;

Shop::Shop()
{
	stock_.push_back(new HealthPotion());
	stock_.push_back(new AttackBoost());
}

void Shop::displayItems() const
{
    for (int i = 0; i < stock_.size(); i++)
    {
		cout << stock_[i]->getName() << " - " 
             << stock_[i]->getPrice() << "Gold\n" << endl;
    }
}

void Shop::buyItem(int index, Character* player)
{
    if  (index < 1 || stock_.size() < index)
    {
        cout << "Invalid item Item Number.\n";
        return;
	}

    if (player->getGold() >= (*stock_[index]).getPrice())
    {
		Item* item = nullptr;

        switch (index)
        {
            case 1:
				item = new HealthPotion();
                break;
			case 2:
                item = new AttackBoost();
				break;
            default:
                cout << "Invalid item Item Number.\n";
				return;
        }
		player->addItem(item);

        //player->addItem(stock_[index]);
        player->spendGold(stock_[index]->getPrice());
        cout << "Purchased complete!\n"
            << "Gold Remaining : " << player->getGold();
    }
    else
    {
        cout << "Not enough Gold.\n"
            << "Gold Remaining : " << player->getGold();
    }
}

int Shop::sellItem(int index, Character* player)
{
    if (index < 0 || index >= player->getInventory().size())
    {
        cout << "Invalid item Item Number.\n";
		return 0;
    }

    for (int i = 0; i < stock_.size(); i++)
    {
        if (player->getInventory()[index]->getName() == stock_[i]->getName())
        {
            cout << "Sold " << player->getInventory()[index]->getName() << " - "
                 << (stock_[i]->getPrice() * SELL_RATE_PERCENT) / 100 << " Gold \n";

            player->addGold((stock_[i]->getPrice() * SELL_RATE_PERCENT) / 100);
			player->getInventory().erase(player->getInventory().begin() + index);
            //delete player->getInventory()[index];
            //player->getInventory().erase(player->getInventory().begin() + index);

            return stock_[i]->getPrice() * SELL_RATE_PERCENT / 100;
        }
    }
	cout << "Item not found in shop.\n";
return 0;
}