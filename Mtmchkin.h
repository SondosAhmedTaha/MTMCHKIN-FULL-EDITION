#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include <string>
#include <fstream>
#include <deque>
#include <memory>
#include <map>

#include "Exception.h"
#include "utilities.h"
#include "Cards/Card.h"

const int MAX_PLAYERS=6;
const int MIN_PLAYERS =2;
const int MIN_CARDS =5;


class Mtmchkin{

public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;


private:
    int m_NumOfrounds;

    std::map<std::string,std::unique_ptr<Player>> m_PlayersJobs;

    std::deque<std::unique_ptr<Player>> m_PlayersIN;
    std::deque<std::unique_ptr<Player>> m_Losers_Queue;
    std::deque<std::unique_ptr<Player>> m_Winners_Queue;

    std::map<std::string,std::unique_ptr<Card>> m_Cardskinds;

    deque<unique_ptr<Card>> m_DeckOfCards;
    Mtmchkin& operator=(Mtmchkin&) = delete;// Assigment operator
    Mtmchkin(const Mtmchkin&) = delete;// Copy Constructor

};



#endif /* MTMCHKIN_H_ */