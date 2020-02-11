// Isabel Ovalles
// lab5.cpp

#include <iostream>

using namespace std;

const char YES = 'y';
const int MIN = 5;
const int MAX = 25;

void welcome();

int input();
// returns values from MIN to MAX

int summation(int num);
// returns the sum of 1 to the integer num

void goodbye();

int main()
{
  char answer = YES;
  int userInput;
  int sum;
  welcome();

  while(answer == YES) {
    userInput = input();
    sum = summation(userInput);
    cout << "The summation of " << userInput << " is " << sum << "." << endl;
    cout << "Again? (y/n): ";
    cin >> answer;
    cout << endl;
  }
  goodbye();
  return 0;
}

void welcome()
{
  cout << endl << endl;
  cout << "Welcome to lab 5!" << endl;
}

int input()
{
  int value = 0;
  while(value < MIN || value > MAX){
    cout << "Please supply an integer between "
        << MIN << " and " << MAX << ": ";
    cin >> value;
  }
  return value;
}

int summation(int num)
{
  int sum = 0;
  for(int i = 0; i <= num; i++) {
      sum += i;
  }
  return sum;
}

void goodbye()
{
  cout << "Thank you! Goodbye....." << endl << endl << endl;
}
