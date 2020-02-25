// Isabel Ovalles
// p4.cpp
// 2-25-2020

// Purpose: This program plays a memory card game with the user.
//
// Input: Files contatining possible chars for the board. User will supply
// coordinates for two cards.
//
// Processing: The program will have input validation for the coordinates of
// the cards and determine if the two cards are a match, either removing
// the matched pair from play or waiting so the player can look at the cards.
//
// Output:
// Example:

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int BEGINNER_TIME = 10;
const int EXPERT_TIME = 5;
const char EXPERT = 'e';
const char BEGINNER = 'b';
const char YES = 'y';
const int ROWS = 4;
const int COLS = 3;
const char LEFT_BRACKET = '[';
const char RIGHT_BRACKET = ']';
const char SPACE = ' ';
const char ASTERISK = '*';
const char UNDERSCORE = '_';
const int COL_LABEL = 4;
const string BOARD_A = "/home/fac/sreeder/class/cs1420/p4data1.dat";
const string BOARD_B = "/home/fac/sreeder/class/cs1420/p4data2.dat";
const int BOARD_CLEARED = 12;

void welcome();

int getDifficulty();
// returns the wait time based on the player's difficulty

bool createBoard(char board[][COLS]);

void displayBoard(char board[][COLS], int c1row = -1, int c1col = -1,
                  int c2row = -1, int c2col = -1);
// prints the board to screen with the astricks and underscores,
// with one card flipped over and with both cards flipped over

void pickFirstCard(char board[][COLS], int& c1row, int& c1col);

void goodbye();

int main()
{
  char ans = YES;
  int waitTime; // stores the wait time in seconds based on difficulty
  bool noError = false; // tracks if file was read properly
  char board[ROWS][COLS]; //char array for the board of cards

  int currentC1Row = -1;
  int currentC1Col = -1;
  //int currentC2Row = -1;
  //int currentC2Col = -1;

  welcome();
  while(tolower(ans) == YES) {
    waitTime = getDifficulty();
    cout << "Your wait time is: " << waitTime << endl;
    noError = createBoard(board);
      if(!noError) {
        ans = 'n';
        cout << "Error with file! Quitting program...." << endl;
      }
    displayBoard(board);
    pickFirstCard(board, currentC1Row, currentC1Col);
    cout << "the card you picked was: " << currentC1Row << " " << currentC1Col << endl;
    cout << "Do you want to play again? (y/n): ";
    cin >> ans;
    waitTime = 0;
  }
  goodbye();
  return 0;
}

void welcome()
{
  cout << endl << endl;
  cout << "Welcome to the Memory Game! " << endl;
  cout << "You will have a " << ROWS << " by "
       << COLS << " board of cards that you will need to match.";
  cout << endl << endl;
}

int getDifficulty()
{
  char choice = 'y';
  int time;

  while(choice != BEGINNER && choice != EXPERT) {
    cout << "There are two difficulties for this game. Please choose one.";
    cout << endl << "Beginner (b) or expert (e): ";
    cin >> choice;
  }

  if(tolower(choice) == EXPERT) {
    time = EXPERT_TIME;
  } else {
    time = BEGINNER_TIME;
  }
  return time;
}

bool createBoard(char board[][COLS])
  {
    ifstream inFile;
    string fileName;
    int randNum = rand() % ((20 - 10) + 1) + 10;
    if((randNum % 2) == 0) { // file is chosen based on even or odd rand num
      fileName = BOARD_A;
    } else {
      fileName = BOARD_B;
    }

    inFile.open(fileName);
    if(inFile.fail()) {
      return false;
    }

    for(int r = 0; r < ROWS; r++) {
      for(int c = 0; c < COLS; c++) {
        inFile >> board[r][c];
      }
    }
    inFile.close();
    return true;
}

void displayBoard(char board[][COLS], int c1row, int c1col, int c2row,
                 int c2col)
{
  for(int i = 0; i < COLS; i++) {
    cout << setw(COL_LABEL) << i;
  }
  cout << endl;

  for(int row = 0; row < ROWS; row++) {
    cout << row << SPACE;
    for(int col = 0; col < COLS; col++) {
      cout << LEFT_BRACKET;
      if(row == c1row && col == c1col) {
        cout << board[c1row][c1col];
      } else if (row == c2row && col == c2col) {
        cout << board[c2row][c2col];
      } else {
        cout << ASTERISK;
      }
      cout << RIGHT_BRACKET << SPACE;
    }
      cout << endl;
  }
}

void pickFirstCard(char board[][COLS], int& c1row, int& c1col)
{
  int cardRow = -1;
  int cardCol =  -1;

  while (cardRow < 0 || cardRow > ROWS - 1) {
    cout << "Row? ";
    cin >> cardRow;

    if(board[c1Row][c1Col] == UNDERSCORE) {
      cout << "Card Out Of Play! Pick Again...";
      cardRow = -1;
    }
  }

  c1row = cardRow;

  while (cardCol < 0 || cardCol > COLS - 1) {
    cout << "Col? ";
    cin >> cardCol;

    if(board[c1Row][c1Col] == UNDERSCORE) {
      cout << "Card Out Of Play! Pick Again...";
      cardCol = -1;
    }
  }
  
    c1col = cardCol;
}
void goodbye()
{
  cout << endl << endl;
  cout << "Thanks for playing! Goodbye...." << endl << endl;
}
