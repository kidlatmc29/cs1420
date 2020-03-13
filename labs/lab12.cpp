// Isabel Ovalles
// lab12.cpp

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
const int AGE_SPACE = 4;
const char SPACE = ' ';
const string FILENAME = "/home/fac/sreeder/class/cs1420/lab11input.dat";

int readFile(CoffeeDrinker arr[]);
// returns the number of CoffeDrinkers stored in the file

void selectionSort(CoffeeDrinker arr[], int numOfElements);
// sorts an array of CoffeeDrinkers in alphabetical order

void swapCoffee(CoffeeDrinker& p1, CoffeeDrinker& p2);
// swaps CoffeeDrinkers form two given indexs

int findOldest(CoffeeDrinker arr[], int numOfElements);
// linear search that finds the oldest person

int findLeastCoffee(CoffeeDrinker arr[], int numOfElements);
// linear search that finds the person who drinks the least coffee

void printRecord(CoffeeDrinker record);
// prints CoffeeDrinker with labels

double avgAge(CoffeeDrinker arr[], int numOfElements);
// returns the avg age of a person in the array

int totalCups(CoffeeDrinker arr[], int numOfElements);
// returns the total cups of coffees consumed by everyone in the array

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

  cout << "Unsorted Records: " << endl;
  for(int i = 0; i < numOfElements; i++)
    printRecord(arr[i]);

  cout << endl << endl;

  cout << "Sorted Records: " << endl;
  selectionSort(arr, numOfElements);
  for(int i = 0; i < numOfElements; i++)
    printRecord(arr[i]);

  cout << endl << endl;

  cout << "Average Age: " << avgAge(arr, numOfElements)
       << endl << endl;

  cout << "Total of coffee cups consumed: " << totalCups(arr, numOfElements);

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
  int indexSwap;

  for(int index = 0; index < numOfElements; index++) {
    indexSwap = index;
    for(int j = index + 1; j < numOfElements; j++) {
      if(arr[j].name < arr[indexSwap].name) {
        indexSwap = j;
      }
    }
    swapCoffee(arr[index], arr[indexSwap]);
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

void swapCoffee(CoffeeDrinker& p1, CoffeeDrinker& p2)
{
  CoffeeDrinker temp = p1;
  p1 = p2;
  p2 = temp;
}

void printRecord(CoffeeDrinker record)
{
  cout << "Name: " << left <<  setw(NAME_SPACE) << record.name << SPACE
       << "Age: "  << setw(AGE_SPACE) << record.age << SPACE
       << "Coffee: " <<  record.coffee
       << endl;
}

double avgAge(CoffeeDrinker arr[], int numOfElements)
{
  double sum = 0;
  for(int index = 0; index < numOfElements; index++) {
    sum += arr[index].age;
  }
  return (sum/numOfElements);
}

int totalCups(CoffeeDrinker arr[], int numOfElements)
{
  int total;
  for(int index  = 0; index < numOfElements; index++) {
    total += arr[index].coffee;
  }
  return total;
}
