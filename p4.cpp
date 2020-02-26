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
const int INVALID = -1;
const int SCREEN_HEIGHT = 40;
const int BOARD_CLEARED = 12;

void welcome();

int getDifficulty();
// returns the wait time based on the player's difficulty

bool createBoard(char board[][COLS]);
// returns true if a char array is sucessfuly made from reading a file
// returns false otherwise

void displayBoard(char board[][COLS], int c1row = -1, int c1col = -1,
                  int c2row = -1, int c2col = -1);
// prints the board to screen with the astricks and underscores,
// with one card flipped over and with both cards flipped over

void pickFirstCard(char board[][COLS], int& c1row, int& c1col);
// returns the row and col values of the first card

void pickSecondCard(char board[][COLS], int c1row, int c1col, int& c2row,
                    int& c2col);
// returns row and col values of the second card

void wait(int seconds);
// pauses the program for x seconds based on difficulty

void takeTurn(char board[][ROWS], int waitTime);
// asks for cards to pick and checks if there is a match or not

void goodbye();

int main()
{
  char ans = YES;
  int waitTime; // stores the wait time in seconds based on difficulty
  bool noError = false; // tracks if file was read properly
  char board[ROWS][COLS]; //char array for the board of cards

  int currentC1Row = INVALID;
  int currentC1Col = INVALID;
  int currentC2Row = INVALID;
  int currentC2Col = INVALID;

  welcome();
  while(tolower(ans) == YES) {
    waitTime = getDifficulty();
    cout << "Your wait time is: " << waitTime << endl;
    noError = createBoard(board);
      if(!noError) {
        ans = 'n';
        cout << "Error with file! Quitting program...." << endl;
      }

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
  for(int line = 0; line <= SCREEN_HEIGHT; line++){
    cout << endl;
  }

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
  int cardRow = INVALID;
  int cardCol = INVALID;

  while(cardRow == INVALID && cardCol == INVALID) {
    while (cardRow < 0 || cardRow > ROWS - 1) {
      cout << "Row? ";
      cin >> cardRow;
    }

    c1row = cardRow;

    while (cardCol < 0 || cardCol > COLS - 1) {
      cout << "Col? ";
      cin >> cardCol;
    }

    if(board[c1row][c1col] == UNDERSCORE) {
      cout << "Card Out Of Play! Please Pick Again...";
      cardRow = INVALID;
      cardCol = INVALID;
    }
  }
    c1col = cardCol;
}

void pickSecondCard(char board[][COLS], int c1row, int c1col, int& c2row,
                    int& c2col)
{
  int cardRow = INVALID;
  int cardCol = INVALID;

  while(cardRow == INVALID && cardCol == INVALID) {
    while (cardRow < 0 || cardRow > ROWS - 1) {
      cout << "Row? ";
      cin >> cardRow;
    }
    c2row = cardRow;
    while (cardCol < 0 || cardCol > COLS - 1) {
      cout << "Col? ";
      cin >> cardCol;
    }
    c2col = cardCol;
    if(board[c2row][c2col] == UNDERSCORE) {
      cout << "Card Out Of Play! Please Pick Again..." << endl;
      cardRow = INVALID;
      cardCol = INVALID;
    } else if(cardRow == c1row && cardCol == c1col) {
      cout << "Already Picked This Card! Please Pick Again..." << endl;
      cardRow = INVALID;
      cardCol = INVALID;
    }
  }
}

void wait(int seconds)
{
  clock_t endwait;
  endwait = clock() + seconds * CLOCKS_PER_SEC;

  while (clock() < endwait){}
}

bool takeTurn(char board[][COLS], int waitTime)
{
  bool foundMatch = false;
  displayBoard(board);
  pickFirstCard(board, currentC1Row, currentC1Col);
  displayBoard(board, currentC1Row, currentC1Col);
//  cout << "the first card you picked was: " << currentC1Row << " " << currentC1Col << endl;
  pickSecondCard(board,currentC1Row, currentC1Col, currentC2Row, currentC2Col);
  if(board[currentC1Row][currentC1Col] == board[currentC2Row][currentC2Col]) {
    cout << "You found a match!!!" << endl;
    board[currentC1Row][currentC1Col] = UNDERSCORE;
    board[currentC2Row][currentC2Col] = UNDERSCORE;
    foundMatch = true; 
  } else {
    cout << "Sorry, not a match... ";
    displayBoard(board, currentC1Row, currentC1Col, currentC2Row, currentC2Col);
    wait(waitTime);
  }
//  cout << " The second card you picked was " << currentC2Row << " " << currentC2Col << endl;
  return foundMatch;
}

void goodbye()
{
  cout << endl << endl;
  cout << "Thanks for playing! Goodbye...." << endl << endl;
}
