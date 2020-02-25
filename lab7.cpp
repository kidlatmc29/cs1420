// Isabel Ovalles
// p4.cpp

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const string FILENAME = "/home/fac/sreeder/class/cs1420/lab7input.dat";
const int MAX_NUMS = 30;
const int INDEX_WIDTH = 6;
const int VALUE_WIDTH = 8;
const char SPACE = ' ';

void printArr(int list[], int numElements);
// prints the array index as well as the value stored at that index

int main()
{
  int negNum[MAX_NUMS];
  int evenNum[MAX_NUMS];
  int oddNum[MAX_NUMS];

  int negNumElements = 0;
  int evenNumElements = 0;
  int oddNumElements = 0;

  ifstream inFile;
  int num;
  inFile.open(FILENAME);

  cout << endl << endl;

  if(inFile.fail()) {
    cout << "Problem with file... exiting the program... Press enter...";
    cin.get();
    cout << endl << endl;
    return 0;
  }

  while (inFile >> num) {
      if(num < 0) {
        negNum[negNumElements] = num;
        negNumElements++;
      } else if(num > 0) {
          if(num % 2 == 0) {
            evenNum[evenNumElements] = num;
            evenNumElements++;
          } else {
            oddNum[oddNumElements] = num;
            oddNumElements++;
        }
      }
  }

  inFile.close();

  cout << "Contents of negNum" << endl;
  printArr(negNum, negNumElements);
  cout << endl;
  cout << "Contents of evenNum" << endl;
  printArr(evenNum, evenNumElements);
  cout << endl;
  cout << "Contents of oddNum" << endl;
  printArr(oddNum, oddNumElements);

  cout << endl << endl;
  return 0;
}

void printArr(int list[], int numElements)
{
  cout << setw(INDEX_WIDTH) << "Index" << SPACE;
  cout << setw(VALUE_WIDTH)<< "Value" << endl;

  for(int i = 0; i < numElements; i++) {
    cout << setw(INDEX_WIDTH) << i;
    cout << setw(VALUE_WIDTH) << list[i] << endl;
  }
}
