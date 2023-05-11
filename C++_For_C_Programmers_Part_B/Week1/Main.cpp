#include "HexGame.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

//Player vs AI
// Player with black connects horizontally(west, east)
//Player with white connects vertically (north, south)

    int main()
{
    const int board_size = 7;
    HexGame hexBoard(board_size);
    std::cout << "Initializing hex board" << std::endl;
    hexBoard.displayBoard(std::cout);
    
    std::srand(std::time(NULL));
    Player p;
    Player com;
    bool winFlag = false;
    int turns = 0;
    int playX;
    int playY;

    int choice;
    //Player can choose to go first or second
    while(1)
    {
        std::cout << "Play with Black[1] or White [2]?" << std::endl;
        std::cin >> choice;
        if(choice == 1 || choice == 2)
        {
            break;
        }
        std::cout << "Please enter either 1 or 2" << std::endl;
    }
    //player chooses to go first
    if(choice %= 2)
    {
        p = Player::BLACK;
        com = Player::WHITE;

        while(!winFlag)
        {
            turns++;
            hexBoard.playerToPlay(p, &playX, &playY);
            hexBoard.displayBoard(std::cout);
            hexBoard.win(choice, &playX, &playY, winFlag, &turns);
            if(winFlag == true)
            {
                break;
            }
            hexBoard.computerToPlay(com, &playX, &playY);
            hexBoard.displayBoard(std::cout);
            hexBoard.win(!choice, &playX, &playY, winFlag, &turns);
        }

    }
    //player chooses to go second
    else
    {
        com = Player::BLACK;
        p = Player::WHITE;

        while(!winFlag)
        {
            turns++;
            hexBoard.computerToPlay(com, &playX, &playY);
            hexBoard.displayBoard(std::cout);
            hexBoard.win(!choice, &playX, &playY, winFlag, &turns);
            if (winFlag == true)
            {
                break;
            }
            hexBoard.playerToPlay(p, &playX, &playY);
            hexBoard.displayBoard(std::cout);
            hexBoard.win(choice, &playX, &playY, winFlag, &turns);
        }
    }
    return 0;
}