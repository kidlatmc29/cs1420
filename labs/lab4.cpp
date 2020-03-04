// Isabel Ovalles
// lab4.cpp

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int userInput;
  // 1. x num of x on one line
  cout << " 1.) Please supply an integer: ";
  cin >> userInput;

  for (int i = userInput; i > 0; i--){
    cout << userInput;
  }

  cout << endl << endl;

  // 2. x num of 1s
  cout << " 2.) Please supply another integer: ";
  cin >> userInput;
  for (int j = userInput; j > 0; j--){
    cout << "1" << endl;
  }

  cout << endl << endl;

  // 3. the multiplcation table to x
  cout << " 3.) Please supply another integer (Between 1 - 9): ";
  cin >> userInput;

  for(int g = 1; g <= userInput; g++){
    cout << " " << setw(2) << g;
  }

  cout << endl;

  for(int k = 1; k <= userInput; k++){
    cout << k;
    for(int h = 1; h <= userInput; h++){
      cout << setw(2) << k * h << " ";
    }
    cout << endl;
  }
  cout << endl << endl;

  // 4. num of x triangle
  cout << " 4.) Please supply another integer: ";
  cin >> userInput;

  for(int n = 1; n <= userInput; n++) {
    for (int m = 1; m <= n; m++) {
      cout << n << " ";
    }
    cout << endl;
  }
  cout << endl << endl;

  // 5. the outline of a half-diamond, with x at the widest point
  cout << " 5.) Please supply another integer: ";
  cin >> userInput;
  for(int t = 1; t <= userInput; t++) {
    for(int spaces = 1; spaces < t; spaces++) {
      cout << " ";
    }
    cout << t << endl;
  }

  for (int b = userInput - 1; b > 0; b--) {
    for(int spaces = b - 1; spaces > 0; spaces--) {
      cout << " ";
    }
    cout << b << endl;
  }

  cout << endl << endl;
  return 0;
}
