#include <iostream>
using namespace std;

char board[3][3];

void initializeBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = '-';
        }
    }
}

void drawBoard() {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool placeMark(int row, int col, char mark) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '-') {
        return false;
    }
    board[row][col] = mark;
    return true;
}

bool checkWin(char mark) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) {
            return true; // Horizontal win
        }
        if (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark) {
            return true; // Vertical win
        }
    }
    if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) {
        return true; // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark) {
        return true; // Diagonal win (top-right to bottom-left)
    }
    return false;
}

int main() {
    initializeBoard();
    bool player1Turn = true;

    while (true) {
        drawBoard();

        int row, col;
        char mark = player1Turn ? 'X' : 'O';
        cout << (player1Turn ? "Player 1" : "Player 2") << ", enter row and column (0-2) to place your mark: ";
        cin >> row >> col;

        if (placeMark(row, col, mark)) {
            if (checkWin(mark)) {
                cout << (player1Turn ? "Player 1" : "Player 2") << " wins!" << endl;
                break;
            }
            else {
                player1Turn = !player1Turn; // Switch player
            }
        }
        else {
            cout << "Invalid move! Please try again." << endl;
        }
    }

    return 0;
}
