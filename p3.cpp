// Isabel Ovalles
// p3.cpp
// 2-16-2020

// Purpose: This program plays the game chutes and ladders with the user.

// Input: The user is prompted to give their name to the program. The user
// spins to start the game.

// Output: When the user spins to move, the program prints how many spaces
// they are going to move, and what number square they land on. This also
// occurs when the computer spins, which tells the user how many spaces the
// computer will move, and what number square the computer lands on.

// Example:

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const char YES = 'y';
const int MIN_SPIN = 1;
const int MAX_SPIN = 6;
const int WINNING_SQUARE = 100;

void welcome();
int spin();
int move(int spaces, int position);
int checkLadder(int position);
int checkChutes(int position);
void goodbye();


int main()
{
  string name; // Stores the user's name.
  char answer; // Stores user's answer to play the game again.
  int userPosition; // Stores the current user's positon on the board is.
  int pcPosition; // Stores the current computer's position on the board is.
  int userSpin; // Stores the current spin of the user.
  int pcSpin; // Stores the current spin of the pc.
  int whosTurn; // Stores who turn it is.
  srand(time(0));

  welcome();

  cout << "Enter your name: ";
  getline(cin, name);

  ans = 'y';
  userPosition = 0;
  pcPosition = 0;
  whosTurn = 1;

  while(tolower(ans) == YES) {
    int moves = spin();
    if(whosTurn % 2 != 0) {
      userPosition += moves;
      checkLadder(userPosition);
      checkChutes(userPositiion);
    }


    cout << "Want to play again? (y/n): ";
    cin >> ans;
  }
  return 0;
}

void welcome()
{
  cout << endl << endl;
  cout << "Welcome to the Chutes and Ladders Game! " <<endl;
    // put directions about how the game works here
}
int spin()
{
  int moves = rand() % ((MAX_SPIN - MIN_SPIN) + 1) + MIN_SPIN;
  return moves;
}

int move(int spaces, int position)
{
  return position + spaces;
  // this will update the pc or user's position on the board
}

int checkLadder(int positon)
{
  int newPosition = position;

  if(position == 1){
    newPosition += 37;
  } else if (position == 4) {
    newPosition += 10;
  } else if (position == 9){
    newPosition += 12;
  } else if (position == 23){
    newPosition += 21;
  } else if (position == 28) {
    newPosition += 56;
  } else if (position == 36) {
    newPosition += 8;
  } else if (position == 51) {
    newPosition += 15;
  } else if (position == 71) {
    newPosition += 19;
  } else if (position == 80) {
    newPosition += 20;
  }
  return newPosition
 // this checks if the pc or user landed on a ladder the updates
}

void checkChute(int position)
{
  int newPosition = position;

  if(position == 98) {
    newPosition -= 20;
  } else if (position == 95) {
    newPosition -= 20;
  } else if (position == 93) {
    newPosition -= 20;
  } else if (position == 87) {
    newPosition -= 63;
  } else if (position == 64) {
    newPosition -= 4;
  } else if (position == 62) {
    newPosition -= 43;
  } else if (position == 56) {
    newPosition -= 3;
  } else if (position == 49) {
    newPosition -= 38;
  } else if (position == 48) {
    newPosition -= 22;
  } else if (position == 16) {
    newPosition -= 10;
  }
  return newPosition;
  // this checks if the pc of user landed on a chute
}

void goodbye()
{
  cout << "Thanks for playing! Goodbye.... " << endl << endl;
}
