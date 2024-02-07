#include "String.h"
#include <iostream>
using namespace std;

int main() {
	char array[6] = { 'h','e','l','l','o','\0'};
	char* arrayPtr = array;

	//default constructor
	String str1;
	//char* str constructor
	String str2(arrayPtr);
	//String& str constructor
	String str3(str1);

	//Checking the length of the three constructors
	cout << "The length of str1 is: " << str1.Length() << endl;
	cout << "The length of str1 is: " << str2.Length() << endl;
	cout << "The length of str3 is: " << str3.Length() << endl;

	//Look for character at [1] in str2
	cout << "The character at index 1 is: " << str2.CharacterAt(1) << endl;
	//Out of bound checks
	cout << "The character at index -1 (out of bounds): " << str2.CharacterAt(-1) << endl;
	cout << "The character at index 5 (out of bounds): " << str2.CharacterAt(5) << endl;

	return 0;
}