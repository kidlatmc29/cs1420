// Isabel Ovalles
// p1.cpp
// 1-10-2020

// Purpose: This program plays a word game with the user. 
//
// Input: The user will input a name, city, college, age, profession, 
// animal type and pet name.
//
// Processing: None. 
//
// Output: The input items are imbedded into a pre-determined paragraph.
//
// Examples: User input: Isabel, 19  Output: "Isabel is 18 years old."

#include <iostream>

using namespace std;

int main()
{
  string name; // Stores the user's input
  string cityName; 
  string collegeName; 
  int age; 
  string profession; 
  string animal; 
  string petName; 

  cout << endl << endl; 

  cout << "Hello, let's play a game! " << endl << endl; 

  cout << "Please enter your name: ";
  getline(cin, name);

  cout << "Please enter a city name: ";
  getline(cin, cityName);

  cout << "Please enter a college name: ";
  getline(cin, collegeName);

  cout << "Please enter an age: ";
  cin >> age;
  cin.ignore();

  cout << "Please enter a profession: ";
  getline(cin, profession);

  cout << "Please enter a type of animal: ";
  getline(cin, animal);

  cout << "Please enter another name: ";
  getline(cin, petName);

  cout << endl; 

  cout << "Press enter to see your results....";
  cin.get();

  cout << endl << "There once was a person named " << name 
    << " who lived in " << cityName << ". "; 
  cout << "At the age of " << age << ", " << endl
    << name << " went to college at " << collegeName << ". "; 
  cout << name << " graduated and went to work as a(n) " << endl
    << profession << ". "; 
  cout << "Then, " << name << " adopted a(n) " << animal 
    << " named " << petName << ". " 
	<< "They both lived " << endl << "happily ever after!";
  cout << endl << endl; 

  cout << "Goodbye, thank you for playing!"; 

  cout << endl << endl << endl;
  return 0;
}