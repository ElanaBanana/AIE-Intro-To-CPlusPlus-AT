#include "String.h"
#include <iostream>
using namespace std;


String::String() {
	theStringArray = new char[7] {'p', 'o', 't', 't', 'e', 'r', '\0'};
	//default constructor
}

String::String(const char* str) { //ASSUMING ARRAY PROVIDED HAS THE \0 ALREADY
	//takes a pointer to an array of chars
	//for me to put into an array of chars
	theStringArray = new char[strlen(str)+1]; // initialises dynamic array of ints, 1 larger to allow for the null terminator

	for (int i = 0; i < strlen(str); i++) {
		//for each value in the str array, add it to the local array
		theStringArray[i] = str[i];
	}
	//adding the null terminator to the end of the         
	theStringArray[strlen(str)] = '\0';
}

String::String(const String& otherString){ //otherString.CStr(); returns a pointer to a char array
	//takes in a memory addresss to a string
	int lenOfOther = otherString.Length(); // length of the provided string
	theStringArray = new char[lenOfOther + 1]; // initialises dynamic array of ints, 1 larger to allow for the null terminator

	for (int i = 0; i < lenOfOther; i++) {
		//for each value in other string, place in local array
		theStringArray[i] = otherString.CStr()[i]; 
	}
	//adding the null terminator to the end of the array
	theStringArray[lenOfOther] = '\0';
}

String::~String() {
	//default destructor
	delete[] theStringArray;
}

size_t String::Length() const {
	return strlen(theStringArray); //returns the len of the char array as a size_t (int that just great, ehehehe)
}

char String::CharacterAt(int index) {
	//check if the index is not range, return '\0'
	if (index < 0 || index >= Length()) { 
		//less than zero, or greater than or eq too Length of array
		return '\0';
	}
	return theStringArray[index];
}

bool String::EqualTo(const String& other) const{
	//first check if the length of both ararys is equal
	if (Length() == other.Length()) {
		for (int i = 0; i < Length(); i++) {
			//for each element in the arrays, compare values
			if (theStringArray[i] != other.CStr()[i]) {
				//if any element does not match
				return false;
			}
		}
		//if all comparison checks pass
		return true;
	}
	return false; //default value
}

const char* String::CStr() const {
	return theStringArray;
}

bool String::operator ==(const String& other) { //overriding the equality operator
	if (EqualTo(other)) {//if the two strings are equal
		return true;
	}
	return false;
}

bool String::operator !=(const String& other) { //overriding the not equal to operator
	if (EqualTo(other) == false) { //checks if they are not equal
		return true; //returns true if equality check returns false
	}
	return false;//confusing I know
}

char String::operator [](int index) { //overriding the [] operator
	//finds the character at specific index and returns the char, else return null terminator
	return CharacterAt(index);
}


