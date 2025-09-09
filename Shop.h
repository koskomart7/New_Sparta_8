#pragma once

#include <vector>
#include <memory>
#include <cstddef>

using namespace std;

class Item;
class Character;
class Shop
{
private:
    vector<Item*> stock_;
    static const int SELL_RATE_PERCENT = 60;

public:
    Shop();
	~Shop();


    void displayItems(int sell = 100) const;
    void buyItem(int index, Character* player);
    int sellItem(int index, Character* player);
};