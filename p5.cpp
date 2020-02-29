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

bool readFile(Part Parts[], int& numOfElements);

void printParts(const Part Parts[], int& numOfElements);

void goodbye();

int main()
{
  Part parts[MAX_PARTS];
  int numOfElements; // tacks num of parts in Parts[]
  bool ok = true; // checks for if file reading is sucessfuly

  welcome();
  ok = readFile(parts, numOfElements);

  while(ok) {
    printParts(parts, numOfElements);
  }

  goodbye();
  return 0;
}

void welcome()
{
  cout << endl << endl;
  cout << " - Welcome to Everythin Electronic! Inventory System - ";
  cout << endl;
}

bool readFile(Part parts[], int& numOfElements)
{
  ifstream inFile;
  string fileName;
  string current;

  cout << "Please enter an input file name: ";
  cin >> fileName;

  inFile.open(fileName);
  if(inFile.fail()) {
    return false;
  }

  cout << "Reading from " << fileName << endl;
  while(inFile >> current) {
    struct Part newPart;
    parts[numOfElements] = newPart;
    cin >> parts[numOfElements].name;
    cin >> parts[numOfElements].manufacturer;
    cin >> parts[numOfElements].quantity;
    cin >> parts[numOfElements].mininum;
    cin >> parts[numOfElements].unitPrice;
    numOfElements++;
  }

  cout << "There were " << numOfElements << " parts in this file." << endl;
  inFile.close();
  return true;
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
