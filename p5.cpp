// Isabel Ovalles
// 2-29-2020
// p5.cpp

// Purpose: This program serves as an inventory for the store
//
// Input:
//
// Processing:
//
// Output:
//
// Example:

#include<iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Part
{
  string name;
  string manufacturer;
  int quantity;
  int mininum;
  double unitPrice;
};

const int MAX_PARTS = 150;

void welcome();

int readFile(Part Parts[], int maxParts);

void printParts(const Part Parts[], int& numOfElements);

void goodbye();

int main()
{
  Part parts[MAX_PARTS];
  int numOfElements; // tacks num of parts in Parts[]

  welcome();
  numOfElements = readFile(parts, MAX_PARTS);

  printParts(parts, numOfElements);


  goodbye();
  return 0;
}

void welcome()
{
  cout << endl << endl;
  cout << " - Welcome to Everything Electronic! Inventory System - ";
  cout << endl;
}

int readFile(Part parts[], int maxParts)
{
  ifstream inFile;
  string fileName;
  int count = 0;

  cout << "Please enter an input file name: ";
  cin >> fileName;

  inFile.open(fileName);

  if(inFile.fail()) {
    return false;
  }

  cout << "Reading from " << fileName << endl;
  while(count < maxParts && inFile >> parts[count].name) {
    inFile >> parts[count].manufacturer;
    inFile >> parts[count].quantity;
    inFile >> parts[count].mininum;
    inFile >> parts[count].unitPrice;
    count++;
  }

  cout << "There were " << count << " parts in this file." << endl;
  inFile.close();
  return count;
}

void printParts(const Part parts[], int& numOfElements)
{
  cout << "Printing array of Parts: " << endl;
  for(int index = 0; index <= numOfElements; index++) {
    cout << parts[index].name << endl;
  }
}

void goodbye()
{
  cout << "Exiting program. Goodbye....";
  cout << endl << endl;
}
