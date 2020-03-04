// Isabel Ovalles
// 1-25-2020
// p2.cpp

// Purpose: This program plays a number guessing game with the user. A main
// menu is displayed to the user. They can pick from playing the game, checking
// their top three scores, or quitting the game.
//
// Input: If the user chooses to play the game, they type 1 and
// they will input numbers ranging from 1 to 25. If the user chooses to
// view their top three scores, they type 2. If the user wants to quit the
// game, they type 3 and the program will end.
//
// Processing:
// The program will compare the user's guess to the random generated number
// and will continue until the user's guess matches the random number.
//
// Output: Program will print out messages based on if the user's guess is
// too high, too low or correct. If the user chooses to view their scores
// the top three scores will be printed out.
//
// Examples:
// The user is prompted to pick a selection from the menu. There player
// selects 'p' and starts a game. The random number is 12, and the user guesses
// 15, the game will print out "Too high!". When the user guesses again, with
// 10, the game will print out "Too low!" and they guess again.
// When the user guesses 12, the game will print out "Correct! It took you 3
// guesses to win!"

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int MAX_VALUE = 15; // Stores upperbounds of the possible random number.
const int MIN_VALUE = 1; // Stores lowerbounds of the possible random number.
const char YES = 'y';
const int PLAY = 1; // Value for playing the game.
const int VIEW = 2; // Value for viewing scores.
const int QUIT = 3; // Value for quiting game.

int main()
{
  srand(time(0));
  int selection; // Stores user selection from the menu.
  int first; // Stores highest score.
  int second; // Stores the second highest score.
  int third; // Stores the third highest score.
  int randNum; // Stores the random number for the user to guess.
  int guess; // Stores the current user's guess.
  int numOfGuesses; // Stores number of guesses for one round.

  cout << endl << endl;
  cout << "Hello! Welcome to the guessing number game." << endl << endl;

  first = 0;
  second = 0;
  third = 0;

  while (selection != QUIT) {
    cout << "MAIN MENU:" << endl;
    cout << "  " << PLAY << " - [Play Game]" << endl;
    cout << "  " << VIEW << " - [View Scores]" << endl;
    cout << "  " << QUIT << " - [Quit] " << endl;
    cout << endl;

    cout << "Please enter a selection: ";
    cin >> selection;
    cin.ignore();

    switch(selection)
    {
      case PLAY :
      {
        cout << "You will have to guess a number between " << MIN_VALUE
        << " and " << MAX_VALUE << " to win." << endl << endl;
        cout << "Press enter when you are ready to play....";
        cin.get();

        randNum = rand() % ((MAX_VALUE - MIN_VALUE) + 1) + MIN_VALUE;
        cout << "Guess a number between " << MIN_VALUE << " - " << MAX_VALUE
             << ": ";
        cin >> guess;
        numOfGuesses = 1;

        while (guess != randNum) {
          if (guess > randNum) {
            cout << "Too high!" << endl << endl;
          } else {
            cout << "Too low!" << endl << endl;
          }
          cout << "Guess a number between " << MIN_VALUE << " - "
               << MAX_VALUE
               << ": ";
          cin >> guess;
          numOfGuesses++;
        }
        cout << "Correct!" << endl;
        cout << "It took you " << numOfGuesses << " guesses to win!"
            << endl << endl;

        // Storing and comparing scores occurs here
        if (first == 0) {
          first = numOfGuesses;
        } else if (numOfGuesses < first) {
          third = second;
          second = first;
          first = numOfGuesses;
        } else if (second == 0) {
          second = numOfGuesses;
        } else if (numOfGuesses < second) {
          third = second;
          second = numOfGuesses;
        } else if (third == 0) {
          third = numOfGuesses;
        } else if (numOfGuesses < third) {
          third = numOfGuesses;
        }
          selection = 0;
          break;
      }
      case VIEW :
      {
        cout << "TOP THREE SCORES   " << endl;
          if(first != 0) {
            cout << " " << first << endl;
          }

          if(second != 0) {
            cout << " " << second << endl;
          }

          if(third != 0) {
            cout << " " << third << endl;
          }
          cout << endl << endl;

          selection = 'a';
          break;
      }
      case QUIT :
      {
        cout << "Quiting game.... Goodbye! " << endl << endl << endl;
        break;
      }
      default :
      {
        cout << "Invalid selection." << endl << endl;
      }
    }
  }
  return 0;
}
