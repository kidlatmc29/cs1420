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
const string FILENAME = "/home/fac/sreeder/class/cs1420/lab11input.dat";

int readFile();
// returns the number of CoffeDrinkers stored in the file

void swap();
// swap

int main()
{
  CoffeeDrinker list[MAX];
  int numOfElements;

  numOfElements = readFile(list);

  return 0;
}

int readFile(CoffeeDrinkers list[])
{
  ifstream inFile;
  string fileName = FILENAME;
  int count = 0;

  inFile.open(fileName);

  if(!inFile.fail()) {
    while(count < MAX && inFile >> list[count].name) {
      inFile >> list[count].age
             >> list[count].coffee;
      count++;
    }
  } else {
    cout = 0;
  }
  inFile.close();
  return count;
}

void selectionSort()
{
  int switch;

  for(int index = 0; index < numOfElements; index++)
  {
    int switch = index;
    for(int j = index +1; j < numOfElements; j++) {
      if(list[j] < list[index]) {
        switch = j;
      }
    }
  }
}

int findOldest(CoffeeDrinkers list[], int numOfElements)
{
   // linear search that finds the oldest person
   int index = 0;
   int oldest = 0;
   while(index < numOfElements) {
     if(list[index + 1].age > list[index].age) {
       oldest = index + 1;
     }
     index++
   }
    return -1;
}

int findLeastCoffee(CoffeeDrinker)
{
  // linear search that finds the person who drinks the least coffee
  return -1;
}

void swap(CoffeeDrinkers list[], int index, int indexSwap)
{
  CoffeeDrink temp = list[index];
  list[index] = list[indexSwap];
  list[indexSwap] = temp;

}
