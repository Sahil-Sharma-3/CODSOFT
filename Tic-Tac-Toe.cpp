/*Sahil Sharma
A simple console-based Tic-Tac-Toe game that
allows two players to play against each other*/

#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<char> >& board) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j != 2) cout << " | ";
        }
        if (i != 2) cout << "\n---------\n";
    }
    cout << "\n\n";
}

bool isWin(const vector<vector<char> >& board, char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

bool isDraw(const vector<vector<char> >& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

void playerMove(vector<vector<char> >& board, char player) {
    int row, col;
    cout << "Player " << player << ", enter your move (row and column): ";
    while (true) {
        cin >> row >> col;
        if (cin.fail() || row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid move, try again: ";
        } else {
            board[row-1][col-1] = player;
            break;
        }
    }
}

int main() {
    vector<vector<char> > board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameRunning = true;

    while (gameRunning) {
        printBoard(board);
        playerMove(board, currentPlayer);
        if (isWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Congratulations! Player " << currentPlayer << " wins!\n";
            gameRunning = false;
        } else if (isDraw(board)) {
            printBoard(board);
            cout << "It's a draw!\n";
            gameRunning = false;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
