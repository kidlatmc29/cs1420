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

int spin();
void move(int squares);

int main()
{
  string name; // Stores the user's name.
  char ans; // Stores user's answer to play the game again.
  int userPosition; // Stores the current user's positon on the board is.
  int pcPosition; // Stores the current computer's position on the board is.
  int userSpin; // Stores the current spin of the user.
  int pcSpin; // Stores the current spin of the pc.
  srand(time(0));

  cout << endl << endl;
  cout << "Welcome to the Chutes and Ladders Game! " <<endl;
    // put directions about how the game works here
  cout << "Enter your name: ";
  getline(cin, name);

  ans = 'y';
  userPosition = 0;
  pcPosition = 0;

  while(tolower(ans) == YES) {
    while((userPosition != WINNING_SQUARE) || (pcPosition != WINNING_SQUARE)) {
      cout << "now it's time to spin!" << endl;
      userSpin = spin();
      cout << name << " spun a  " << userSpin << endl;
      
    }
    cout << "Want to play again? (y/n): ";
    cin >> ans;
  }

  cout << "Thanks for playing! Goodbye.... " << endl << endl;
  return 0;
}

int spin()
{
  int moves = rand() % ((MAX_SPIN - MIN_SPIN) + 1) + MIN_SPIN;
  return moves;
}

void move(int squares)
{
  // this will update the pc or user's position on the board
}

void checkLadder()
{
 // this checks if the pc or user landed on a ladder
}

void checkChute()
{
  // this checks if the pc of user landed on a chute
}
