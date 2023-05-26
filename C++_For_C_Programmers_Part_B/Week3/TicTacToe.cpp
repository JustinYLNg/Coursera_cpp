#include "TicTacToe.hpp"
#include <algorithm>
#include <string>

void TicTacToe::displayBoardAndInstructions(std::ostream &out)
{
    std::string horizontalLine = "---|---|---";
    std::string space = " ";
    std::string partition = "\t\t";
    //std::string padding = "\t\t\t\t";
    int step = size;

    //out << "=========== Tic Tac Toe ===========" << std::endl;
    out << " Game Board" << partition << "Square numbers" << std::endl;

    for (int i = 0; i < size; i++)
    {
        out << space << board[i * step] << space
            << "|"
            << space << board[i * step + 1] << space
            << "|"
            << space << board[i * step + 2] << space
            << partition
            << space << std::to_string(i * step) << space
            << "|"
            << space << std::to_string(i * step + 1) << space
            << "|"
            << space << std::to_string(i * step + 2) << space
            << std::endl;
        if (i != size - 1)
        {
            out << horizontalLine << partition << horizontalLine << std::endl;
        }
    }
}

char TicTacToe::checkLines(int n, int step)
{
    char value = board[n];
    n+=step;
    if (board[n + step] == board[n] && board[n] == value)
    {
        return value;
    }
    return BLANK;
}

char TicTacToe::checkWin()
{
    char result = BLANK;    //default case is blank
    
    for(int i=0; i<size; i++)
    {
        //checking result of verticals
        if(checkLines(i,3)!=BLANK)
        {
            result = checkLines(i,3);
            break;
        }
        //checking result of horizontals
        if(checkLines(i*3,1)!=BLANK)
        {
            result = checkLines(i*3,1);
            break;
        }
    }
    //checking result of major diagonal of matrix
    if (checkLines(0, 4) != BLANK)
    {
        result = checkLines(0, 4);
    }
    //checking result of minor diagonal of matrix
    if (checkLines(2, 2) != BLANK)
    {
        result = checkLines(2, 2);
    }
    //check if all squares are filled
    if(isFilled())
    {
        result = TIE;
    }
    return result;
}

bool TicTacToe::isFilled()
{
    for(int i=0; i<size*size; i++)
    {
        if(board[i] == BLANK)
        {
            return false;
        }
    }
    return true;
}

bool TicTacToe::withinBoard(int n)
{
    return n >= 0 && n < size * size;
}

bool TicTacToe::isLegal(int n)
{
    return board[n] == BLANK;
}

bool TicTacToe::isValid(int n)
{
    return withinBoard(n) && isLegal(n);
}

bool TicTacToe::playMove(State p, int n)
{
    char symbol;
    if(p == State::BLANK)
        return false;
    if (p == State::NAUGHT)
        symbol = NAUGHT;
    if (p == State::CROSS)
        symbol = CROSS;
    board[n] = symbol;
    return true;
}

int TicTacToe::minimaxWithAlphaBetaPruning(int depth, bool isMaximizer, int alpha, int beta)
{
    char winner = checkWin();
    //terminal state
    if (winner != BLANK)
    {
        return scoreMap[winner];
    }

    if (isMaximizer)
    {
        int bestScore = -INF;
        for (int i = 0; i < size * size; i++)
        {
            //find the first available spot
            if (board[i] == BLANK)
            {
                board[i] = NAUGHT; //O is maximizer no matter player or computer chooses it
                int score = minimax(depth + 1, !isMaximizer);
                board[i] = BLANK; //reset, important for backtracking
                bestScore = std::max(score, bestScore);
                alpha = std::max(alpha, bestScore);
                if(beta <= alpha)
                {
                    break;
                }
            }
        }
        return bestScore;
    }
    else
    {
        int bestScore = INF;
        for (int i = 0; i < size * size; i++)
        {
            if (board[i] == BLANK)
            {
                board[i] = CROSS; //X is minimizer no matter player or computer chooses it
                int score = minimax(depth + 1, !isMaximizer);
                board[i] = BLANK; //reset, important for backtracking
                bestScore = std::min(score, bestScore);
                beta = std::min(beta, bestScore);
                if(beta <= alpha)
                {
                    break;
                }
            }
        }
        return bestScore;
    }
}

int TicTacToe::minimax(int depth, bool isMaximizer)
{
    char winner = checkWin();
    //terminal state
    if (winner != BLANK)
    {
        return scoreMap[winner];
    }

    if (isMaximizer)
    {
        int bestScore = -INF;
        for (int i = 0; i < size * size; i++)
        {
            //find the first available spot
            if(board[i] == BLANK)
            {
                board[i] = NAUGHT;      //O is maximizer no matter player or computer chooses it
                int score = minimax(depth + 1, !isMaximizer);
                board[i] = BLANK;       //reset, important for backtracking
                bestScore = std::max(score, bestScore);
            }
        }
        return bestScore;
    }
    else
    {
        int bestScore = INF;
        for (int i = 0; i < size * size; i++)
        {
            if (board[i] == BLANK)
            {
                board[i] = CROSS;       //X is minimizer no matter player or computer chooses it
                int score = minimax(depth + 1, !isMaximizer);
                board[i] = BLANK;       //reset, important for backtracking
                bestScore = std::min(score, bestScore);
            }
        }
        return bestScore;
    }
}

int TicTacToe::findBestMove(State p)
{
    //AI assumed to be the minimizing player
    int bestScore;
    int bestMove;
    char symbol;
    if(p == State::NAUGHT)
    {
        //maximizer case
        symbol = NAUGHT;
        bestScore = -INF;
        for (int i = 0; i < size * size; i++)
        {
            //check if the square is available
            if (board[i] == BLANK)
            {
                //AI try going there
                board[i] = symbol;
                //get the score for this particular move
                int score = minimax(0, false);
                board[i] = BLANK;
                if (score > bestScore)
                {
                    bestScore = score;
                    bestMove = i; //best move is at this particular square i
                    //break;
                }
            }
        }
        board[bestMove] = symbol;
        return bestMove;
    }
    else if(p == State::CROSS)
    {
        //minimizer case
        symbol = CROSS;
        bestScore = INF;
        for (int i = 0; i < size * size; i++)
        {
            //check if the square is available
            if (board[i] == BLANK)
            {
                //AI try going there
                //board[i] = CROSS;
                board[i] = symbol;
                //get the score for this particular move
                int score = minimax(0, true);
                board[i] = BLANK;
                if (score < bestScore)
                {
                    bestScore = score;
                    bestMove = i; //best move is at this particular square i
                    //break;
                }
            }
        }
        board[bestMove] = symbol;
        return bestMove;
    }

    //board[bestMove] = symbol;
    return bestMove;
    //change player
}

int TicTacToe::findBestMoveWithAlphaBeta(State p)
{
    //AI assumed to be the minimizing player
    int bestScore;
    int bestMove;
    char symbol;
    if (p == State::NAUGHT)
    {
        //maximizer case
        symbol = NAUGHT;
        bestScore = -INF;
        for (int i = 0; i < size * size; i++)
        {
            //check if the square is available
            if (board[i] == BLANK)
            {
                //AI try going there
                board[i] = symbol;
                //get the score for this particular move
                int score = minimaxWithAlphaBetaPruning(0, false, -INF, INF);
                board[i] = BLANK;
                if (score > bestScore)
                {
                    bestScore = score;
                    bestMove = i; //best move is at this particular square i
                    //break;
                }
            }
        }
        board[bestMove] = symbol;
        return bestMove;
    }
    else if (p == State::CROSS)
    {
        //minimizer case
        symbol = CROSS;
        bestScore = INF;
        for (int i = 0; i < size * size; i++)
        {
            //check if the square is available
            if (board[i] == BLANK)
            {
                //AI try going there
                //board[i] = CROSS;
                board[i] = symbol;
                //get the score for this particular move
                int score = minimaxWithAlphaBetaPruning(0, true, -INF, INF);
                board[i] = BLANK;
                if (score < bestScore)
                {
                    bestScore = score;
                    bestMove = i; //best move is at this particular square i
                    //break;
                }
            }
        }
        board[bestMove] = symbol;
        return bestMove;
    }

    //board[bestMove] = symbol;
    return bestMove;
    //change player
}

//simple method for debugging
void TicTacToe::setNaught(int n)
{
    if(isValid(n))
    {
        board[n] = NAUGHT;
    }
    else
    {
        throw std::invalid_argument("sqaure " + std::to_string(n) + " is already occupied. Please play another move.");
    }
}

//simple function for debugging
void TicTacToe::setCross(int n)
{
    if (isValid(n))
    {
        board[n] = CROSS;
    }
    else
    {
        throw std::invalid_argument("sqaure " + std::to_string(n) + " is already occupied. Please play another move.");
    }
}

void TicTacToe::playerToPlay(State p, int *move)
{
    while(1)
    {
        std::cout << "Your turn to play a move." << std::endl;
        std::cout << "Please enter a number between 0 to 8 (inclusive), referring to "
                     "the instruction on the right." << std::endl;
        std::cin >> *move;
        if (isValid(*move))
        {
            playMove(p, *move);
            break;
        }
        std::cout << "Invalid input, please try again." << std::endl;
    }
}
