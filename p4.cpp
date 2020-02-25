// Isabel Ovalles
// p4.cpp
// 2-15-2020

// Purpose: This program plays a memory card game with the user.
// Input: Files contatining possible board configurations.
// Processing:
// Output:
// Example:

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

const char YES = 'y';
const char EXPERT = 'e';
const char BEGINNER = 'b';
const char LEFT_BRACKET = '[';
const char RIGHT_BRACKET = ']';
const char SPACE = ' ';
const char ASTERISK = '*';
const char UNDERSCORE = '_';
const int PERFECT_GAME = 6;
const int ROWS = 4;
const int COLS = 3;
const int BEGINNER_TIME = 10;
const int EXPERT_TIME = 5;
const string BOARD_A = /home/fac/sreeder/class/cs1420/p4data1.dat;
const string BOARD_B = /home/fac/sreeder/class/cs1420/p4data2.dat;
const int BOARD_CLEARED = 12;

void welcome();

int getDifficulty();
// returns the wait time based on the player's difficulty

bool createBoard(char board[][ROWS], string fileName);
// returns true if the file worked and the board is full of chars
// returns false if otherwise

void displayBoard(char board[][ROWS], int c1row = -1, int c1col =1,
    int c2row = -1, int c2col = -1);
// prints the board to screen with the astricks and underscores,
// with one card flipped over and with both cards flipped over

int takeTurn(char board[][ROWS], int waitTime);
// this is where the user is asked about the cards
// wait() is called here
// removeMatch() is called here too

int pickFirstCard();
// paras is the current board
// returns row and col

int pickSecondCard();
// params is the current board AND the row and col of FIRST card

void wait(int seconds);
// pauses the program for x seconds

void goodbye();

int main()
{
  srand(time(0));
  int numOfTurns = 0; // tracks the number of turns the player takes
  int matchedPairs = 0; // tracks the number of pairs the player gets
  int waitTime; // stores the wait time returned by getDifficulty();
  char board[ROWS][COLS]; //char array for the board of cards
  bool noError = false; // Bool that make sures the board was made
  char ans = YES;

  welcome();

  while(tolower(answ) == YES) {
      waitTime = getDifficulty();
      noError = createBoard();
      if(!noError) {
        ans = 'n';
        cout << "Error with file!" << endl;
        }

      while(matchedPairs > BOARD_CLEARED && createBoard() == noError) {
        takeTurn(board, waitTime);
        numOfTurns++;
      }

      cout << "You won! Your score is " << numOfTurns << "." << endl;
      cout << "Do you want to play again? (y/n): ";
      cin >> ans;
  }

  goodbye();
  return 0;
}

void welcome()
{
  cout << endl << endl;
  cout << "Welcome to the Memory Game! " << endl;
  cout << "You will have a " << ROWS << " by "
       << COLS << "board of cards that you will need to match.";
  cout << endl << endl;
}

int getDifficulty()
{
  char choice;
  int time;
  cout << "There are two difficulties for this game. Please choose one.";
  cout << endl << "Beginner (b) or expert (e): "
  cin >> choice;

  if(tolower(choice) == EXPERT_TIME) {
    time = EXPERT_TIME;
  } else {
    time = BEGINNER_TIME;
  }
  return time;
}

bool createBoard(char board[][COLS])
{
  ifStream inFile;
  string fileName;
  int ranNum = rand() % ((20 - 10) + 1) + 10;
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

void displayBoard(char board[][ROWS], int c1row = -1, int c1col = -1,
    int c2row = -1, int c2col = -1)
{

  // prints top labels of the board
  for(int i = 0; i < ROWS; i++) {
    cout << SPACE << SPACE << SPACE << i;
  }

  cout << SPACE << SPACE;

  for(int row = 0; row < ROW; row++) {
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
  }

}

int takeTurn(char board[][COLS], int waitTime);
{
  int currentC1Row = -1;
  int currentC1Col = -1;
  int currentC2Row = -1;
  int currentC2Col = -1;
  bool isMatch = false;

  displayBoard(const char board);
  pickFirstCard(const board, currentC1Row, currentC1Col);
  displayBoard(const board, currentC1Row, currentC1Col); // fix this
  getSecondCard(const board, currentC1Row, currentC1Col);
  displayBoard(const board, currentC1Row, currentC1Col, current); // fix this

  isMatch = removeMatch();
  if(!isMatch) {
    wait(waitTime)
  }


  return 1;
}

void wait(int seconds)
{
  clock_t endwait;
  endwait = clock() + seconds * CLOCKS_PER_SEC;

  while (clock() < endwait){}
}

int pickFirstCard(char board[][COLS], int& c1row, int& c1col)
{
  int cardRow = -1;
  int cardCol =  -1;

  while (cardRow < 0 || cardRow > ROWS - 1) {
    cout << "Row? ";
    cin >> cardRow;
  }

  c1row = cardRow;

  while (cardCol < 0 || cardCol > COLS - 1) {
    cout << "Col? ";
    cin >> cardCol;
  }
    c1col = cardCol;
}

int pickSecondCard(char board[][COLS], int& c1row, int& c1col)
{
 // asks for row
 // makes sure it valid
 // makes sure it's not the same as c1row
// else repeat

 // asks for Col
  // makes sure it's valid
  // makes sure it's not the same a c2row
  // else repeat
}

void goodbye()
{
  cout << endl << endl;
  cout << "Thanks for playing! Goodbye...." << endl << endl;
}
