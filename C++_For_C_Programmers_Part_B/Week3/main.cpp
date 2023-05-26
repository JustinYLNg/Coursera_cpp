/*
 * Author: Justin Ng
 * Created: 23 May 2023
 * Email: justinngyl@gmail.com
 * 
 */
#include <iostream>
#include <stdexcept>

#include "TicTacToe.hpp"

int main()
{
    /* //demo
    //For debugging purposes
    //TicTacToe game;
    //demo for naught vertical win
    // game.setNaught(0);
    // game.setCross(1);
    // game.setNaught(3);
    // game.setCross(5);
    // game.setNaught(6);

    //demo for naught major diagonal win
    // game.setNaught(0);
    // game.setCross(1);
    // game.setNaught(4);
    // game.setCross(2);
    // game.setNaught(8);

    //demo for cross horizontal win
    // game.setNaught(0);
    // game.setCross(6);
    // game.setNaught(4);
    // game.setCross(7);
    // game.setNaught(2);
    // game.setCross(8);

    //demo for a tie
    // game.setNaught(0);
    // game.setCross(1);
    // game.setNaught(2);
    // game.setCross(3);
    // game.setNaught(4);
    // game.setCross(5);
    // game.setNaught(6);
    // game.setCross(7);
    // game.setNaught(8);
    
    //demo output
    // game.displayBoard(std::cout);
    // char winner = game.chkWin();
    // std::cout << winner << std::endl;
    */
   
    TicTacToe playGame;
    //initialize tic tac toe board and instructions
    std::cout << "=========== Tic Tac Toe ===========" << std::endl;
    playGame.displayBoardAndInstructions(std::cout);

    State player;
    State com;

    int move;
    int choice;
    char gameState;

    while (1)
    {
        //defining O to go first, X to go second always
        std::cout << "Play as O [1] or X [2]?" << std::endl;
        std::cin >> choice;
        if(choice == 1 || choice == 2)
        {
            break;
        }
        std::cout << "Please enter 1 or 2." << std::endl;
    }

    if(choice%=2)
    {
        //player as O, computer as X
        //player goes first, computer goes second
        player = State::NAUGHT;
        com = State::CROSS;
        while(1)
        {
            playGame.playerToPlay(player, &move);
            playGame.displayBoardAndInstructions(std::cout);
            std::cout << "You played: " << move << '\n' << std::endl;
            gameState = playGame.checkWin();
            if (gameState != '-')
            {
                break;
            }
            //move = playGame.findBestMove(com);
            move = playGame.findBestMoveWithAlphaBeta(com);
            playGame.displayBoardAndInstructions(std::cout);
            std::cout << "The computer selects square " << move << std::endl;
            gameState = playGame.checkWin();
            if (gameState != '-')
            {
                break;
            }
        }
        if(gameState != '=')
        {
            std::cout << '\n' << gameState << " wins!" << std::endl;
        }
        else{
            std::cout << '\n' << "It is a tie!" << std::endl;
        }
    }
    else
    {
        //computer as O, player as X
        //computer goes first, player goes second
        com = State::NAUGHT;
        player = State::CROSS;
        while (1)
        {
            //move = playGame.findBestMove(com);
            move = playGame.findBestMoveWithAlphaBeta(com);
            playGame.displayBoardAndInstructions(std::cout);
            std::cout << "The computer selects square " << move << std::endl;
            gameState = playGame.checkWin();
            if (gameState != '-')
            {
                break;
            }
            playGame.playerToPlay(player, &move);
            playGame.displayBoardAndInstructions(std::cout);
            std::cout << "You played: " << move << '\n' << std::endl;
            gameState = playGame.checkWin();
            if (gameState != '-')
            {
                break;
            }
        }
        if (gameState != '=')
        {

            std::cout << '\n' << gameState << " wins!" << std::endl;
        }
        else{
            std::cout << '\n' << "It is a tie!" << std::endl;
        }
    }
    
    return 0;
}