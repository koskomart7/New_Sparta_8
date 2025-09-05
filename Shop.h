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

    void displayItems() const;

    void buyItem(int index, Character* player);

    int sellItem(int index, vector<Item*> invantory);
};