//
//  Header.h
//  tictactoe
//
//  Created by Max Mitchell on 24/08/2022.
//

#ifndef Header_h
#define Header_h

using namespace std;

void introduction();
void tutorial();
void startGame();
void ending();

bool wantTutorial();
bool wantGame();
bool wantTeminate();

string move(string board, bool turn); // return string (the board position)
bool isValidMove(int row, int column, std::string board);

bool isBoardFull(string board);
void displayBoard(string board);

bool isWonPosition(string board);
bool isFinished(string board);
string outputWinner(string board, bool turn);


#endif /* Header_h */
