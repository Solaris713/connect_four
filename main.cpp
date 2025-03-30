#include "Game.h"

using namespace std;

int main() {
    int rows = 6;
    int cols = 7;
    bool continuePlaying = true;

    while (continuePlaying) {
        Game game(rows, cols);
        game.play();
        continuePlaying = game.playAgain(); // Ask if the players want to play again
        if (!continuePlaying) {
            cout << "\nThank you for playing! Goodbye!\n\n";
        }
    }

    cout << "Press Enter to exit...";
    cin.ignore();
    cin.get(); // Wait for the user to press Entry

    return 0;
}
