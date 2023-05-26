#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP

#include <iostream>
#include <unordered_map>

enum class State : char
{
    BLANK = '-',
    NAUGHT = 'O',       //go first
    CROSS = 'X'         //go second
    
};

class TicTacToe
{
    public:
        //constructor initializing board as a 1D array
        TicTacToe() : board(new char[size * size])
        {
            for (int i = 0; i<size*size; i++)
            {
                board[i] = BLANK;
            }
        }

        //display tic-tac-toe board and its instructions
        void displayBoardAndInstructions(std::ostream &out);

        //check if either player has won
        char checkWin();

        //for AI to find optimal move
        int findBestMove(State p);

        //for AI to find optimal move - with alpha-beta pruning
        int findBestMoveWithAlphaBeta(State p);

        //temporary function to set board[n] to naught
        void setNaught(int n);

        //temporary function to set board[n] to cross
        void setCross(int n);

        //method for player to play a move
        void playerToPlay(State p, int *move);

    private:
        const int size = 3;
        char* board;

        const char CROSS = 'X';
        const char NAUGHT = 'O';
        const char TIE = '=';
        const char BLANK = '-';

        //assume AI will go second with X
        //X is minimizer
        std::unordered_map<char, int> scoreMap =
        {
            {'O', 1},
            {'=', 0},
            {'X', -1},
        };

        //wrapper function for player to play move n
        bool playMove(State p, int n);

        //helper function for checkWin
        char checkLines(int n, int step);

        //check if move is within grid boundary
        bool withinBoard(int n);

        //check if move is legal, meaning if the move to be played is on a blank square
        bool isLegal(int n);

        //wrapper function for above two withinBoard and isLegal combined
        bool isValid(int n);

        //check if the board is filled
        bool isFilled();

        //implements minimax algorithm without alpha-beta pruning
        int minimax(int depth, bool isMaximizer);

        //implements minimax algorithm with alpha-beta pruning
        int minimaxWithAlphaBetaPruning(int depth, bool isMaximizer, int alpha, int beta);

        const int INF = 99999;
};

#endif //TIC_TAC_TOE_HPP
