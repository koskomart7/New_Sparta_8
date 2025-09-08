#include <iostream>

#include "rangeRd.h"
#include "GameManager.h"
#include "Shop.h"

int main()
{
    srand((unsigned int)time(NULL)); //set random seed from system time.

    GameManager game(characterCreation());
    Shop shop;
    
    while (true) {
        int selection = callMainMenu();

        switch (selection)
        {
        case 1:
            callPlayerMenu(game);
            break;

        case 2:
            game.battle();
            break;

        case 3:
            callShopMenu(game, shop);
            break;

        case 4:
            return 0;

        default:
            break;
        }
    }
}
