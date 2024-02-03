#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

std::vector<std::string> split(const std::string &s, char delimiter)
{
    std::vector<std::string> tokens;
    std::istringstream tokenStream(s);
    std::string token;
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}
class Card
{
public:
    char suit;
    std::string value;
    std::string allValues = "23456789|0jqka";

    Card(char suit, std::string value) : suit(suit), value(value) {}

    int compareTo(const Card &other) const
    {
        return allValues.find(this->value) - allValues.find(other.value);
    }
};

class Player
{
public:
    std::string name;
    std::vector<Card> cards;

    Player(std::string name) : name(name) {}

    void addCard(std::string cardStr)
    {
        this->cards.push_back(Card(cardStr[0], cardStr.substr(1)));
    }
};

class Game
{
public:
    std::map<std::string, Player> players;
    std::vector<Card> playedCards;
    char trump;
    std::vector<std::string> playerNames;

    Game(const std::vector<std::string> &playerNames, char trump) : playerNames(playerNames), trump(trump)
    {
        for (const auto &name : playerNames)
        {
            players[name] = Player(name);
        }
    }

    void addCardToPlayer(const std::string &playerName, const std::string &cardStr)
    {
        Card card(cardStr[0], cardStr.substr(1));
        players[playerName].addCard(cardStr);
        playedCards.push_back(card);
    }

    Card getOptimalCard(Player &self)
    {
        std::string teammate = (playerNames.indexOf(self.name) % 2 == 0)
                                   ? playerNames[playerNames.indexOf(self.name) + 2]
                                   : playerNames[playerNames.indexOf(self.name) - 2];

        Card highestCard = playedCards[0];
        for (const auto &card : playedCards)
        {
            if ((highestCard.suit == card.suit && card.compareTo(highestCard) > 0) || (card.suit == trump && highestCard.suit != trump))
            {
                highestCard = card;
            }
        }

        if (std::any_of(players[teammate].cards.begin(), players[teammate].cards.end(),
                        [&highestCard](const Card &c)
                        { return c.suit == highestCard.suit && c.value == highestCard.value; }))
        {
            return getSmallestCard(self.cards, '0');
        }

        if (highestCard.suit != trump)
        {
            Card smallestBiggerCard = getSmallestCardBiggerThan(self.cards, highestCard, highestCard.suit);
            if (smallestBiggerCard != nullptr)
            {
                return smallestBiggerCard;
            }
            return getSmallestCard(self.cards, '0');
        }

        Card highestTeammateTrumpCard = getHighestCard(players[teammate].cards, trump);
        Card highestEnemyTrumpCard = nullptr;

        for (const auto &playerName : playerNames)
        {
            if (playerName == teammate || playerName == self.name)
                continue;
            const Card *tempCard = getHighestCard(players[playerName].cards, trump);
            if (tempCard != nullptr && (highestEnemyTrumpCard == nullptr || tempCard->compareTo(*highestEnemyTrumpCard) > 0))
            {
                highestEnemyTrumpCard = tempCard;
            }
        }

        if (highestTeammateTrumpCard == nullptr || (highestEnemyTrumpCard != nullptr && highestTeammateTrumpCard->compareTo(*highestEnemyTrumpCard) > 0))
        {
            Card *smallestTrumpHigherThanEnemy = getSmallestCardBiggerThan(self.cards, highestEnemyTrumpCard, trump);
            if (smallestTrumpHigherThanEnemy != nullptr)
            {
                return *smallestTrumpHigherThanEnemy;
            }
        }

        return getSmallestCard(self.cards, trump);
    }

    Card *getHighestCard(const std::vector<Card> &cards, char suit)
    {
        std::vector<Card> sortedCards = cards;
        std::sort(sortedCards.begin(), sortedCards.end(), [](const Card &a, const Card &b)
                  { return b.compareTo(a) > 0; });

        for (const auto &card : sortedCards)
        {
            if (card.suit == suit)
            {
                return const_cast<Card *>(&card);
            }
        }
        return nullptr;
    }

    Card *getSmallestCard(const std::vector<Card> &cards, char suit)
    {
        std::vector<Card> sortedCards = cards;
        std::sort(sortedCards.begin(), sortedCards.end(), [](const Card &a, const Card &b)
                  { return a.compareTo(b) < 0; });

        for (const auto &card : sortedCards)
        {
            if (suit == '0' || card.suit == suit)
            {
                return const_cast<Card *>(&card);
            }
        }
        return nullptr;
    }

    Card *getSmallestCardBiggerThan(const std::vector<Card> &cards, const Card &targetCard, char targetSuit)
    {
        Card *smallestBiggerCard = nullptr;
        for (const auto &card : cards)
        {
            if (card.suit == targetSuit && card.compareTo(targetCard) > 0)
            {
                if (smallestBiggerCard == nullptr || card.compareTo(*smallestBiggerCard) < 0)
                {
                    smallestBiggerCard = const_cast<Card *>(&card);
                }
            }
        }
        return smallestBiggerCard;
    }
};

int main()
{
    std::string inputString;
    std::getline(std::cin, inputString);

    const std::vector<std::string> components = split(inputString, ';');
    std::map<std::string, std::string> inputMap;
    for (const auto &component : components)
    {
        const size_t colonIndex = component.find(':');
        if (colonIndex != std::string::npos)
        {
            inputMap[component.substr(0, colonIndex)] = component.substr(colonIndex + 1);
        }
    }

    const std::vector<std::string> playerNames = split(inputMap["players"], ',');
    const char trump = inputMap["trump"][0];
    Game game(playerNames, trump);

    for (const auto &playerName : playerNames)
    {
        if (inputMap.find(playerName) != inputMap.end())
        {
            game.addCardToPlayer(playerName, inputMap[playerName]);
        }
    }

    Player &self = game.players[inputMap["self"]];
    const std::vector<std::string> cards = split(inputMap["cards"], ',');
    for (const auto &cardStr : cards)
    {
        self.addCard(cardStr);
    }

    const Card optimalCard = game.getOptimalCard(self);
    std::cout << optimalCard.suit << optimalCard.value;

    return 0;
}
