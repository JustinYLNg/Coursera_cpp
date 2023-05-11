#include "Card.hpp"
#include "Poker.hpp"

#include <algorithm>
#include <assert.h>
#include <cstdlib>

void Poker::initDeck(std::vector<Card>& deck)
{
    for(suit s=(suit)0; s <= suit::SPADE; s = static_cast<suit>((size_t)s + 1))
    {
        for(int p=1; p<=13; p++)
        {
            Card c(s, p);
            deck.push_back(c);
        }
    }
}

void Poker::shuffleDeck(std::vector<Card> &deck)
{
    for(int i=0; i<deck.size(); i++)
    {
        int random_index = rand()%(52-1);   //[0,51]
        if(i!=random_index)
        {
            Card temp = deck[i];
            deck[i] = deck[random_index];
            deck[random_index] = temp;
        }

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
    assert(hand.size() == 5);
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

bool Poker::is_N_Of_A_Kind(std::vector<Card>& hand, int n)
{
    //bucket count
    int bins[13] = {0};
    for(int i=0; i<hand.size(); i++)
    {
        int pip = (hand[i].get_pips()).get_pips();
        bins[pip-1]++;
    }
    for(int i=0; i<13; i++)
    {
        if(bins[i] == n)
        {
            return true;
        }
    }
    return false;
}