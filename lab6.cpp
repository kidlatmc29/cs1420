// Isabel Ovalles
// lab6.cpp

#include <iostream>

using namespace std;

void input(string &values1, string &values2);
// returns two string values given by the user

void swapStr(string &val1, string &val2);

void output(string str1, string str2);
// prints two strings a with space between

int main()
{
  string string1 = " ";
  string string2 = " ";

  cout << endl << endl;
  input(string1, string2);
  output(string1, string2);
  swapStr(string1, string2);
  output(string1, string2);
  cout << endl << endl;

  return 0;
}

void input(string &num1, string &num2)
{
  cout << "Please provide 2 string values: ";
  cin >> num1 >> num2;
}

void output(string str1, string str2)
{
  cout << str1 << " " << str2 << endl;
}

void swapStr(string &val1, string &val2)
{
  string temp = " ";
  temp = val1;
  val1 = val2;
  val2 = temp;
}
