// Isabel Ovalles
// lab8.cpp

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

const string FILE_NAME = "/home/fac/sreeder/class/cs1420/lab8input.dat";
const int MAX_ELEMENTS = 50;
const int PRECISION = 3;
const int INDEX_WIDTH = 5;
const int VALUE_WIDTH = 7;

int readFile(double arr[]);
// returns number of elements stored into the double array

void printList(const double arr[], int numOfElements);
// prints the elements of the array in a table

double sum(const double arr[], int numOfElements);
// returns sum of doubles from given double array

int main()
{
  double arr[MAX_ELEMENTS];
  int numOfElements;
  double total = 0;
  bool ok = true;

  cout << endl << endl;

  numOfElements = readFile(arr);
  if(numOfElements < 0 ) {
    cout << "Trouble with file! Quitting....";
    ok = false;
  }
    if(ok) {
      printList(arr, numOfElements);
      total = sum(arr, numOfElements);
      cout << "The sum is: " << total << ". ";
  }
  cout << endl << endl << endl;
  return 0;
}

int readFile(double arr[])
{
 int index = 0;
 double val;
 ifstream inFile;
 string fileName = FILE_NAME;

 inFile.open(fileName);
 if(inFile.fail()) {
   return index;
 }

  while(inFile >> val) {
    arr[index] = val;
    index++;
  }

 inFile.close();

 return index;
}

void printList(const double arr[], int numOfElements)
{
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(PRECISION);

  cout << setw(INDEX_WIDTH) << "Index ";
  cout << setw(VALUE_WIDTH) << "Value";

  cout << endl;
  for(int index = 0; index < numOfElements; index++) {
    cout << setw(INDEX_WIDTH) << index << " ";
    cout << setw(VALUE_WIDTH) << arr[index];
    cout << endl;
  }
  cout << endl;
}

double sum(const double arr[], int numOfElements)
{
  double currentSum = 0.0;
  for(int index = 0; index < numOfElements; index++) {
    currentSum += arr[index];
  }
  return currentSum;
}
