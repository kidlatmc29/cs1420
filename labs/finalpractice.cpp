// Isabel Ovalles
// finalpractice.cpp

// final exam practice includes:
// - functions (pass by ref and pass by value)
// - structs
// - linear and binary searching
// - arrays of structs
// - selection sort

// Practice: Create a struct called Book, which holds the following values:
// its title, the author, the length of the book, the year it was published.

// Create an array of type Book. Write funtions that can sort based on the given
// values. Write one linear and one binary search that can find the shortest
// book and a book based on an author's name.

// Main should execute as so:
// 1.) Read in a file of books and populate an array of type book
// 2.) Search (linear) for the shortest book in page length
// 3.) Sort the array based on author's name alphabetically
// 4.) Search (binary) for the first book written by Lowry
// 5.) Sort based on year published, in nondescending order. Print out the arr.


#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Book {
  string title;
  string author;
  unsigned int totalPages;
  unsigned int year;
};

const int MAX = 10;
const string DATA = "finalpracticeinput.dat";

void welcome();

int readFile(Book list[], int maxBooks);

void printBook(Book list[], int index);

int findShortest(Book list[], int numOfBooks);

void goodbye();

int main()
{
  Book list[MAX];
  int numOfBooks = 0;

  numOfBooks = readFile(list, MAX);

  if(numOfBooks < 1) {
    cout << "Problem with file. Press [ENTER] to quit the program...";
    cin.get();
    goodbye();
    return 0;
  }

  cout << "List of books in Isabel's bookshelf: " << endl;
  for(int index = 0; index < numOfBooks; index++) {
    printBook(list, index);
  }

  cout << endl << endl 
       << "The shortest book is: " << list[findShortest(list, numOfBooks)].totalPages
       << endl << endl;
  goodbye();
  return 0;
}

void welcome()
{
  cout << endl << endl;
  cout << "Welcome to Isabel's Bookshelf!" << endl << endl;
}

int readFile(Book list[], int maxBooks)
{
  ifstream inFile;
  string fileName = DATA;
  int count = 0;

  cout << "Reading data from " << fileName << "....." << endl << endl;
  inFile.open(fileName);

  if(!inFile.fail()) {
    while(count < maxBooks && inFile >> list[count].title) {
      inFile >> list[count].author
             >> list[count].totalPages
             >> list[count].year;
      count++;
    }
  } else {
    count = 0;
  }
  inFile.close();
  return count;
}

void printBook(Book list[], int index)
{
  cout << "Title: " << list[index].title << endl
       << "Author: " << list[index].author << endl
       << "Publish Year: " << list[index].year << endl
       << "Page Count: " << list[index].totalPages << endl
       << endl;
}

int findShortest(Book list[], int numOfBooks)
{
  int shortest = 0; 
  for(int i = 0; i < numOfBooks; i++) {
    if(list[i].totalPages < list[shortest].totalPages) {
      shortest = i;
    }
  }

  return shortest;
}

void goodbye()
{
  cout << "Goodbye! Please come again!" << endl << endl;
}
