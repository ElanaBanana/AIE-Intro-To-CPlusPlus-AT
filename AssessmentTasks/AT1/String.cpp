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
	return strlen(theStringArray); //returns the len of the char array
}

char String::CharacterAt(int index) {
	//check if the index is not range, return '\0'
	if (index < 0 || index >= Length()) { 
		//less than zero, or greater than or eq too Length of array
		return '\0';
	}
	return theStringArray[index];
}

//bool String::EqualTo(const String other) const{
//	//first check if the length of both ararys is ==
//	if (Length() == strlen(other)) {
//
//	}
//}

const char* String::CStr() const {
	return theStringArray;
}



