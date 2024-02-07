#include "String.h"
#include <iostream>
using namespace std;

int main() {
	char array[8] = { 'H','e','l','l','o',',',' ','\0'};
	//char array[7] = { 'W','o','r','l','d','!','\0'};
	char* arrayPtr = array;
	
				//CONSTRUCTORS
	//default constructor
	String str1;  //potter
	//char* str constructor
	String str2(arrayPtr); // hello
	//String& str constructor
	String str3(str1); // potter

				//LENGTH
	//Checking the length of the three constructors
	cout << "The length of str1 is: " << str1.Length() << endl;
	cout << "The length of str1 is: " << str2.Length() << endl;
	cout << "The length of str3 is: " << str3.Length() << endl;

				//CHARACTER AT
	//Look for character at [1] in str2
	cout << "The character at index 1 is: " << str2.CharacterAt(1) << endl;
	//Out of bound checks
	cout << "The character at index -1 (out of bounds): " << str2.CharacterAt(-1) << endl;
	cout << "The character at index 5 (out of bounds): " << str2.CharacterAt(7) << endl;

				//EQUAL TO
	//check that str1 is equal to str3 (true), and check if str1 is equal to str2 (false)
	cout << "Are str1 and str3 equal?: " << str1.EqualTo(str3) << endl;
	cout << "Are str1 and str2 equal?: " << str1.EqualTo(str2) << endl;

			//OPERATOR OVERLOAD ==
	if (str1 == str3) {
		cout << "str1 and str3 are equal!!!" << endl;
	}

			//OPERATOR OVERLOAD !=
	if (str1 != str2) {
		cout << "str1 is not equal to str2 :(((" << endl;
	}

			//OPERATOR OVERLOAD []
	//Look for character at [1] in str2
	cout << "The character at index 1 is: " << str2[1] << endl;
	//Out of bound checks
	cout << "The character at index -1 (out of bounds): " << str2[-1] << endl;
	cout << "The character at index 5 (out of bounds): " << str2[7] << endl;

			//OPERATOR OVERLOAD +
	cout << "str1 + str3: " << str1 + str3 << endl;

			//APPEND
	cout << "Appending str2 before appending: " << str2.CStr() << endl;
	str2.Append(str3);
	cout << "Appending str2 with str3: " << str2.CStr() << endl;

			//PREPEND
	cout << "Appending str2 before prepending: " << str2.CStr() << endl;
	str2.Prepend(str3);
	cout << "Prepending str3 to str2: " << str2.CStr() << endl;

	return 0;
}