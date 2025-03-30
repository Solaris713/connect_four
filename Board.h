#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Board {
public:
    Board(int rows, int cols);
    void display() const;
    bool dropPiece(int col, char piece);
    bool checkWin(char piece) const;
    int getCols() const;

private:
    int rows, cols;
    vector<vector<char>> grid;

    bool checkHorizontal(char piece) const;
    bool checkVertical(char piece) const;
    bool checkDiagonal(char piece) const;
};

#endif // BOARD_H
