// Isabel Ovalles
// lab3.cpp

#include<iostream>

using namespace std;

const char YES = 'y';

int main()
{
	int firstInt; 
	int secondInt;
	int secondMultiple;
	char userResponse;

	userResponse = 'y';

	cout << endl << endl;

	while (userResponse == YES) { 
		cout << "Enter two integers: ";
		cin >> firstInt >> secondInt;

		if ((secondInt % firstInt) == 0) {
			secondMultiple = secondInt / firstInt;
			cout << "Yes, the other factor is " << secondMultiple << endl;
		}
		else {
			cout << "No, not a multiple." << endl;
		}

	cout << "Do you want to enter new integers? (y/n): "; 
		cin >> userResponse;
		cin.ignore();
		cout << endl; 
	}
	cout << endl << endl;
	return 0; 
}