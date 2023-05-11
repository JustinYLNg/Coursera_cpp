#include "HexBoard.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

//AI vs AI
//Player with black connects horizontally (west, east)
//Player with white connects vertically (north, south)

int main()
{
    const int board_size = 7;
    HexBoard hexBoard(board_size);
    std::cout << "Initializing hex board" << std::endl;
    hexBoard.displayBoard(std::cout);

    std::srand(std::time(NULL));
    int turns = 0;
    bool player = 0;
    int playX;
    int playY;

    while(1)
    {
        turns++;
        player = !player;
        //player 1 with black
        if(player)
        {
            do
            {
                playX = std::rand()%board_size;
                playY = std::rand()%board_size;
            } while(!hexBoard.placeStone(Player::BLACK, playX, playY));
            
            std::cout << "Black plays (" << playX << ", " << playY << ")" << std::endl;
            
        }
        else
        {
            do
            {
                playX = std::rand()%board_size;
                playY = std::rand()%board_size;
            } while(!hexBoard.placeStone(Player::WHITE, playX, playY));
            
            std::cout << "White plays (" << playX << ", " << playY << ")" << std::endl;
        }
        if(hexBoard.checkWin(playX, playY))
        {
            std::cout << (player? "Black " : "White ") << "wins!" << std::endl;
            std::cout << "Number of turns passed: " << turns << std::endl;
            hexBoard.displayBoard(std::cout);
            break;
        }
    }

    return 0;
}