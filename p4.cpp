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
const int ROW = 4;
const int COL = 3;
const int BEGINNER_TIME = 10;
const int EXPERT_TIME = 5;
const string BOARD_A = /home/fac/sreeder/class/cs1420/p4data1.dat;
const string BOARD_B = /home/fac/sreeder/class/cs1420/p4data2.dat;
const int BOARD_CLEARED = 12;

void welcome();

char getDifficulty();
// returns the difficulty the player wants for the game

string createBoard();
// this is where you pick the file
// it feeds the chars into the string array

void displayBoard();
//ya pass the 2d array here to print??

int takeTurn();
// this is where the user is asked about the cards
// wait() is called here
// removeMatch() is called here too

void wait(int seconds);
// pauses the program for x seconds

void goodbye();

int main()
{
  int numOfTurns = 0;
  char ans = YES;
  int matchedPairs = 0;
  char difficulty;

  welcome();

  while(tolower(answ) == YES){
      difficulty = getDifficulty();
      createBoard();

      while(matchedPars > BOARD_CLEARED) {
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

char getDifficulty()
{
  char choice;
  cout << "There are two difficulties for this game. Please choose one.";
  cout << endl << "Beginner (b) or expert (e): "
  cin >> choice;

  if(tolower(choice) == EXPERT_TIME) {
    return EXPERT_TIME;
  }

  return BEGINNER_TIME;
}

string createBoard()
{

}

void displayBoard()
{

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
