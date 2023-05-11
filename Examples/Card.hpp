#ifndef CARD_HPP
#define CARD_HPP
#include <iostream>

#include "assert.h"

//ADT for poker cards
enum class suit : short
{
    CLUB,
    DIAMOND,
    HEART,
    SPADE
};

class pips
{
    public:
        pips(int val) : pip(val) { assert(pip > 0 && pip < 14); }
        int get_pips() const { return pip; }

    private:
        int pip;
};

class Card
{
    public:
        //default constructor
        Card():s(suit::CLUB), p(1){}
        //parameterized constructor
        Card(suit s, pips p) : s(s), p(p){}
        //overloaded bit shift operator for outputting for type Card
        friend std::ostream &operator<<(std::ostream &out, const Card &c);
        //accessor function for getting suit
        suit get_suit() { return s; }
        //setter function for setting suit
        void set_suit(suit s) { s = s;}
        //accessor function for getting pips
        pips get_pips() { return p; }
        //setter function for setting pips
        void set_pips(pips p){ p = p; }

    private:
        suit s;
        pips p;
};

std::ostream& operator << (std::ostream& out, const Card &c)
{
    out << c.p, c.s;
    return out;
}

#endif