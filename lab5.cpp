// Isabel Ovalles
// lab5.cpp

#include <iostream>

using namespace std;

const char YES = 'y';

void welcome();
void input();
int summation(int num);
void goodbye();

int main()
{
  welcome();
  summation(input());

  goodbye();
  return 0;
}

void welcome()
{
  cout << "Welcome to lab 5! ";
}

void input()
{
  cout << "Please supply an integer to summate: ";
}

int summation(int num)
{
  int sum = 0;
  for(int i = 0; i <= num; i++){
      sum += i;
  }
  return sum;
}
