// Isabel Ovalles
// 1-25-2020
// p2.cpp

// Purpose: This program plays a number guessing game with the user. A main
// menu is displayed to the user. They can pick from playing the game, checking
// their top three scores, or quitting the game.
//
// Input: If the user chooses to play the game, they type 'p' and
// they will input numbers ranging from 1 to 25. If the user chooses to
// view their top three scores, they type 'v'. If the user wants to quit the
// game, they type 'q' and the program will end.
//
// Processing:
// The program will compare the user's guess to the random generated number
// and will continue until the user's guess matches the random number.
//
// Output: Program will print out the user if their guess is
// too high, too low or correct.
//
// Examples:
// The random number is 12, and the user guesses 15, the game will
// print out "Too high!". When the user guesses again, with 10, the game will
// print out "Too low!" and they guess again. When the user guesses 12, the
// game will print out "Correct!" and ask the user if they want to play again.

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int MAX_VALUE = 10; // Stores upperbounds of the possible random number.
const int MIN_VALUE = 1; // Stores lowerbounds of the possible random number.
const char YES = 'y';
const char PLAY = 'p';
const char VIEW = 'v';
const char QUIT = 'q';

int main()
{
  srand(time(0));
  char selection; // Stores user selection from the menu.
  int first; // Stores highest score.
  int second; // Stores the second highest score.
  int third; // Stores the third highest score.
  int randNum; // Stores the random number for the user to guess.
  int guess; // Stores the current user's guess.
  int numOfGuesses; // Stores number of guesses for one round.
  int roundNum; // Stores the number of rounds of the game the player plays.

  cout << endl << endl;
  cout << "Hello! Welcome to the guessing number game." << endl << endl;

while (selection != QUIT) {
  cout << "=== MAIN MENU ===" << endl;
  cout << " P - [Play Game]" << endl;
  cout << " V - [View Top 3 Scores]" << endl;
  cout << " Q - [Quit] " << endl;
  cout << "=================" << endl;

  cout << "Please enter a selection: ";
  cin >> selection;
  cin.ignore();

  switch(tolower(selection))
  {
    case PLAY :
    {
      first = 0;
      second = 0;
      third = 0;
      numOfGuesses = 1;

      cout << "You will have to guess a number between " << MIN_VALUE
      << " and " << MAX_VALUE << " to win." << endl << endl;
      cout << "Press enter when you are ready to play....";
      cin.get();

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
        cout << "Guess a number between " << MIN_VALUE << " - "
             << MAX_VALUE
             << ": ";
        cin >> guess;
        numOfGuesses++;
      }
      cout << "Correct!" << endl;
      roundNum++;
      // cout << endl << "num of guesses this round: " << numOfGuesses << endl;

      // storing and comparing scores here
      if (first == 0){
        first = numOfGuesses;
      } else if (numOfGuesses < first){
        third = second;
        second = first;
        first = numOfGuesses;
      }
      if (second == 0 && (first < numOfGuesses)){
        second = numOfGuesses;
      } else if(numOfGuesses < second){
        third = second;
        second = numOfGuesses;
      }
      if (third == 0 && (second < numOfGuesses)){
        third = numOfGuesses;
      } else if (numOfGuesses < third) {
        third = numOfGuesses;
      }
        break;
      }
    case VIEW :
    {
      cout << "=== TOP THREE SCORES ===" << endl
        << first << endl
        << second << endl
        << third << endl;
      break;
    }
    default :
    {
      if(selection != QUIT) {
        cout << "Invalid selection." << endl;
      } else {
        cout << "Quiting game.... Goodbye! " << endl << endl << endl;
        }
    }
  return 0;
    }
  }
}
