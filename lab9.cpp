// Isabel Ovalles
// lab9.cpp

#include <fstream>
#include <iostream>

using namespace std;

const int MAX = 75;
const string FILE = "/home/fac/sreeder/class/cs1420/lab9input.dat";

int findString(string list[], string target, int numOfElements);
// returns index of found string
// returns -1 if otherwise

int main()
{
  string words[MAX];
  string target;
  int index = 0;
  int numOfElements = 0;
  string val;
  ifstream inFile;
  bool ok = true;

  cout << endl << endl;
  cout << "Attempting to read in from " << FILE << "......" endl;

  while(ok){
    inFile.open(FILE);
    if(inFile.fail()) {
      cout << FILE << " could not be read! Quiting.....";
      return index;
   }

   while(inFile >> val) {
     words[numOfElements] = val;
     numOfElements++;
    }

    inFile.close();

    cout << "Enter a single word to search for: ";
    cin >> target;
    index = findString(words, target, numOfElements);

    if(index == -1){
      cout << "Word not found!" << endl << endl;
    } else {
        cout << "Word found at index " << index << endl << endl;
      }
  }

  cout << "Goodbye...." << endl << endl;
  return 0;
}

int findString(string list[], string target , int numOfElements)
{
  int index = 0;
  while(index < numOfElements && list[index] != target){
    index++;
  }
  return index;
}
