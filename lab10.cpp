// Isabel Ovalles
// lab10.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int MAX = 20;
const int INDEX = 7;
const int VALUE = 15;

void printList(int arr[], int numOfElements);
// prints the existing indices and their values

int main()
{
  int numOfElements = 0;
  int arr[MAX];
  srand(time(0));

  cout << endl << endl;

  while (numOfElements  < 1 || numOfElements > MAX) {
  cout << "How many elements should be filled? ";
  cin >> numOfElements;

  for(int index = 0; index < numOfElements; index++) {
    arr[index] = random();
  }

  printList(arr, numOfElements);

  cout << endl << endl;
}

  cout << endl << endl;
  return 0;
}

void printList(int arr[], int numOfElements)
{
  cout << endl;
  cout << setw(INDEX) << "Index";
  cout << setw(VALUE) << "Value" << endl;
  for(int index = 0; index < numOfElements; index++) {
    cout << setw(INDEX) << index;
    cout << setw(VALUE) << arr[index] << endl;
  }
}
