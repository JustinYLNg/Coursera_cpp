#include "Card.hpp"
#include "Poker.hpp"

#include <algorithm>

void Poker::initDeck(std::vector<Card>& deck)
{
    for(int i=1; i<14; i++)
    {
        Card card_spade(suit::SPADE, i);
        deck[i - 1] = card_spade;
        Card card_heart(suit::HEART, i);
        deck[i + 13 - 1] = card_heart;
        Card card_diamond(suit::DIAMOND, i);
        deck[i + 26 - 1] = card_diamond;
        Card card_club(suit::CLUB, i);
        deck[i + 39 - 1] = card_club;
    }
}

void Poker::printDeck(std::vector<Card>& deck)
{
    int counter = 0;
    for (std::vector<Card>::iterator it = deck.begin(); it != deck.end(); it++)
    {
        std::cout << *it << " ";
        counter++;
        if(counter%13 == 0)
        {
            std::cout << std::endl;
        }
    }
}

bool Poker::isFlush(std::vector<Card> &hand)
{
    //5 cards on hand are of the same suit, not necessarily sequential
    //pivot at first card
    suit s = hand[0].get_suit();

    for (auto it = hand.begin() + 1; it != hand.end(); it++)
    {
        //start looping from second card
        if(s!=it->get_suit())
        {
            return false;
        }
    }
    return true;
}

bool Poker::isStraight(std::vector<Card> &hand)
{
    //sort the 5 cards on hand
    //check consecutiveness
    int pips_hand[5];
    int i = 0;
    for (auto it = hand.begin(); it != hand.end(); it++)
    {
        pips_hand[i++] = (it->get_pips()).get_pips();
    }
    std::sort(pips_hand, pips_hand + 5);
    if(pips_hand[0] == 1)
    {
        return (pips_hand[1] == pips_hand[0] + 1) && (pips_hand[2] == pips_hand[1] + 1) &&
                   (pips_hand[3] == pips_hand[2] + 1) && (pips_hand[4] == pips_hand[3] + 1) ||
               (pips_hand[1] == 10) && (pips_hand[2] == 11) && (pips_hand[3] == 12) && 
               (pips_hand[4] == 13);    //because it is sorted in ascending order
    }
    else
    {
        return (pips_hand[1] == pips_hand[0] + 1) && (pips_hand[2] == pips_hand[1] + 1) &&
               (pips_hand[3] == pips_hand[2] + 1) && (pips_hand[4] == pips_hand[3] + 1);
    }
}

bool Poker::isStraightFlush(std::vector<Card> &hand)
{
    return isStraight(hand) && isFlush(hand);
}