#ifndef VALIDATION_H
#define VALIDATION_H
#include <iostream>
#include <string>
using namespace std;

/*
Elana Parnis
31/1/2024
*/

//alt way to cin.ignore(cin.rdbuf()->in_avail())
int intInput() {
	//gets the user input and determins it is a valid int
	//accepts both positive and neg numbers
	bool failed = false;
	int num = 0;
	do { //ask for new input if input is invalid
		failed = false;
		cin >> num;
		if (cin.fail()) { //if the input type is incorrect
			cin.clear(); //corrects the stream
			cin.ignore(cin.rdbuf()->in_avail()); // skips the rest of the data
			cout << "Please provide a vaild number: " << endl;
			failed = true;
		}
	} while (failed == true);
	//clear the remaining data in cin to avoid conflicts in the future
	cin.clear(); //corrects the stream
	cin.ignore(cin.rdbuf()->in_avail()); // skips the rest of the data
	return num;
}

float floatInput() {
	//gets the user input and determins it is a valid int
	//accepts both positive and neg numbers
	bool failed = false;
	float num = 0;
	do { //ask for new input if input is invalid
		failed = false;
		cin >> num;
		if (cin.fail()) { //if the input type is incorrect
			cin.clear(); //corrects the stream
			cin.ignore(cin.rdbuf()->in_avail()); // skips the rest of the data entered into the cin
			cout << "Please provide a vaild number: " << endl;
			failed = true;
		}
	} while (failed == true);
	//clear the remaining data in cin to avoid conflicts in the future
	cin.clear(); //corrects the stream
	cin.ignore(cin.rdbuf()->in_avail()); // skips the rest of the data
	return num;
}

#endif

