#include "Board.h"

Board::Board(int rows, int cols) : rows(rows), cols(cols) {
    grid.resize(rows, vector<char>(cols, ' '));
}

void Board::display() const {
    cout << "\n";
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            cout << "| " << cell << " ";
        }
        cout << "|\n";
    }
    for (int col = 0; col < cols; ++col) {
        cout << "----";
    }
    cout << "-\n";
    for (int col = 1; col <= cols; ++col) {
        cout << "  " << col << " ";
    }
    cout << "\n\n";
}


bool Board::dropPiece(int col, char piece) {
    if (col < 0 || col >= cols) {
        throw out_of_range("Column out of range! Please select another column!");
    }
    for (int row = rows - 1; row >= 0; --row) {
        if (grid[row][col] == ' ') {
            grid[row][col] = piece;
            return true;
        }
    }
    return false; // Column is full
}

bool Board::checkWin(char piece) const {
    return checkHorizontal(piece) || checkVertical(piece) || checkDiagonal(piece);
}

int Board::getCols() const {
    return cols;
}

bool Board::checkHorizontal(char piece) const {
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols - 3; ++col) {
            if (grid[row][col] == piece &&
                grid[row][col + 1] == piece &&
                grid[row][col + 2] == piece &&
                grid[row][col + 3] == piece) {
                return true;
            }
        }
    }
    return false;
}

bool Board::checkVertical(char piece) const {
    for (int col = 0; col < cols; ++col) {
        for (int row = 0; row < rows - 3; ++row) {
            if (grid[row][col] == piece &&
                grid[row + 1][col] == piece &&
                grid[row + 2][col] == piece &&
                grid[row + 3][col] == piece) {
                return true;
            }
        }
    }
    return false;
}

bool Board::checkDiagonal(char piece) const {
    for (int row = 3; row < rows; ++row) {
        for (int col = 0; col < cols - 3; ++col) {
            if (grid[row][col] == piece &&
                grid[row - 1][col + 1] == piece &&
                grid[row - 2][col + 2] == piece &&
                grid[row - 3][col + 3] == piece) {
                return true;
            }
        }
    }
    for (int row = 0; row < rows - 3; ++row) {
        for (int col = 0; col < cols - 3; ++col) {
            if (grid[row][col] == piece &&
                grid[row + 1][col + 1] == piece &&
                grid[row + 2][col + 2] == piece &&
                grid[row + 3][col + 3] == piece) {
                return true;
            }
        }
    }
    return false;
}
