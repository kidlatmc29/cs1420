// Isabel Ovalles
// lab6.cpp

#include <iostream>

using namespace std;

void input(string &values1, string &values2);
// returns two string values given by the user

void swapStr(string &val1, string &val2);
// switches the two values

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

void input(string &value1, string &value2)
{
  cout << "Please provide two single words: ";
  cin >> value1 >> value2;
}

void swapStr(string &val1, string &val2)
{
  string temp = " ";
  temp = val1;
  val1 = val2;
  val2 = temp;
}

void output(string str1, string str2)
{
  cout << str1 << " " << str2 << endl;
}
