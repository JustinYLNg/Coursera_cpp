#include "HexBoard.hpp"

#include <assert.h>
#include <queue>
#include <utility>

const int HexBoard::moves[6][2] =
    {
        {0, -1}, {1, -1}, //top left, top right
        {-1, 0}, {1, 0}, //left, right
        {-1, 1}, {0, 1} //bottom left, bottom right
};

bool HexBoard::withinBoard(int x, int y) const
{
    return x >= 0 && x < size && y >= 0 && y < size;
}

//check if (x,y) is at border of the board
void HexBoard::atBorder(char stone_color, int x, int y, std::vector<bool> &flags)
{
    /* touching border at each end
     * > black : [0][y] && [size - 1][y]
     * > white : [x][size - 1] &&[x][0]
     */
    //vector flags stores boolean value for whether black/white stone is placed at (x,y)
    if (stone_color == Black)
    {
        if (x == 0)
            flags[0] = true;
        if (x == size - 1)
            flags[1] = true;
    }
    else if (stone_color == White)
    {
        if (y == 0)
            flags[0] = true;
        if (y == size - 1)
            flags[1] = true;
    }
}

//place stone at (x,y), returns true if succeed
bool HexBoard::placeStone(Player p, int x, int y)
{
    //check if the move being played is within board boundary
    if(withinBoard(x, y) == false)
        return false;
    
    //check if the move being played is legal or not
    if(board[x][y] != Blank)
        return false;
    
    if(p == Player::BLACK)
        board[x][y] = Black;
    else if(p == Player::WHITE)
        board[x][y] = White;
    return true;
}

//undo a wrong move
bool HexBoard::undoMove(int x, int y)
{
    //check if the move being played is within board boundary
    if (withinBoard(x, y) == false)
        return false;
    board[x][y] = Blank;
    return true;
}

//check which player wins
bool HexBoard::checkWin(int x, int y)
{
    //referenced https://www.programiz.com/dsa/graph-bfs
    if(withinBoard(x, y) == false && board[x][y] == Blank)
        return false;

    char stone_color = board[x][y];
    std::vector<std::vector<bool>> visited(size, std::vector<bool>(size));
    std::queue<std::pair<int, int>> unvisited;
    std::vector<bool> flags(2, false);

    visited[x][y] = true;
    unvisited.push(std::make_pair(x, y));

    while(!unvisited.empty())
    {
        std::pair<int, int> top = unvisited.front();
        atBorder(stone_color, top.first, top.second, flags);
        unvisited.pop();

        for(int n=0; n<6; n++)
        {
            int neighborOfX = top.first + moves[n][0];
            int neighborOfY = top.second + moves[n][1];
            if (withinBoard(neighborOfX, neighborOfY) && board[neighborOfX][neighborOfY] == stone_color 
                && visited[neighborOfX][neighborOfY] == false)
            {
                visited[neighborOfX][neighborOfY] = true;
                unvisited.push(std::make_pair(neighborOfX, neighborOfY));
            }
                
        }
    }
    return flags[0] && flags[1];
}

//print the hex board
void HexBoard::displayBoard(std::ostream& out)
{
    assert(size > 0);

    std::string padding = "\t\t";
    std::string spaces = "";

    //first row is x-coordinates
    out << padding << " ";
    for(int i=0; i<size; i++)
    {
        out << " " << i;
    }
    out << std::endl;
    //out << padding;
    for(int j=0; j<size; j++)
    {
        out << padding << spaces << j;
        spaces+=" ";
        for(int i=0; i<size; i++)
        {
            out << " " << board[i][j];
        }
        out << " " << j << std::endl;
    }
    out << padding << spaces;
    for(int i=0; i<size; i++)
    {
        out << " " << i;
    }
    out << std::endl;
}
