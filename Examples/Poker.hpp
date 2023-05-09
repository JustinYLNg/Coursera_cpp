#ifndef POKER_HPP
#define POKER_HPP
#include <vector>

#include "Card.hpp"

class Poker
{
    public:
        void initDeck(std::vector<Card> &deck);

        void printDeck(std::vector<Card> &deck);

        bool isFlush(std::vector<Card> &hand);

        bool isStraight(std::vector<Card> &hand);

        bool isStraightFlush(std::vector<Card> &hand);

    private:
};

#endif