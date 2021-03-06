// Isabel Ovalles
// 2-29-2020
// p5.cpp

// Purpose: This program serves as an inventory database for the store.
//
// Input: The user gives the name of a file that contains data on electronic
// items. From the file given, its contents is stored into an array of parts.
// The user chooses from a menu i, r, or q on what they'd like to do.
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
// Program waits at the end of the report for them to press enter, then
// menu is displayed again.

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
const char QUIT = 'q';
const char RESTOCK = 'r';
const char INVENTORY = 'i';
const int ITEM_COL = 20;
const int MAN_COL = 20;
const int QUA_COL = 7;
const int COST_COL = 14;
const int VAL_COL = 16;
const int MIN_COL = 9;
const int ORDER_COL = 5;
const int SCREEN_HEIGHT = 20;
const int SCREEN_WIDTH = 80;
const char DOLLAR = '$';
const char SPACE = ' ';
const int PRECISION = 2;
const string W_TITLE = "-Welcome to Everything Electronic's Inventory System-";
const string I_TITLE = "Inventory Report";
const int W_NUM_CHAR = 54;
const int I_NUM_CHARS = 16;
const int R_NUM_CHARS = 14;
const string R_TITLE = "Reorder Report";
const string ITEM_HEADER = "Item";
const string MAN_HEADER = "Manufacturer";
const string QUA_HEADER = "Quantity";
const string COST_HEADER = "Cost each";
const string TOTAL_VAL_HEADER = "Total value";
const string MIN_HEADER = "Mininum";
const string ORDER_HEADER = "Order";
const string ORDER_COST_HEADER = "Cost";
const string NUM_DIFF_ITEMS = "Numbers of different items: ";
const string TOTAL_QUA = "Total quantity: ";
const string TOTAL_VAL = "Total value of all items: ";
const string DIFF_ITEMS = "Number of different items to order: ";
const string TOTAL_NUM_REORDER = "Total number to reorder: ";
const string TOTAL_REORDER_COST = "Total cost:";

void welcome();

int readFile(Part parts[], int maxParts);
// returns the number of parts stored in the array
// returns 0 if the file failed to open
// when reading, if there's a name, the rest of the data exists

void selectionSort(Part parts[], int numOfElements);
// sorts all the parts in the given array by name, alphabetically

void swapParts(Part parts[], int index, int indexSwap);
// swaps the two values of an array at the given indices

char getMenuChoice();
// asks user for 1 of 3 menu choices

void printInventory(Part parts[], int numOfElements);
// prints the full inventory with totals

void printReorder(Part parts[], int numOfElements);
// prints an report of parts to be ordered with totals

void clearScreen();
// clears the screen based on SCREEN_HEIGHT

void goodbye();

int main()
{
  Part parts[MAX_PARTS];
  int numOfElements; // total num of parts in Parts[]
  char menuChoice  = 'n';

  clearScreen();
  welcome();
  numOfElements = readFile(parts, MAX_PARTS);

  if(numOfElements < 1) {
    cout << "File reading failed! Terminating programing....";
    return 0;
  }

  while(menuChoice != QUIT && numOfElements > 0) {
    selectionSort(parts, numOfElements);

    while(menuChoice != QUIT && menuChoice != INVENTORY
          && menuChoice != RESTOCK) {
        clearScreen();
        menuChoice = getMenuChoice();
    }

    switch(menuChoice)
    {
      case INVENTORY :
      {
        clearScreen();
        printInventory(parts, numOfElements);
        clearScreen();
        menuChoice = getMenuChoice();
        break;
      }
      case RESTOCK :
      {
        clearScreen();
        printReorder(parts, numOfElements);
        clearScreen();
        menuChoice =  getMenuChoice();
        break;
      }
    }
  }

  clearScreen();

  goodbye();
  return 0;
}

void welcome()
{
  cout << endl << endl;
  for(int i = 0; i < (SCREEN_WIDTH - W_NUM_CHAR) / 2; i++) {
    cout << SPACE;
  }
  cout << W_TITLE;

  for(int j = (SCREEN_WIDTH - W_NUM_CHAR) / 2; j < SCREEN_WIDTH; j++) {
    cout << SPACE;
  }
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

void selectionSort(Part parts[], int numOfElements)
{
  int indexSwap;
  for(int index = 0; index < numOfElements; index++) {
    indexSwap = index;
    for(int j = index + 1; j < numOfElements; j++) {
      if(parts[j].name < parts[indexSwap].name) {
        indexSwap = j;
      }
    }
    swapParts(parts, index, indexSwap);
  }
}

void swapParts(Part parts[], int index, int indexSwap)
{
  Part temp = parts[index];
  parts[index] = parts[indexSwap];
  parts[indexSwap] = temp;
}

char getMenuChoice()
{
  char choice;
  cout << "MAIN MENU:" << endl;
  cout << "  " << INVENTORY << " - [Inventory Report]" << endl;
  cout << "  " << RESTOCK << " - [Restock Report]" << endl;
  cout << "  " << QUIT << " - [Quit] " << endl;
  cout << endl;
  cout << "Please select a menu choice: ";
  cin >> choice;
  return choice;
}

void printInventory(Part parts[], int numOfElements)
{
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(PRECISION);

  int totalQuant = 0;
  double totalVal = 0;

  int titleSpaces = (SCREEN_WIDTH - I_NUM_CHARS) / 2;

  for(int spaces = 0; spaces < titleSpaces; spaces++) {
    cout << SPACE;
  }

  cout << I_TITLE;

  for(int spaces = 0; spaces < SCREEN_WIDTH; spaces ++) {
    cout << SPACE;
  }

  cout << endl;

  cout << left << setw(ITEM_COL) << ITEM_HEADER;
  cout << setw(MAN_COL) << MAN_HEADER;
  cout << right << setw(QUA_COL) << QUA_HEADER;
  cout << right << setw(COST_COL) << COST_HEADER;
  cout << right << setw(VAL_COL) << TOTAL_VAL_HEADER;

  cout << endl << endl;

  for(int i = 0; i < numOfElements; i++) {
    cout << left << setw(ITEM_COL) << parts[i].name
         << setw(MAN_COL) << parts[i].manufacturer;
    cout << right << setw(QUA_COL) << parts[i].quantity;
    cout << setw(COST_COL / 2) << DOLLAR
         << setw(COST_COL / 2 - 1) << parts[i].unitPrice;
    cout << setw(VAL_COL / 2) << DOLLAR << setw(VAL_COL / 2 - 1)
         << parts[i].unitPrice * parts[i].quantity << endl;

    totalQuant += parts[i].quantity;
    totalVal += parts[i].quantity * parts[i].unitPrice;
  }

  cout << endl << endl;
  cout << NUM_DIFF_ITEMS << numOfElements << endl;
  cout << TOTAL_QUA << totalQuant << endl;
  cout << TOTAL_VAL << DOLLAR << totalVal << endl << endl;
  cin.ignore();
  cout << "Press enter to continue....";
  cin.get();
}

void printReorder(Part parts[], int numOfElements)
{
  int totalDiff = 0;
  int totalReorder = 0;
  double totalCost = 0;

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(PRECISION);

  int titleSpaces = (SCREEN_WIDTH - R_NUM_CHARS) / 2;

  for(int spaces = 0; spaces < titleSpaces; spaces++) {
    cout << SPACE;
  }

  cout << R_TITLE;

  for(int spaces = 0; spaces < SCREEN_WIDTH; spaces ++) {
    cout << SPACE;
  }

  cout << endl;

  cout << left << setw(ITEM_COL) << ITEM_HEADER
       << setw(MAN_COL) << MAN_HEADER;
  cout << right << setw(QUA_COL) << QUA_HEADER
       << setw(MIN_COL) << MIN_HEADER
       << setw(ORDER_COL) << ORDER_HEADER
       << setw(COST_COL) << COST_HEADER;

  cout << endl << endl;

  for(int i = 0; i < numOfElements; i++) {
      if(parts[i].quantity < parts[i].mininum) {
        cout << left << setw(ITEM_COL) << parts[i].name
             << setw(MAN_COL) << parts[i].manufacturer;
        cout << right << setw(QUA_COL) << parts[i].quantity
             << setw(MIN_COL) << parts[i].mininum
             << setw(ORDER_COL) << (parts[i].mininum - parts[i].quantity)
             << setw(COST_COL / 2) << DOLLAR << setw(COST_COL / 2 -1)
             << parts[i].unitPrice << endl;
        totalDiff++;
        totalReorder += (parts[i].mininum - parts[i].quantity);
        totalCost += parts[i].unitPrice *
                  (parts[i].mininum - parts[i].quantity);
    }
  }

  cout << endl << endl;
  cout << NUM_DIFF_ITEMS << totalDiff << endl;
  cout << TOTAL_NUM_REORDER << totalReorder << endl;
  cout << TOTAL_REORDER_COST << SPACE << DOLLAR << totalCost << endl << endl;
  cin.ignore();
  cout << "Press enter to continue....";
  cin.get();
  cout << endl;
}

void clearScreen()
{
  for(int i = 0; i < SCREEN_HEIGHT; i++)
    cout << endl;
}

void goodbye()
{
  cout << "Exiting program. Thank you! Goodbye....";
  cout << endl << endl << endl;
}
