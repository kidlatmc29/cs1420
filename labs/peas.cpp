// Isabel Ovalles
// peas.cpp
// Purpose: this is a sample programthat will print the
// number of pease in a given number of peas
// Input: number of pods, number of peas
// Process: simple multiplecation
// Output: result of multiplying provided numbers
// Example: number of pods: 2, number of pease: 6, result: 12

#include <iostream>
using namespace std;

int main()
{
	int peas = 0, pods = 0, totalPeas = 0;

	//explanation
	cout << endl << endl << endl;
	cout << "This will calculate the total number of peas in the pods.";
	cout << endl << endl;

	//input

	cout << "How many pods? ";
	cin >> pods;
	cout << "How many peas in each pod? ";
	cin >> peas;

	//calculation 
	totalPeas = pods * peas;

	//output 
	cout << endl << endl;
	cout << "If you have " << pods << " pods each contains " << endl;
	cout << peas << " peas then you have a total of " << totalPeas
		<< " peas." << endl;
	cout << endl << endl << endl;

	return 0;
}