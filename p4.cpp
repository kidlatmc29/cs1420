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
const char RIGHT_BRAKET = ']';
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

int takeTurn();
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
  int numOfTurns = 0;
  char ans = YES;
  int matchedPairs = 0;
  int waitTime;
  char board[ROWS][COLS];
  srand(time(0));

  welcome();

  while(tolower(answ) == YES) {
      difficulty = getDifficulty();
      createBoard();
      while(matchedPairs > BOARD_CLEARED) {
        takeTurn();
      }
  }

  goodbye();
  return 0;
}

void welcome()
{
  cout << endl << endl;
  cout << "Welcome to the Memory Game! " << endl;
  cout << "You will have a 4 x 3 board of cards that will need to be matched.";
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
  string fileName;
  int ranNum = rand() % ((20 - 10) + 1) + 10;
  if((randNum % 2) == 0) { // file is chosen based on even or odd rand num
    fileName = BOARD_A;
  } else {
    fileName = BOARD_B;
  }
  ifStreaminFile;

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

void displayBoard(char board[][ROWS], int c1row = -1, int c1col =1,
    int c2row = -1, int c2col = -1)
{
  for(int i = 0; i < ROWS; i++) {
    cout << SPACE << SPACE << SPACE << i;
  }

  for(int row = 0; row < ROW; row++) {

  }
}

int takeTurn()
{
  return 1;
}

void wait(int seconds)
{
  clock_t endwait;
  endwait = clock() + seconds * CLOCKS_PER_SEC;

  while (clock() < endwait){}
}

void goodbye()
{
  cout << endl << endl;
  cout << "Thanks for playing! Goodbye...." << endl << endl;
}
