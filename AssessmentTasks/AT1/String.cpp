#include "String.h"
#include <iostream>
using namespace std;

char* joinStrings(const String& strLHS, const String& strRHS); //function to add two strings together

String::String() {
	theStringArray = new char[9] {'P', 'o', 't', 't', 'e', 'r','.',' ', '\0'};
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
	delete[] theStringArray; //AVADAAAAAA KEDAVRAA
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

char* temp; //pointer to temp dynamic array

void String::Append(const String& str) {
	//append the two strings
	char* appended = joinStrings(theStringArray, str);
	//delete old value stored in class pointer
	delete[] theStringArray;
	//finally set the class pointer to the new appended array
	theStringArray = appended;
	//set the temp pointer to nullptr as we are done with it
	temp = nullptr;
}

void String::Prepend(const String& str) {
	//prepend calls the join strings function but opposite to the append function
		//append the two strings
	char* prepended = joinStrings(str, theStringArray);
	//delete old value stored in class pointer
	delete[] theStringArray;
	//finally set the class pointer to the new appended array
	theStringArray = prepended;
	//set the temp pointer to nullptr to avoid leaving a hanging pointer
	temp = nullptr;
}

char* joinStrings(const String& strLHS, const String& strRHS) {//function joins two strings the RHS is added the the end of the LHS
	//create a new char array the length of both arrays combine
	int newLen = strLHS.Length() + strRHS.Length(); // the size of the new array 
	//temp pointer for new string to a new char array of size newLen
	temp = new char[newLen+1]; //+1 extra space for null terminator
	//for each value in lhs add to new array
	for (int i = 0; i < strLHS.Length(); i++) {
		temp[i] = strLHS.CStr()[i];
	}
	//for each value in rhs append to the end of previous string
	for (int i = strLHS.Length(), j = 0; i < newLen; i++, j++) { //start where last for loop ended, until the end of the newLen
		//i = the first index after the end of first append
		//j is used to keep track of the index being accessed from the array
		//keep appending until i < length of second string + the starting index -1, which is for the null terminator
		temp[i] = strRHS.CStr()[j];
	}
	temp[newLen] = '\0'; //add null terminator to the last index of array
	return temp; //returns the pointer to the new string
}

const char* String::CStr() const {
	return theStringArray; //returns a pointer to the char array storing the class string
}

void String::ToLower() {
	//first checks if the ascii character is already lowercase
	for (int i = 0; i < Length(); i++) {
		if (theStringArray[i] >= 97 && theStringArray[i] <= 122) { //is it already lowercase?
			continue;
		}
		if (theStringArray[i] >= 65 && theStringArray[i] <= 90) { //is it uppercase character?
			theStringArray[i] = char(theStringArray[i] + 32); // convert to lowercase version of char by adding 32
		}
	}
	//else skip
}

void String::ToUpper() {
	//first checks if the ascii character is already uppercase
	for (int i = 0; i < Length(); i++) {
		if (theStringArray[i] >= 65 && theStringArray[i] <= 90) { //is it already uppercase?
			continue;
		}
		if (theStringArray[i] >= 97 && theStringArray[i] <= 122) { //is it lowercase character? else dont convet
			theStringArray[i] = char(theStringArray[i] - 32); // convert to lowercase version of char by adding 32
		}
	}
	//else skip
}

int String::Find(const String& findString) {
	return Find(0, findString); //runs the find from index function, but from the first index
}

int String::Find(int startIndex, const String& findString) {
	if (findString.Length() > Length()) { //first check wether the string is longer than the current string
		return -1;
	}
	if (startIndex < 0 || startIndex >= Length()) { //boundry cases for invald starting point
		return -1;
	}

	int searchLength = findString.Length(); //the length of the string that we want to find
	const char* searchArray = findString.CStr(); //the string we want to find
	for (int i = startIndex, j = 0; i < Length(); i++) { //for each value in theStringArray from starting index
		//check if it is still possible for theStringArray to contain the search value
		if (Length() - i >= searchLength) { //if the remaining elements in the StringArray are >= the length of the search string, continue search
			j = 0; //reset back to first element of findString
			if (theStringArray[i] == searchArray[j]) { // if a match is found the start of findString and theStringArray
				for (j = 1; j < searchLength; j++) { //if a match was found, check the proceeding values for match
					//j is the next value in the findString array after a match is found (starting from index 1)
					//i + j is the next value in theStringArray after a match is found
					if (theStringArray[i+j] == searchArray[j]) {
						if (j + 1 >= searchLength) { // if we have reached the end of the searchArray
							return i; //in this case, i triggers the first match and will hold the value of the starting index for match
						}
					}
					else {
						continue; //if not a match, return to search
					}
				}
			}
		}
		else {
			//if the searchArray is larger then the remaining space in theStringArray, it can't be found
			return -1;
		}
	}
	return -1; //if there is no match found
}

void String::Replace(const String& findString, const String& replaceString) {
	int indexOfFound = Find(0, findString); //returns the index of start of string if found, else return -1

	while (indexOfFound != -1) {
		char* oldArray = theStringArray; //stores the original array before replacements
		int newLength = Length() + replaceString.Length() - findString.Length();
		char* newArray = new char[newLength+1]; //creates a new array to store the replacement + original array + 1 for null terminator
		int currentIndex = 0; //this determins the current poisiton of the array that needs to be accessed
		if (indexOfFound != currentIndex) {
			for (currentIndex = 0; currentIndex < indexOfFound; currentIndex++) {
				newArray[currentIndex] = oldArray[currentIndex]; //adds the not replaced values into the new array
			}
		}
		for (int j = 0; j < replaceString.Length(); j++) {
			newArray[currentIndex + j] = replaceString.CStr()[j];
		}
		currentIndex += replaceString.Length();
		for (int i = 0; currentIndex < newLength; i++, currentIndex++) {
			newArray[currentIndex] = oldArray[i + findString.Length()];
		}
		newArray[newLength] = '\0';
		delete[] theStringArray;
		theStringArray = newArray;
		newArray = nullptr;
		indexOfFound = Find(indexOfFound + replaceString.Length(), findString); //look for the next replacement from the end of the replaced string
	}
}

void String::WriteToConsole() {
		cout << theStringArray << endl;
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

void String::operator =(const String& str) {
	//delete the current value in class array
	delete[] theStringArray;
	//initalise new array with length of string to be added
	int len = str.Length();
	theStringArray = new char[len+1]; //+1 for the null terminator
	for (int i = 0; i < len; i++) {
		theStringArray[i] = str.CStr()[i];
	}
	//add the null terminator
	theStringArray[len] = '\0';
}

char String::operator [](int index) { //overriding the [] operator
	//finds the character at specific index and returns the char, else return null terminator
	return CharacterAt(index);
}

String String::operator+(const String& other) {
	String newString(joinStrings(theStringArray, other)); //Julian is so smart omg
	return newString; //returns the new string concatanation
}

void String::operator +=(const String& other){
	theStringArray = joinStrings(theStringArray, other);
	return; 
}


