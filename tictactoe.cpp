#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char current_m;
int current_p;

void drawBoard() {
    cout << "Tic Tac Toe Board:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "--|---|--" << endl;
    }
    cout << endl;
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_m;
        return true;
    }
    return false;
}

int checkWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return current_p;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return current_p;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return current_p;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return current_p;

    return 0;  // No winner yet
}

void swapPlayerAndMarker() {
    if (current_m == 'X')
        current_m = 'O';
    else
        current_m = 'X';

    if (current_p == 1)
        current_p = 2;
    else
        current_p = 1;
}

void game() {
    cout << "Player 1, choose your marker (X or O): ";
    char marker_p1;
    cin >> marker_p1;

    current_p = 1;
    current_m = marker_p1;

    drawBoard();

    int winner = 0;
    for (int i = 0; i < 9; i++) {
        cout << "It's player " << current_p << "'s turn. Enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9 || !placeMarker(slot)) {
            cout << "Invalid move. Try again." << endl;
            i--;
            continue;
        }

        drawBoard();

        winner = checkWinner();
        if (winner != 0) {
            cout << "Player " << winner << " wins!" << endl;
            break;
        }
        swapPlayerAndMarker();
    }

    if (winner == 0) {
        cout << "It's a tie!" << endl;
    }
}

int main() {
    game();
    return 0;
}