#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include <string>

using namespace std;

class Game {
public:
    Game(int rows, int cols);
    void play();
    bool playAgain();

private:
    Board board;
    int currentPlayer;
    char players[2]; // Array for player pieces ('X' and 'O')
    string playerNames[2]; // Array for player names
};

#endif // GAME_H

