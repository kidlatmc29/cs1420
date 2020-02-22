// Isabel Ovalles
// p3.cpp
// 2-16-2020

// Purpose: This program plays the game Chutes and Ladders with the user
// against the computer as an opponent.

// Input: The user provides a name to the program and presses enter to spin.

// Processing: The program will spin the spinner by generating a random number
// at the beginning of a turn. That random number is then added to the player's
// position on the board. The new position will be checked if it is a chute
// or ladder. The final position is updated accordingly.

// Output: When the user spins to move, the program prints how many spaces
// they are going to move. This also occurs when the computer spins, which
// tells the user how many spaces the computer will move and what number
// square the computer lands on. The program prints out if the user lands on
// a ladder, chute or neither.

// Example: Name given: "Alex" Prints the message: "It's Alex's turn now. Alex
// is at square 0." A spin: "Alex spun a 4." After checking location:
// "Alex landed on a ladder!" Final position is updated: "Alex is now at
// square 14."

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const char YES = 'y';
const int MIN_SPIN = 1; // min spin
const int MAX_SPIN = 6; // max spin
const int STARTING_POSITION = 0; // start square for players
const int WINNING_SQUARE = 100; // board size
const string COMPUTER_NAME = "HAL"; // computer name

void welcome();
// displays welcome message and game description

string getName();
// asks for player's name
// returns the player's name

int spin();
// returns a valid spin value from MIN_SPIN to MAX_SPIN

int takeTurn(int position, string name);
// takes the turn for name
// returns the new position

int checkLocation(int position);
// returns value of ladder or chute at that location
// returns 0 if none

void goodbye();
// displays goodbye message

int main()
{
  string userName; // Stores the user's name.
  char answer; // Stores user's answer to play the game again.
  int userPosition; // Stores the user's positon on the board.
  int computerPosition; // Stores the computer's position on the board.
  bool computerTurn = false;
  srand(time(0));

  welcome();
  userName = getName();

  answer = YES;

  while(tolower(answer) == YES) {
    userPosition = STARTING_POSITION;
    computerPosition = STARTING_POSITION;
    while(userPosition != WINNING_SQUARE &&
          computerPosition != WINNING_SQUARE) {
      if(computerTurn) {
        computerPosition = takeTurn(computerPosition, COMPUTER_NAME);
        computerTurn = false;
      } else {
        userPosition = takeTurn(userPosition, userName);
        computerTurn = true;
      }
  }
    cout << "Want to play again? (y/n): ";
    cin >> answer;
  }
  goodbye();
  return 0;
}

void welcome()
{
  cout << endl << endl;
  cout << "Welcome to the Chutes and Ladders Game! " << endl << endl;
  cout << "The first player to reach " << WINNING_SQUARE
       << " exactly, wins the game!" << endl;
  cout << "Press enter to spin the spinner for moves." << endl;
  cout << "On certain spaces, there will be chutes that will move you down the"
       << " board, " << endl
       << "or ladders that will move you up the board. Good luck!"
       << endl << endl;
}

string getName()
{
  string name;
  cout << "Your opponent will be HAL. Please enter your name: ";
  getline(cin, name);
  cout << endl;
  return name;
}

int spin()
{
  return rand() % ((MAX_SPIN - MIN_SPIN) + 1) + MIN_SPIN;
}

int takeTurn(int position, string name)
{
  int currentSpin;
  int currentPosition = position;
  int adjustment; // stores moves after chute or ladder

  //tells player where they are on the board
  cout << "It is " << name << "'s turn now. " << endl;
  cout << name << " is on square " << position << "." << endl;
  cout << "Press enter to spin.....";
  cin.get();
  currentSpin = spin();
  cout << name << " spun a " << currentSpin << "." << endl;
  cout << "Press enter to continue....";
  cin.get();

  // checks if moves from spin will go over WINNING_SQUARE
  if(currentPosition + currentSpin <= WINNING_SQUARE) {
    currentPosition += currentSpin;
  }

  adjustment = checkLocation(currentPosition);

  if (currentPosition == WINNING_SQUARE ||
     (currentPosition + adjustment) == WINNING_SQUARE) {
    cout << name << " landed on square " << WINNING_SQUARE << "! " << endl;
    cout << name << " has won the game! Congrats!" << endl << endl;
    currentPosition += adjustment;
  } else if (adjustment < 0) {
    cout << name << " landed on a chute!" << endl;
    currentPosition += adjustment;
    cout << name << " is now at square " <<  currentPosition << "!"
         << endl << endl;
  } else if (adjustment > 0) {
    cout << name << " landed on a ladder!" << endl;
    currentPosition += adjustment;
    cout << name << " is now at square " << currentPosition << "!"
         << endl << endl;
  } else {
    cout << name << " did not land on a chute or ladder." << endl;
    cout << name << " is now at square " << currentPosition << "!"
         << endl << endl;
  }
  return currentPosition;
}

int checkLocation(int position)
{
  if (position == 1) {
    return 37;
  } else if (position == 4) {
    return 10;
  } else if (position == 9){
    return 12;
  } else if (position == 23){
    return 21;
  } else if (position == 28) {
    return 56;
  } else if (position == 36) {
    return 8;
  } else if (position == 51) {
    return 15;
  } else if (position == 71) {
    return 19;
  } else if (position == 80) {
    return 20;
  } else if(position == 98) {
    return -20;
  } else if(position == 95) {
    return -20;
  } else if (position == 93) {
    return -20;
  } else if (position == 87) {
    return -63;
  } else if (position == 64) {
    return -4;
  } else if (position == 62) {
    return -43;
  } else if (position == 56) {
    return -3;
  } else if (position == 49) {
    return -38;
  } else if (position == 48) {
    return -22;
  } else if (position == 16) {
    return -10;
  }
  return 0;
}

void goodbye()
{
  cout << endl << endl;
  cout << "Thanks for playing! Goodbye.... " << endl << endl << endl;
}
