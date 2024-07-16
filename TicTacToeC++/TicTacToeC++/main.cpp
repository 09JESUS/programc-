#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentMarker;
int currentPlayer;

//Create a function that draw the tictac toe board
void drawBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool placeMarker(int slot) {
    int row = slot / 3;
    int col;

    if (slot % 3 == 0) {
        row -= 1;
        col = 2;
    } else {
        col = (slot % 3) - 1;
    }

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

int winner() {
    for (int i = 0; i < 3; i++) {
        // Rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return currentPlayer;
        }
        // Columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return currentPlayer;
        }
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return currentPlayer;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return currentPlayer;
    }
    return 0;
}

void swapPlayerAndMarker() {
    if (currentMarker == 'X') {
        currentMarker = 'O';
    } else {
        currentMarker = 'X';
    }

    if (currentPlayer == 1) {
        currentPlayer = 2;
    } else {
        currentPlayer = 1;
    }
}

void game() {
    string name1,name2;
    cout<<"Enter your name: ";
    cin>>name1;
    cout<<"Enter your name: ";
    cin>>name2;
    cout << name1<<", choose your marker: ";//user suppose to choose between O AND X IF(Chooses X automatically player 2 takes the opposite maker)
    char markerP1;
    cin >> markerP1;

    currentPlayer = 1;
    currentMarker = markerP1;

    drawBoard();

    int playerWon;

    for (int i = 0; i < 9; i++) {
        if (currentPlayer == 1) {
            cout << name1 << ", it's your turn. Enter your slot: ";
        } else {
            cout << name2 << ", it's your turn. Enter your slot: ";
        }
        int slot;
        cin >> slot;
        if (slot < 1 || slot > 9) {
            cout << "That slot is invalid! Try another slot!" << endl;
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "That slot is occupied! Try another slot!" << endl;
            i--;
            continue;
        }
        system("cls");
        drawBoard();//Call function to display the board

        playerWon = winner();

        if (playerWon == 1) {
            //display this message if player  won
             //display this message if player 2 won
            cout<<"==============================="<<endl;
            cout<<"*******Game Over********"<<endl;
            cout << name1<<" Wins!" << endl;
            cout<<"==============================="<<endl;
            break;
        }
        if (playerWon == 2) {
            //display this message if player 2 won
            cout<<"==============================="<<endl;
            cout<<"*******Game Over********"<<endl;
            cout << "Player 2 wins!" << endl;
            cout<<"==============================="<<endl;
            break;
        }

        swapPlayerAndMarker();
    }

    if (playerWon == 0) {
        //display if it is a draw for both player
        cout << "It's a tie!" << endl;
    }
}

int main() {
    //call game functions
    game();
    return 0;
}
