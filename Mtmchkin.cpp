#include "Mtmchkin.h"
#include <iostream>

#include "Cards/Witch.h"
#include "Cards/Gremlin.h"
#include "Cards/Dragon.h"
#include "Cards/Mana.h"
#include "Cards/Barfight.h"
#include "Cards/Well.h"
#include "Cards/Treasure.h"
#include "Cards/Merchant.h"

using std::ifstream;
using std::string;
using std::map;
using std::deque;
using std::cin;
using namespace std;


/**  Helping Functions */
void Fill_CardsKind(std::map<std::string, std::unique_ptr<Card>>& CardsKinds){//the function fills the the cards types in CardsKinds
    CardsKinds.emplace("Witch", std::unique_ptr<Card>(new Witch()));
    CardsKinds.emplace("Gremlin", std::unique_ptr<Card>(new Gremlin()));
    CardsKinds.emplace("Dragon", std::unique_ptr<Card>(new Dragon()));
    CardsKinds.emplace("Mana", std::unique_ptr<Card>(new Mana()));
    CardsKinds.emplace("Barfight", std::unique_ptr<Card>(new Barfight()));
    CardsKinds.emplace("Well", std::unique_ptr<Card>(new Well()));
    CardsKinds.emplace("Treasure", std::unique_ptr<Card>(new Treasure()));
    CardsKinds.emplace("Merchant", std::unique_ptr<Card>(new Merchant()));
}

void Fill_PlayersJobs(map<string,std::unique_ptr<Player>>& PlayersJobs)//the function fills the the player types in PlayersJobs
{
    std::unique_ptr<Healer> Healer(new  class Healer("Healer"));
    std::unique_ptr<Ninja> Ninja(new  class Ninja("Ninja"));
    std::unique_ptr<Warrior> Warrior(new   class Warrior("Warrior"));

    PlayersJobs["Healer"] = std::move(Healer);
    PlayersJobs["Ninja"] = std::move(Ninja);
    PlayersJobs["Warrior"] = std::move(Warrior);
}
int get_NumOfPlayers() {//the function gets from the user the number of the players in the game and checks if it is legal
    string input;
    int NumOfPlayers = 0;
    while (NumOfPlayers == 0) {
        std::getline(std::cin, input);
        try {
            NumOfPlayers = std::stoi(input);
        } catch (...) {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
            continue;
        }
        if (!(NumOfPlayers >= MIN_PLAYERS && NumOfPlayers <= MAX_PLAYERS)) {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
            NumOfPlayers = 0;
            continue;
        }
    }

    return NumOfPlayers;
}
bool Check_playerName(const std::string& playerName) {//the function checks if the player name is valid
    if (playerName.length() <= 15) {
        string::size_type index;
        for (index = 0; index < playerName.length(); index++) {
            if (!((playerName[index] >= 'A' && playerName[index] <= 'Z') || (playerName[index] >= 'a' && playerName[index] <= 'z'))) {
                break;
            }
        }
        if (index == playerName.length()) {
            return true;
        }
    }
    return false;
}

bool git_PlayerINFO(string& playerName, string& playerJob) {
    string line;
    if (!getline(cin, line)) {
        return false;
    }

    playerName.clear();
    playerJob.clear();

    bool NameDone = false;
    bool NameBegin = false;
    bool JobDone = false;
    bool JobBegin = false;

    for (char ch : line) {
        if (ch == ' ' ) {
            if(NameBegin)
                NameDone= true;
            if(JobBegin)
                JobDone= true;
        }
        else {
            if(JobDone){
                return false;
            }
            if (NameDone) {
                playerJob += ch;
                JobBegin= true;
                continue;
            }
            playerName += ch;
            NameBegin= true;

        }
    }

    if (playerName.empty() || playerJob.empty()) {
        return false;
    }

    return true;
}

void Fill_PlayersIN(std::deque<std::unique_ptr<Player>>& PlayersIN, std::map<std::string, std::unique_ptr<Player>>& PlayersJobs) {//the function  gets the data for the players,and sets everything up so we can use them.
    printEnterTeamSizeMessage();
    int NumOfPlayers = get_NumOfPlayers();
    std::string playerName, playerJob;
    while (NumOfPlayers > 0) {
        printInsertPlayerMessage();

        while (true) {
            if (!git_PlayerINFO(playerName, playerJob)) {
                printInvalidInput();
                continue;
            }
            if (!Check_playerName(playerName)) {
                printInvalidName();
                continue;
            }
            if (PlayersJobs.find(playerJob) == PlayersJobs.end()) {
                printInvalidClass();
                continue;
            }
            break;
        }
        NumOfPlayers--;
        Player* player = PlayersJobs[playerJob]->clone();
        player->setName(playerName);
        std::unique_ptr<Player> playerPtr(player);
        PlayersIN.push_back(std::move(playerPtr));
    }
}
bool git_cardKind(string& line, string& cardKind) {
    bool cardKind_Begin = false;
    bool cardKind_Done = false;
    cardKind.clear();

    for (char ch : line) {
        if (ch == ' ') {
            if (cardKind_Begin && !cardKind_Done) {
                cardKind_Done = true;
            }
        }
        else {
            if (cardKind_Done) {
                return false;
            }

            cardKind += ch;
            cardKind_Begin = true;
        }
    }

    if (cardKind.empty()) {
        return false;
    }

    return true;
}

bool isLineOnlySpaces(const std::string& line) {
    for (char ch : line) {
        if (ch != ' ') {
            return false;
        }
    }
    return true;
}

void Fill_CardsIN(std::ifstream& Cardsource, std::map<std::string, std::unique_ptr<Card>>& CardsKinds, std::deque<std::unique_ptr<Card>>& DeckOfCards) {
    std::string cardKind, line;
    int LineNum = 1;
    int Cards_Num = 0;
    int firstEmpty_line = 0;
    bool previousLineEmpty = false;

    while (std::getline(Cardsource, line)) {
        if (isLineOnlySpaces(line)) {
            if (!previousLineEmpty) {
                firstEmpty_line = LineNum;
            }
            previousLineEmpty = true;
            LineNum++;
            continue;
        }
        previousLineEmpty = false;

        if (git_cardKind(line, cardKind)) {
            if (!cardKind.empty()) {
                if (firstEmpty_line != 0) {
                    throw DeckFileFormatError(firstEmpty_line);
                }
                if (CardsKinds.find(cardKind) == CardsKinds.end()) {
                    throw DeckFileFormatError(LineNum);
                }

                Cards_Num++;
                Card* new_card = CardsKinds[cardKind]->clone();
                std::unique_ptr<Card> Card_Ptr(new_card);
                DeckOfCards.push_back(std::move(Card_Ptr));
            }
        } else {
            throw DeckFileFormatError(LineNum);
        }

        LineNum++;
    }

    if (Cards_Num < MIN_CARDS) {
        throw DeckFileInvalidSize();
    }
}

////////////////////////////////////////////////////////////////////
Mtmchkin:: Mtmchkin(const string &fileName): m_NumOfrounds(0),
                                             m_PlayersJobs(),
                                             m_PlayersIN(),
                                             m_Losers_Queue(),
                                             m_Winners_Queue(),
                                             m_Cardskinds(),
                                             m_DeckOfCards()
{
    printStartGameMessage();
    Fill_CardsKind(m_Cardskinds);
    ifstream Cardsource (fileName);

    if(!Cardsource)
    {
        throw DeckFileNotFound(); //exeption
    }
    try
    {
        Fill_CardsIN(Cardsource,m_Cardskinds,m_DeckOfCards);
    }
    catch (const DeckFileFormatError& e)
    {
        throw e;
    }
    catch (const DeckFileInvalidSize& e)
    {
        throw e;
    }

    Fill_PlayersJobs(m_PlayersJobs);
    Fill_PlayersIN(m_PlayersIN,m_PlayersJobs);
}
int Mtmchkin:: getNumberOfRounds() const{
    return m_NumOfrounds;
}
bool Mtmchkin:: isGameOver() const
{
    if(m_PlayersIN.empty()){
        return true;
    }
    return false;
}
void Mtmchkin:: playRound(){
    m_NumOfrounds++;
    printRoundStartMessage(m_NumOfrounds);

    for (std::deque<std::unique_ptr<Player>>::iterator it = m_PlayersIN.begin(); it != m_PlayersIN.end(); ) {
        printTurnStartMessage((*it)->getName());
        m_DeckOfCards.front()->applyEncounter(*(*it));
        m_DeckOfCards.push_back(std::move(m_DeckOfCards.front()));
        m_DeckOfCards.pop_front();

        if ((*it)->isKnockedOut()) {
            m_Losers_Queue.push_front(std::move(*it));
            it = m_PlayersIN.erase(it);
        } else {
            if ((*it)->getLevel() == 10) {
                m_Winners_Queue.push_back(std::move(*it));
                it = m_PlayersIN.erase(it);
            } else {
                ++it;
            }
        }
    }
    if(isGameOver()){
        {
            printGameEndMessage();
        }
    }
}
void Mtmchkin:: printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int rank_num=0;
    for(const std::unique_ptr<Player>& curr_player : m_Winners_Queue)
    {
        rank_num++;
        printPlayerLeaderBoard(rank_num, *curr_player);
    }
    for(const std::unique_ptr<Player>& curr_player : m_PlayersIN)
    {
        rank_num++;
        printPlayerLeaderBoard(rank_num, *curr_player);
    }
    for(const std::unique_ptr<Player>& curr_player : m_Losers_Queue)
    {
        rank_num++;
        printPlayerLeaderBoard(rank_num, *curr_player);
    }

}