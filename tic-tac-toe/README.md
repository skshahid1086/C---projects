# Tic Tac Toe in C

A simple terminal-based Tic Tac Toe game written in C. This project allows two players to play against each other in the console, with automatic win detection, draw detection, and the option to restart the game after each match.

## Features

* Two-player gameplay (X vs O)
* Interactive command-line interface
* Winner detection
* Draw detection
* Input validation for board positions
* Restart game without restarting the program
* Clean and beginner-friendly code structure

## Demo

```text
   |   |
   |   |
---|---|---
   |   |
   |   |
---|---|---
   |   |
   |   |
```

Players choose positions using numbers from **1 to 9**:

```text
 1 | 2 | 3
---|---|---
 4 | 5 | 6
---|---|---
 7 | 8 | 9
```

## How It Works

1. Player X starts first.
2. Players enter a position number (1-9).
3. The selected cell is marked with the player's symbol.
4. The game checks for:

   * Three matching symbols in a row
   * Three matching symbols in a column
   * Three matching symbols diagonally
5. If a player wins, the winner is announced.
6. If all 9 cells are filled without a winner, the game ends in a draw.
7. Players can choose to play again without restarting the program.

## Project Structure

```text
tic-tac-toe/
│
├── tic_tac_toe.c
└── README.md
```

## Functions

### `displayBoard()`

Displays the current state of the game board.

### `playerInput()`

Handles player input and updates the board.

### `checkWinner()`

Checks all rows, columns, and diagonals for a winning condition.

### `resetBoard()`

Clears the board for a new game.

## Requirements

* GCC or any C compiler
* Terminal/Command Prompt

## Compilation

Using GCC:

```bash
gcc tic_tac.toe.c -o tic_tac_toe
```

## Running the Game

### Linux/macOS

```bash
./tic_tac_toe
```

### Windows

```bash
tic_tac_toe.exe
```

## Example Gameplay

```text
X's Turn
Choose Position (1-9): 5

   |   |
   | X |
   |   |

O's Turn
Choose Position (1-9): 1

 O |   |
   | X |
   |   |
```

## Future Improvements

* Single-player mode against AI
* Difficulty levels
* Better board visualization
* Score tracking system
* Input error recovery
* Colored terminal output

## Concepts Practiced

* Arrays
* Functions
* Pointers
* Loops
* Conditionals
* Boolean logic
* User input handling
* Game state management

## License

This project is open source and available under the MIT License.