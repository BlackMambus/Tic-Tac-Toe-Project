#include <iostream>
using namespace std;

char board[3][3];

// Initialize the board with numbers 1-9 for the positions
void initializeBoard() {
    char pos = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = pos++;
        }
    }
}

// Print the board to the console
void printBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
    cout << "\n";
}

// Check if the board cell is free
bool isCellFree(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    return board[row][col] != 'X' && board[row][col] != 'O';
}

// Place the player's mark on the board
void placeMark(int position, char mark) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    board[row][col] = mark;
}

// Check for a win by checking rows, columns and diagonals
bool checkWin(char player) {
    // Check rows
    for (int i = 0; i < 3; i++)
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;

    // Check columns
    for (int i = 0; i < 3; i++)
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Check if the board is full (for a draw)
bool checkDraw() {
    for (int i = 1; i <= 9; i++) {
        if (isCellFree(i)) {
            return false;
        }
    }
    return true;
}

int main() {
    initializeBoard();
    char currentPlayer = 'X';
    int position;
    bool gameEnded = false;

    cout << "Welcome to Tic Tac Toe!\n";
    cout << "Player 1 is X, Player 2 is O\n";

    while (!gameEnded) {
        printBoard();
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> position;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number between 1 and 9.\n";
            continue;
        }

        if (position < 1 || position > 9) {
            cout << "Invalid position! Choose a number between 1 and 9.\n";
            continue;
        }

        if (!isCellFree(position)) {
            cout << "Cell already taken! Choose another cell.\n";
            continue;
        }

        placeMark(position, currentPlayer);

        if (checkWin(currentPlayer)) {
            printBoard();
            cout << "Congratulations! Player " << currentPlayer << " wins!\n";
            gameEnded = true;
        } else if (checkDraw()) {
            printBoard();
            cout << "The game is a draw!\n";
            gameEnded = true;
        } else {
            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    cout << "Game over. Thanks for playing!\n";
    return 0;
}


