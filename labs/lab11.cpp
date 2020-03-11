// Isabel Ovalles
// lab11.cpp

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

struct CoffeeDrinker
{
  string name;
  int age;
  int coffee;
};

const int MAX = 150;
const int NAME_SPACE = 15;
const int AGE_SPACE = 10;
const int COFFEE_SPACE = 10;
const string FILENAME = "/home/fac/sreeder/class/cs1420/lab11input.dat";

int readFile(CoffeeDrinker arr[]);
// returns the number of CoffeDrinkers stored in the file

void selectionSort(CoffeeDrinker arr[], int numOfElements);
// sorts an array of CoffeeDrinkers in alphabetical order

void swap(CoffeeDrinker arr[], int index, int indexSwap);
// swaps CoffeeDrinkers form two given indexs

int findOldest(CoffeeDrinker arr[], int numOfElements);
// linear search that finds the oldest person

int findLeastCoffee(CoffeeDrinker arr[], int numOfElements);
// linear search that finds the person who drinks the least coffee

void printRecord(CoffeeDrinker record);
// prints CoffeeDrinker with labels

int main()
{
  CoffeeDrinker arr[MAX];
  int numOfElements;
  int oldestIndex;
  int leastIndex;

  cout << endl << endl;
  numOfElements = readFile(arr);

  oldestIndex = findOldest(arr, numOfElements);
  leastIndex = findLeastCoffee(arr, numOfElements);

  cout << "Oldest Person: " << endl;
  printRecord(arr[oldestIndex]);
  cout << endl << endl;

  cout << "Least Coffee Drank: " << endl;
  printRecord(arr[leastIndex]);
  cout << endl << endl;

  selectionSort(arr, numOfElements);
  for(int i = 0; i < numOfElements; i++)
  printRecord(arr[i]);

  cout << endl << endl;

  return 0;
}

int readFile(CoffeeDrinker arr[])
{
  ifstream inFile;
  string fileName = FILENAME;
  int count = 0;

  inFile.open(fileName);

  if(!inFile.fail()) {
    while(count < MAX && inFile >> arr[count].name) {
      inFile >> arr[count].age
             >> arr[count].coffee;
      count++;
    }
  } else {
    count = 0;
  }
  inFile.close();
  return count;
}

void selectionSort(CoffeeDrinker arr[], int numOfElements)
{
  int switchIndex;
  for(int index = 0; index < numOfElements; index++) {
     switchIndex = index;
    for(int j = index + 1; j < numOfElements; j++) {
      if(arr[j].name < arr[index].name) {
        switchIndex = j;
      }
    }
    swap(arr, index, switchIndex);
  }
}

int findOldest(CoffeeDrinker arr[], int numOfElements)
{
   int oldest = 0;

   for(int index = 0; index < numOfElements; index++) {
     if(arr[index].age > arr[oldest].age) {
       oldest = index;
     }
   }
   return oldest;
}

int findLeastCoffee(CoffeeDrinker arr[], int numOfElements)
{
  int leastCoffee = 0;

  for(int index = 0; index < numOfElements; index++) {
    if(arr[index].coffee < arr[leastCoffee].coffee) {
      leastCoffee = index;
    }
  }
  return leastCoffee;
}

void swap(CoffeeDrinker arr[], int index, int indexSwap)
{
  CoffeeDrinker temp = arr[index];
  arr[index] = arr[indexSwap];
  arr[indexSwap] = temp;
}

void printRecord(CoffeeDrinker record)
{
  cout << "Name: " << record.name <<  setw(NAME_SPACE)
       << "Age: "  << record.age  << setw(AGE_SPACE)
       << setw(COFFEE_SPACE)  << "Coffee: " <<  record.coffee
       << endl;
}
