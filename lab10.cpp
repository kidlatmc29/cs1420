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

void printList(const int arr[], int numOfElements);
// prints the existing indices and their values

void selectionSort(int arr[], int numOfElements);
// sorts integer arrays from greatest to least using selection sort

void swapInt(int arr[], int index, int swapIndex);
// swaps the values of two intgers in an array


int main()
{
  int numOfElements = 0;
  int arr[MAX];
  srand(time(0));

  cout << endl << endl;

  while (numOfElements  < 1 || numOfElements > MAX) {
  cout << "How many elements should be filled? ";
  cin >> numOfElements;
  }

  for(int index = 0; index < numOfElements; index++) {
    arr[index] = random();
  }

  printList(arr, numOfElements);

  cout << endl;

  cout << "Sorted Array: " << endl;
  selectionSort(arr, numOfElements);
  printList(arr, numOfElements);

  cout << endl << endl;
  return 0;
}

void printList(const int arr[], int numOfElements)
{
  cout << endl;
  cout << setw(INDEX) << "Index";
  cout << setw(VALUE) << "Value" << endl;
  for(int index = 0; index < numOfElements; index++) {
    cout << setw(INDEX) << index;
    cout << setw(VALUE) << arr[index] << endl;
  }
}

void selectionSort(int arr[], int numOfElements)
{
  for(int index = 0; index < numOfElements - 1; index++) {
    for(int j = index + 1; j < numOfElements; j++) {
      if(index + 1 < numOfElements && arr[index] > arr[j]) {
        swapInt(arr, index, j);
      }
    }
  }
}

void swapInt(int arr[], int index, int swapIndex)
{
  int temp = arr[index];
  arr[index]  = arr[swapIndex];
  arr[swapIndex] = temp;
}