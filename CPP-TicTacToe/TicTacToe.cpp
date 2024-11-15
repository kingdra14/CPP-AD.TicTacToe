#include "TicTacToe.h"

 void TicTacToe:: Display() const {
     
     std::cout << "-------------" << std::endl;
     for (int i = 0; i < 3; i++) {
         std::cout << "| ";
         for (int j = 0; j < 3; j++) {
             std::cout << board[i][j] << " | ";
         }
         std::cout << std::endl << "-------------" << std::endl;
     }
}
bool TicTacToe:: IsGameOver() const {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    return false;
}

void TicTacToe::TakeTurn() {
    int choice;

    while (moves < 9) {
        Display();
        std::cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        std::cin >> choice;

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = currentPlayer;
            moves++;

            if (IsGameOver()) {
                Display();
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                return;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
        else {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }
}