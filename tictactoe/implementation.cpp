//
//  implementation.cpp
//  tictactoe
//
//  Created by Max Mitchell on 24/08/2022.
//

#include <iostream>
#include <stdio.h>
#include "header.h"

void introduction(){
    using namespace std;
    cout << R"(  _____                ____           _____      _        ____           _____   U  ___ uU _____ u)" << endl;
    cout << R"( |_   _|     ___   U / ___|          |_   _| U  / \  u U / ___|         |_   _|   \/ _ \/\| ___ |)" << endl;
    cout << R"(   | |      |_ _|   \| | u    U  u     | |    \/ _ \/  \| | u    U  u     | |     | | | | |  _|)" << endl;
    cout << R"(  /| |\      | |     | |/__   /___\   /| |\   / ___ \   | |/__   /___\   /| |\.-,_| |_| | | |___)" << endl;
    cout << R"( u |_|U    U/| |\u    \____| |__ __| u |_|U  /_/   \_\   \____| |__ __| u |_|U \_)-\___/  |_____|)" << endl;
    cout << R"( _// \\_.-,_|___|_,-._// \\          _// \\_  \\    >>  _// \\          _// \\_     \\    <<   >>)" << endl;
    cout << R"((__) (__)\_)-' '-(_/(__)(__)        (__) (__)(__)  (__)(__)(__)        (__) (__)   (__)  (__) (__))" << endl << endl;
    cout << "This is a tic-tac-toe program.\n";

    if (wantTutorial() == true){
        tutorial();
    }
    
    return;
}


void ending(){
    using namespace std;
    
    cout << "Good-bye\n";
    return;
}


bool wantTutorial(){
    using namespace std;
    
    char wantTutorial;
    cout << "Do you want the tutorial? (Type Y/n)\n";
    cin >> wantTutorial;
    
    return (wantTutorial == 'y' || wantTutorial == 'Y'); // need error handling
}


bool wantGame(){
    using namespace std;
    
    do
    {
        char wantGameInput;
        cout << "Righty then! Fancy a game? (Type Y/n)\n";
        cin >> wantGameInput;
        
        if (wantGameInput == 'y' || wantGameInput == 'Y') return true;
        
    } while (wantTeminate() == false);
    
    return false;
}


bool wantTeminate(){
    using namespace std;
    
    char wantTerminate;
    cout << "Ummm, this is akward. Shall I terminate the program now? (Type Y/n)\n";
    cin >> wantTerminate;
    
    return (wantTerminate == 'y' || wantTerminate == 'Y'); // write
}

void tutorial(){
    using namespace std;
    
    cout << endl;
    cout << "Tic-tac-toe, noughts and crosses, or Xs and Os is a paper-and-pencil game for two players who take turns marking the spaces in a three-by-three grid with X or O. The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row is the winner.\n\n";
    cout << "This is the board:\n\n";
    
    cout << "          |   |  \n";
    cout << "       ---|---|---\n";
    cout << "          |   |  \n";
    cout << "       ---|---|---\n";
    cout << "          |   |  \n\n";
    
    cout << "On your turn you'll type your desired square (eg. \"1 2\" for first row, second column). These are labelled as follows:\n\n";

    cout << "          COLUMN \n";
    cout << "        1   2   3 \n";
    cout << "     1    |   |   \n";
    cout << "       ---|---|---\n";
    cout << " ROW 2    |   |  \n";
    cout << "       ---|---|---\n";
    cout << "     3    |   |  \n\n";
    
    return;
}


void startGame(){
    using namespace std;
    
    cout << "STARTING GAME!\n\n";
    cout << "NB: At any time you can press q to quit the game\n\n";
    
    string board = "         "; // ... should probs be a 2D array too
    displayBoard(board);
    
    
    bool turn = 0; // 0 is Os, 1 is Xs
    do {
        board = move(board, turn);
        
        if (board == "Q"){
            cout << "GAME TERMINATED\n\n";
            return;
        }
        
        displayBoard(board);
        turn = !turn;
    } while (isFinished(board) == false);
    
    cout << outputWinner(board, turn);
}

void displayBoard(std::string board){
    using namespace std;
    
    cout << " " << board[0] <<" | " << board[1] << " | " << board[2] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[3] <<" | " << board[4] << " | " << board[5] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[6] <<" | " << board[7] << " | " << board[8] << " \n";
    
    cout << endl << endl;
    return;
}


std::string move(std::string board, bool turn){
    using namespace std;
    char piece;
    
    if (turn == 0){
        piece = 'O';
    }
    else {
        piece = 'X';
    }
    cout << piece << "'s turn\n";
    
    int selectedSquareIndex;
    string inputCoord; // to account for user quitting with q
    int row, column; // converted to int
    
    do{
        cout << "Choose empty square (eg. \"1,2\" for first row, second column): "; // allow if empty AND valid input (eg not ''4 3'')
        cin >> inputCoord;
        
        if (inputCoord[0] == 'q' || inputCoord[0] == 'Q'){
            return "Q";
        }
        
        row = static_cast<int>(inputCoord[0]);
        column = static_cast<int>(inputCoord[2]);
        
        
        //          0        1       2       3       4       5       6       7       8
        // r,c      1,1      1,2     1,3     2,1     2,2     2,3     3,1     3,2     3,3
        // c-1%3    0        1       2       0       1       2       0       1       2
        // 3*(r-1)  0        0       0       3       3       3       6       6       6
        
    } while (isValidMove(row, column, board) == false);
    
    selectedSquareIndex = (3 * (row - 1)) + ((column - 1) % 3);
    board[selectedSquareIndex] = piece;
    
    return board;
}

bool isValidMove(int row, int column, std::string board){
    int selectedSquareIndex = (3 * (row - 1)) + ((column - 1) % 3);
    if (row > 3 || column > 3 || board[selectedSquareIndex] != ' ') {
        std::cout << "Square occupied! Pick another\n";
        return false;
    }
    return true;
}

bool isFinished(std::string board){

    return (isWonPosition(board) || isBoardFull(board) == true);
}

bool isWonPosition(std::string board){
    
    //CASE 1: isDiagonal
    if (board[4] != ' '){
        if (((board[0] == board[4]) && (board[4] == board[8])) || ((board[2] == board[4]) && (board[4] == board[6]))){
            return true;
        }
    }
    //CASE 2: is row/col
    for (int i = 0; i <= 6; i = i+3){
        if (board[i] != ' '){
            if (((board[i] == board[i+1]) && (board[i+1] == board[i+2]))){
                return true;
            }
            if ((board[i] == board[i+3]) && (board[i+3] == board[i+6])){
                return true;
            }
        }
    }
    return false;
}

bool isBoardFull(std::string board){
    for (int i = 0; i < 9; i++){
        if (board[i] == ' ') {
            return false;
        }
    }
    return true;
}

std::string outputWinner(std::string board, bool turn){
    using namespace std;
    string winner;
    
    if (isWonPosition(board)){
        
        if (turn == 0){
            winner = "X";
        }
        else{
            winner = "O";
        }
    }
    else{
        winner = "No one";
    }
    return (winner + " won!\n");
}
