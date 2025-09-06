#include <iostream>

#include "rangeRd.h"
#include "GameManager.h"

int main()
{
    srand((unsigned int)time(NULL)); //set random seed from system time.

    GameManager game(characterCreation());
    
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
            // shop here
            break;
        case 4:
            return 0;
        default:
            break;
        }
    }
}
