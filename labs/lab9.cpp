// Isabel Ovalles
// lab9.cpp

#include <fstream>
#include <iostream>

using namespace std;

const int MAX = 75;
const string FILE_NAME = "/home/fac/sreeder/class/cs1420/lab9input.dat";
const char YES = 'y';

int findString(string list[], string target, int numOfElements);
// returns index of target string
// returns -1 if otherwise

int main()
{
  string words[MAX];
  string target;
  int index = 0;
  int numOfElements = 0;
  string val;
  ifstream inFile;
  bool fileOpened = true;
  char searchAgain = YES;

  cout << endl << endl;
  cout << "Attempting to read in from " << FILE_NAME <<  "......" << endl;

  inFile.open(FILE_NAME);
  if(inFile.fail()){
    cout << FILE_NAME << " could not be read! Quiting.....";
      fileOpened = false;
  }

  while(tolower(searchAgain) == YES && fileOpened) {
    while(inFile >> val) {
      words[numOfElements] = val;
      numOfElements++;
    }
    inFile.close();
    cout << "Enter a word to search: ";
    cin >> target;

    index = findString(words, target, numOfElements);

    if(index < 0) {
      cout << "Word not found!" << endl << endl;
    } else {
      cout << "Word found at index " << index << endl << endl;
    }

    cout << "Do you want to search again? (y/n): ";
    cin >> searchAgain;
    cout << endl << endl;
  }
  return 0;
}

int findString(string list[], string target , int numOfElements)
{
  int index = 0;
  while(index < numOfElements && list[index] != target) {
    index++;
  }
  if(list[index] == target)
    return index;

  return -1;
}
