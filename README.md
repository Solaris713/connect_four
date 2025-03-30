# Connect Four in C++

## Description

Connect Four is a classic board game where two players compete to be the first to align four of their pieces horizontally, vertically, or diagonally on a grid. This project implements the game in C++ with a command-line interface.

## Features

- **Two-player mode**: Play against another player.
- **Player name input**: Players can enter their names for a personalized experience.
- **Turn-based gameplay**: Players take turns dropping their pieces into the columns.
- **Real-time board display**: The game board is displayed after each move, showing the current state of play.
- **Win detection**: The game checks for horizontal, vertical, and diagonal wins.
- **Draw detection**: The game can detect if the board is full without any winner, resulting in a draw.
- **Input validation**: The game checks for valid column inputs and handles full columns gracefully.
- **Replay option**: After a game ends, players can choose to play again without restarting the program.
- **User-friendly messages**: Informative messages guide players through the game and provide feedback on their actions.

## Installation

To play, you can either follow the installation instructions or simply download the executable.

### A. Executable

You can find the executable in the files just above !

### B. Installation with the terminal 

1. Clone the GitHub repository to your local machine:
   ```bash
   git clone https://github.com/Solaris713/connect_four.git
   cd connect_four
   ```

2. Make sure you have a C++ compiler installed (like g++).
   ```bash
   g++ --version
   ```

3. Compile the program:
   ```bash
   g++ -o connect_four main.cpp Game.cpp Board.cpp
   ```

## Usage

1. Run the program:
   ```bash
   connect_four.exe
   ```

2. Follow the on-screen instructions to enter the players' names and choose columns to place your pieces.

3. The game ends when a player aligns four pieces. You will then have the option to play again or exit.

### Example

![image](https://github.com/user-attachments/assets/38185fd3-973a-4cd7-a34b-e19b6e6b6841)

## Code Structure

- `Board.h` and `Board.cpp`: Contain the logic for the game board, including display, piece placement, and win condition checks.
- `Game.h` and `Game.cpp`: Manage the flow of the game, including player turns and input handling.
- `main.cpp`: The entry point of the program, where the game is initialized and executed.

## Author

- Timothée TRÉHARD (March 2025)
