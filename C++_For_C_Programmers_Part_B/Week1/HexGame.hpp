/*
 *  Author:
 *  Justin Ng
 *  Email: justinngyl@gmail.com
 *  Date: 10 May 2023
 */ 
#ifndef HEX_BOARD_HPP
#define HEX_BOARD_HPP

#include <iostream>
#include <string>
#include <vector>

enum class Player
{
    BLANK,
    BLACK,
    WHITE
};

class HexGame
{
    public:
        HexGame(){}
        HexGame(int size):size(size), board(size, std::vector<char>(size, '-'))
        {
            
        }

        //place stone at (x,y), returns true if succeed
        bool placeStone(Player p, int x, int y);

        //undo a wrong move
        bool undoMove(int x, int y);

        //check which player wins
        bool checkWin(int x, int y);

        //print the hex board
        void displayBoard(std::ostream& out);

        void playerToPlay(Player p, int *x, int *y);

        void computerToPlay(Player c, int *x, int *y);

        void win(int choice, int *x, int *y, bool &flag, int* turns);

    private:
        //can move in 6 directions
        const static int moves[6][2];

        //represent no stone being placed
        const static char Blank = '-';

        //represent stone color being placed
        const static char Black = 'B';
        const static char White = 'W';

        int size;
        std::vector<std::vector<char>> board;

        //make sure the move played on (x,y) is within board boundary
        inline bool withinBoard(int x, int y) const;

        //check if (x,y) is at border of the board
        void atBorder(char stone_color, int x, int y, std::vector<bool>& flags);
};

#endif