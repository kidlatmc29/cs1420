// Isabel Ovalles
// 2-29-2020
// p5.cpp

// Purpose: This program serves as an inventory database for the store.
//
// Input: The user gives the name of a file that contains data on electronic
// items. From the file given, its contents is stored into an array of parts.
// The user chooses from a menu 0 - 2 on what they'd like the program to do.
//
// Processing: When given the file name, the program creates a new Part struct
// and stores all of them into an array of Parts.
//
// Output: If the user asks for an inventory report, then a table of all the
// electronic parts with its name, manufacturer, current quantity, mininum
// quantity as well as its unit price is printed. Additional data including,
// total number of parts and total cost is printed at the end. The other o
//
//
// Example: The user enter the file name 'p5data.dat'. A menu appears and
// the user enters '1' which is to print out an entire inventory report.

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
const int COL = 13;
const char QUIT = 'q';
const char RESTOCK = 'r';
const char INVENTORY = 'i';

void welcome();

int readFile(Part Parts[], int maxParts);
// returns the number of parts stored in the array
// returns 0 if the file failed to open
// When reading from the file, assume if there is a name, the

void printParts(const Part Parts[], int numOfElements);
// only here for debugging purposes!!!! remove when submitting
// displays the array of Parts

void selectionSort(Part Parts[], int numOfElements);
// sorts all the parts in the given array by name, alphabetically

void swap(Part Parts[], int index, int indexSwap);
// swaps the two values of an array at the given indices

char getMenuChoice();
// asks user for 1 of 3 menu choices

void goodbye();

int main()
{
  Part parts[MAX_PARTS];
  int numOfElements; // total num of parts in Parts[]
  char menuChoice;

  welcome();
  numOfElements = readFile(parts, MAX_PARTS);

  if(numOfElements > 0) {
  printParts(parts, numOfElements);
  cout << endl << endl;
  cout << "Sorted Parts: " << endl;
  selectionSort(parts, numOfElements);
  printParts(parts, numOfElements);
  }

  while(menuChoice != QUIT) {
    while(menuChoice != QUIT && menuChoice != INVENTORY
          && menuChoice != RESTOCK) {
        menuChoice = getMenuChoice();
    }

    cout << "menue choice is " << menuChoice << endl;
    switch(menuChoice)
    {
      case INVENTORY :
      {
        cout << "going to print out an inventory" << endl;
        menuChoice = getMenuChoice();
        break;
      }
      case RESTOCK :
      {
        cout << "going to print out a restock report" << endl;
        menuChoice =  getMenuChoice();
        break;
      }
    }
  }
  goodbye();
  return 0;
}

void welcome()
{
  cout << endl << endl;
  cout << " - Welcome to Everything Electronic!'s Inventory System - ";
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

  if(!inFile.fail()) {
    while(count < maxParts && inFile >> parts[count].name) {
      inFile >> parts[count].manufacturer;
      inFile >> parts[count].quantity;
      inFile >> parts[count].mininum;
      inFile >> parts[count].unitPrice;
      count++;
  }
  } else {
    count = 0;
    }
  inFile.close();
  return count;
}

void printParts(const Part parts[], int numOfElements)
{
  cout << "Printing array of Parts: " << endl;
  for(int index = 0; index < numOfElements; index++) {
    cout << setw(COL) << parts[index].name
         << setw(COL) << parts[index].manufacturer
         << setw(COL) << parts[index].quantity
         << setw(COL) << parts[index].mininum
         << "$" << setw(COL) << parts[index].unitPrice
         << endl;
  }
}

void selectionSort(Part parts[], int numOfElements)
{
  for(int index = 0; index < numOfElements - 1; index++) {
    for(int j = index + 1; j < numOfElements; j++) {
      if(parts[index].name > parts[j].name) {
        swap(parts, index, j);
      }
    }
  }
}

void swap(Part parts[], int index, int indexSwap)
{
  Part temp = parts[index];
  parts[index] = parts[indexSwap];
  parts[indexSwap] = temp;
}

char getMenuChoice()
{
  char choice;
  cout << endl;
  cout << "MAIN MENU:" << endl;
  cout << "  " << INVENTORY << " - [Inventory Report]" << endl;
  cout << "  " << RESTOCK << " - [Restock Report]" << endl;
  cout << "  " << QUIT << " - [Quit] " << endl;
  cout << endl;
  cout << "Please select a menu choice: ";
  cin >> choice;
  return choice;
}

void goodbye()
{
  cout << "Exiting program. Goodbye....";
  cout << endl << endl;
}
