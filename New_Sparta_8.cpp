#include <iostream>

#include "rangeRd.h"
#include "GameManager.h"

int main()
{
    srand((unsigned int)time(NULL)); //set random seed from system time.

    for (int i = 0; i < 10; i++)
    {
        std::cout << randomRange(1, 10) << std::endl; // Testing randomRange()
    }

    GameManager game(characterCreation());
    
    while (true) {
        int selection = callMainMenu();

        switch (selection)
        {
        case 1:
            callPlayerMenu(game);
            break;
        case 2:
            // battle here
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
