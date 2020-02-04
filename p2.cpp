// Isabel Ovalles
// 1-17-2020
// p2.cpp

// Purpose: This program plays a number guessing game with the user
// as many times as the user wants.
//
// Input: The user will input guesses of numbers with in the range [1, 25].
//
// Processing: The program will compare the user's guess to the
// random generated number and will continue until the user's guess
// matches the random number.
//
// Output: Program will print out the user if their guess is
// too high, too low or correct.
//
// Example: The random number is 12, and the user guesses 15, the game will
// print out "Too high!". When the user guesses again, with 10, the game will
// print out "Too low!" and they guess again. When the user guesses 12, the
// game will print out "Correct!" and asks the user if they want to play again.

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int MAX_VALUE = 25; // Stores upperbounds of the possible random number.
const int MIN_VALUE = 1; // Stores lowerbounds of the possible random number.
const char YES = 'y';

int main()
{
  srand(time(0));
  char ans = 'y'; // Stores answer of user if they want to play again.
  int guess; // Stores current user's guess.
  int randNum; // Stores the random number the user must guess.

  cout << endl << endl;
  cout << "Hello! Welcome to the guessing number game." << endl
       << "You will have to guess a number between " << MIN_VALUE << " and "
       << MAX_VALUE << " to win." << endl << endl;
  cout << "Press enter when you are ready to play....";
  cin.get();

  while (tolower(ans) == YES) {
    randNum = rand() % ((MAX_VALUE - MIN_VALUE) + 1) + MIN_VALUE;
    cout << "Guess a number between " << MIN_VALUE << " - " << MAX_VALUE
         << ": ";
    cin >> guess;
    while (guess != randNum) {
      if (guess > randNum) {
        cout << "Too high!" << endl;
      } else {
        cout << "Too low!" << endl;
      }
      cout << "Guess a number between " << MIN_VALUE << " - " << MAX_VALUE
           << ": ";
	    cin >> guess;
      }

    cout << "Correct!" << endl;
    cout << endl << "Want to play again? (y/n): ";
    cin >> ans;
  }

  cout << "Thank you for playing. Goodbye!" << endl;
  cout << endl << endl;
  return 0;
}
