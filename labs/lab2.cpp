// Isabel Ovalles
// lab2.cpp

#include <iostream>

using namespace std;

int main()
{
  string name; 
  int int1; 
  int int2; 
  double dnum1; 
  double dnum2; 

  cout << endl << endl; 
  cout << "Please enter your name: "; 
  cin >> name; 
  cout << "This is your name: " << name; 

  cout << endl << endl; 

  cout << "Please enter an integer: "; 
  cin >> int1;
  cout << "Please enter a second integer (less than the first one): ";
  cin >> int2; 
  
  cout << endl;
  cout << "Division gives: " << int1 / int2 << endl; 
  cout << "Modulus gives: " << int1 % int2 << endl; 
  
  cout << endl; 
  cout << "Please enter a float point number: ";
  cin >> dnum1; 
  cout << "Please enter a second float point number (less than the first one): "; 
  cin >> dnum2; 

  cout << endl; 
  cout << "Division gives: " << dnum1 / dnum2 << endl; 

  cout << endl << endl; 

  return 0; 
 }
