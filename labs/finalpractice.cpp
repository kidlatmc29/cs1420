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
// 4.) Search (binary) for the first book written by _______
// 5.) Sort based on year published, in nondescending order. Print out the arr.


#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Book {
  string title;
  string author;
  unsigned int totalPages;
};

int main()
{


  return 0;
}
