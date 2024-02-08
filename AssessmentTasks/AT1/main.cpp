#include "String.h"
#include <iostream>
using namespace std;

int main() {
	char array[8] = {'H','e','l','l','o',',',' ','\0'};
	//char array2[7] = { 'W','o','r','l','d','!','\0'};
	char array3[5] = {'e','l','l','o','\0'};
	char* arrayPtr = array;
	//char* array2Ptr = array2;
	char* array3Ptr = array3;
	
				//CONSTRUCTORS
	//default constructor
	String str1;  //potter
	//char* str constructor
	String str2(arrayPtr); // hello
	//String& str constructor
	String str3(str1); // potter
	//Find
	String findMe(array3Ptr);

				//LENGTH
	cout << "	---LENGTH OUTPUT---" << endl;
	//Checking the length of the three constructors
	cout << "The length of str1 is: " << str1.Length() << endl;
	cout << "The length of str1 is: " << str2.Length() << endl;
	cout << "The length of str3 is: " << str3.Length() << endl;

				//CHARACTER AT
	cout << "\n	---CHARACTER AT OUTPUT---" << endl;
	//Look for character at [1] in str2
	cout << "The character at index 1 is: " << str2.CharacterAt(1) << endl;
	//Out of bound checks
	cout << "The character at index -1 (out of bounds): " << str2.CharacterAt(-1) << endl;
	cout << "The character at index 5 (out of bounds): " << str2.CharacterAt(7) << endl;

				//EQUAL TO
	cout << "\n	---EQUAL TO OUTPUT---" << endl;
	//check that str1 is equal to str3 (true), and check if str1 is equal to str2 (false)
	cout << "Are str1 and str3 equal?: " << str1.EqualTo(str3) << endl;
	cout << "Are str1 and str2 equal?: " << str1.EqualTo(str2) << endl;

				//APPEND
	cout << "\n	---APPEND OUTPUT---" << endl;
	cout << "Appending str2 before appending: " << str2.CStr() << endl;
	str2.Append(str3);
	cout << "Appending str2 with str3: " << str2.CStr() << endl;

				//PREPEND
	cout << "\n	---PREPEND OUTPUT---" << endl;
	cout << "Appending str2 before prepending: " << str2.CStr() << endl;
	str2.Prepend(str3);
	cout << "Prepending str3 to str2: " << str2.CStr() << endl;

				//TO LOWER
	cout << "\n	---TO LOWER OUTPUT---" << endl;
	str1.ToLower();
	cout << "Lets make str1 lower case!: " << str1.CStr() << endl;

				//TO UPPER
	cout << "\n	---TO UPPER OUTPUT---" << endl;
	str1.ToUpper();
	cout << "Actually... I'm not a fan, lets make str1 UPPERCASE!: " << str1.CStr() << endl;

				//FIND (pleaseworkpleaseworkpleasework)
	cout << "\n	---FIND OUTPUT---" << endl;
	cout << "Can we find 'ello' in our str2?: " << endl;
	cout << "str2 is: " << str2.CStr() << endl;
	cout << "what we want to find: " << findMe.CStr() << endl;
	int foundIndex = str2.Find(findMe);
	if (foundIndex != -1) {
		cout << "We found it! The string starts at index: " << foundIndex << endl;
	}
	else {
		cout << "We didn't find the string..." << endl;
	}

				//FIND (FROM INDEX)
	cout << "\n	---FIND (FROM INDEX) OUTPUT---" << endl;
	cout << "Now can we find 'ello' in our str2? if we start search from index 9? Or 10?: " << endl;
	cout << "str2 is: " << str2.CStr() << endl;
	cout << "what we want to find: " << findMe.CStr() << endl;
	int foundIndexFrom9 = str2.Find(9, findMe);
	int foundIndexFrom10 = str2.Find(10, findMe);
	if (foundIndexFrom9 != -1) {
		cout << "We found it! The string starts at index: " << foundIndex << endl;
	}
	else {
		cout << "We didn't find the string starting from index 9..." << endl;
	}
	if (foundIndexFrom10 != -1) {
		cout << "We found it! The string starts at index: " << foundIndex << endl;
	}
	else {
		cout << "We didn't find the string starting from index 10..." << endl;
	}
				//REPLACE
	cout << "\n	---REPLACE OUTPUT---" << endl;
	cout << "What if we replace 'Potter.' with 'Gandalf!' in str2? " << endl;
	char replacement[] = "Gandalf! ";
	char* replacementPtr = replacement;
	String strongerWizard(replacementPtr);
	cout << "Before replacement, str2 is: " << str2.CStr() << endl;
	str2.Replace(str3, strongerWizard);
	cout << "It looks like this: " << str2.CStr() << endl;
	cout << "Now let's put it back, because Gandalf is not from the Wizarding World!" << endl;
	str2.Replace(strongerWizard, str3);
	cout << "Now it looks like this: " << str2.CStr() << endl;

				//READ FROM CONSOLE
	cout << "\n	---READ FROM CONSOLE OUTPUT---" << endl;
	cout << "Let's set str2 to a new value!" << endl;
	str2.ReadFromConsole();
	cout << "Wow! What an input, very impressive, let's take a look: ";
	cout << str2.CStr() << endl;

				//WRITE TO CONSOLE
	cout << "\n	---WRITE TO CONSOLE OUTPUT---" << endl;
	cout << "Now what is in str2?: ";
	str2.WriteToConsole();

				//OPERATOR OVERLOAD ==
	cout << "\n	---OPERATOR OVERLOAD == OUTPUT---" << endl;
	cout << "Are st1 and str3 equal?" << endl;
	cout << "Str1: " << str1.CStr() << endl;
	cout << "Srt3: " << str3.CStr() << endl;
	if (str1 == str3) {
		cout << "str1 and str3 are equal!!!" << endl;
	}

				//OPERATOR OVERLOAD !=
	cout << "\n	---OPERATOR OVERLOAD != OUTPUT---" << endl;
	cout << "Are st1 and str2 equal?" << endl;
	if (str1 != str2) {
		cout << "str1 is not equal to str2 :(((" << endl;
	}

				//OPERATOR OVERLOAD []
	cout << "\n	---OPERATOR OVERLOAD [] OUTPUT---" << endl;
	//Look for character at [1] in str2
	cout << "The character at index 1 of str1 is: " << str1[1] << endl;
	//Out of bound checks
	cout << "The character at index -1 of str1 (out of bounds): " << str1[-1] << endl;
	cout << "The character at index 7 of str1 (out of bounds): " << str1[7] << endl;

				//OPERATOR OVERLOAD +
	cout << "\n	---OPERATOR OVERLOAD + OUTPUT---" << endl;
	String newString(str1 + str3);
	cout << "str1 + str3 is: " << newString.CStr() << endl;

				//OPERATOR OVERLOAD +=
	cout << "\n	---OPERATOR OVERLOAD += OUTPUT---" << endl;
	newString += str1;
	cout << "newString + str1 is: " << newString.CStr() << endl;

	system("pause");
	return 0;
}