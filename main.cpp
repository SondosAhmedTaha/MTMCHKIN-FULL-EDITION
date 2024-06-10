#include "Mtmchkin.h"

#include <exception>
#include <iostream>

using std::string;
using std::cout;
using std::exception;

int main()
{
    string deckFile("deck.txt");
    try
    {
        Mtmchkin Game(deckFile);
        while(!Game.isGameOver())
        {
            Game.playRound();
            Game.printLeaderBoard();

        }
    }
    catch (const exception& e)
    {
        cout << e.what();
    }
}