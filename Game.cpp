#include "Game.h"
#include <iostream>
#include <limits>

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

        // Loop to validate the user's input.
        while (true) {
            cin >> col;

            // Check if the input is valid
            if (cin.fail() || col < 1 || col > board.getCols()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nInvalid input ! Please enter a number between 1 and " << board.getCols() << ".\n\n";
                cout << playerNames[currentPlayer] << " (" << players[currentPlayer] << "), enter column (1-" << board.getCols() << "): ";
            } else {
                break;
            }
        }

        col -= 1;

        try {
            if (board.dropPiece(col, players[currentPlayer])) {
                if (board.checkWin(players[currentPlayer])) {
                    board.display();
                    cout << playerNames[currentPlayer] << " wins !\n\n";
                    return;
                } else {
                    currentPlayer = (currentPlayer + 1) % 2;
                }
            } else {
                cout << "\nColumn is full ! Try another column.\n";
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
