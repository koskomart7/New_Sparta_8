#include "Shop.h"
#include "Character.h"
#include "Item.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

Shop::Shop()
{
	stock_.push_back(new HealthPotion());
	stock_.push_back(new AttackBoost());
}

void Shop::displayItems() const
{
    for (int i = 0; i < stock_.size(); i++)
    {
        stock_[i]->getName();
        stock_[i]->getPrice();
    }
}

void Shop::buyItem(int index, Character & player)
{
    if (player.getGold() >= (*stock_[index]).getPrice())
    {
        player.addItem(stock_[index]);
        player.addGold(stock_[index]->getPrice());
    }
}

int Shop::sellItem(int index, vector<Item>& invantory)
{
    for (int i = 0; i < stock_.size(); i++)
    {
        if (invantory[index].getName() == stock_[i]->getName())
        {
            return stock_[i]->getPrice();
        }
    }
}