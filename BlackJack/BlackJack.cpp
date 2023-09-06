#include "Game.h"

int main()
{
    Game game;
    bool initSetup = game.InitGame();

    if (initSetup) {
        game.GameLoop();
    }


    game.EndGame();       
   
}


