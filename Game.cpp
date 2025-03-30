#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(int rows, int cols) : board(rows, cols), currentPlayer(0) {
    players[0] = 'X';
    players[1] = 'O';

    cout << "\nEnter a name for Player 1 (X): ";
    cin >> playerNames[0];
    cout << "Enter a name for Player 2 (O): ";
    cin >> playerNames[1];
}

void Game::play() {
    int col;
    while (true) {
        board.display();
        cout << playerNames[currentPlayer] << " (" << players[currentPlayer] << "), enter column (1-" << board.getCols() << "): ";
        cin >> col;

        col -= 1; // Convert the input column from 1-7 to 0-6

        try {
            if (board.dropPiece(col, players[currentPlayer])) {
                if (board.checkWin(players[currentPlayer])) {
                    board.display();
                    cout << playerNames[currentPlayer] << " wins!\n\n";
                    return; // End the game
                } else {
                    currentPlayer = (currentPlayer + 1) % 2; // Switch players
                }
            } else {
                cout << "Column is full! Try another column.\n";
            }
        } catch (const out_of_range& e) {
            cout << e.what() << "\n";
        }
    }
}

bool Game::playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
