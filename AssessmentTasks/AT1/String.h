#ifndef STRING_H
#define STRING_H

//const before the function means it is returning a const value (cant be changed)
//const after the function, means it cannot modify the the objects state

class String {
public:
	String();
	String(const char* str);
	String(const String& otherString);
	~String();
public:
	size_t Length() const; // returns the size of the length using strlen()
	char CharacterAt(int index); // returns the character  at index
//	bool EqualTo(const String other) const; // returns true if the string provided is == the stored string
//	void Append(const String str); //adds the provided string to the end current string
//	void Prepend(const String str); //adds the provided string to the start of the current string
	const char* CStr() const; //huh ???????????????????????????????????????????????????????? get my epic string
//	void ToLower(); // converts all the values in the current string to lowercase
//	void ToUpper(); // converts all the values in the current string to UPPERCASE
//
//	//
//	size_t Find(const String str); //returns the location of the start of the specific string
//	size_t Find(size_t startIndex, const String str); //same as above but starts looking from specified index
//	void Replace(const String _find, const String replace); //replaces all the occurances of specified string in the current string with new string
//	void ReadFromConsole(); // get input from the console and store the result
//	void WriteToConsole(); // write the current string to the console
//public:
//	bool operator==(const String other); //returns true if lhs == rhs ???????????????? bruv what sides
//	bool operator!=(const String other); // returns true if lhs != rhs ?????????????????????
//	void operator=(const String str); //replaces the characters in teh lhs with the characters in rhs
//	char operator[](size_t index); //returns the character located at pos provided
//	//String& operator+(const String _other); //return
//	//void operator+=(const String _other); 
private:
	char* theStringArray; //pointer to the string array
};

#endif
