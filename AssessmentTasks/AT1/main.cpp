#include "String.h"
#include "InputValidation.h"
#include <iostream>
#include <fstream> //files!!
#include <ctime> // for time
#include <cmath> // for ceil !! (to round)
#include <iomanip> // for set precision
using namespace std;

/*
Elana Parnis
07/02/2024
*/

int TakeInput();
void testFunctions(int* passArray);

int main() {
	cout << "Hi!" << endl;
	cout << "Welcome to Elana's AT1 and AT2!" << endl;
	cout << "Are you here to test for AT1 (1), AT2 (2) or AT3 (3)?: " << endl;
	int input = TakeInput();
	if (input == 1) 
	{
		String julianInput; //creates default string for Julian's input
		String correctInput("Hello, World!");
		cout << "Hello Julian!!! Hope you are doing well :)" << endl;
		cout << "\n=================================" << endl;
		cout << "Thank you for choosing Parnis Co." << endl;
		cout << "=================================\n" << endl;
		cout << "Too ensure the safety of our employees, we will require you to input 'Hello, World!': ";
		bool goodJulian = false;
		while (goodJulian == false) {
			julianInput.ReadFromConsole();
			goodJulian = julianInput.EqualTo(correctInput);
			if (goodJulian == true) {
				break;
			}
			cout << "Hey! Wait a minute, that's not right :(" << endl;
			cout << "Julian, don't be a fool-again.." << endl;
			cout << "This task is not herculean.." << endl;
			cout << "\nWe can't let you enter unless you can pass this... Try again ?: " << endl;
		}
		cout << "\nGood Job!! I'm so proud of you!" << endl;
		cout << "Welcome to my humble abode...\n" << endl;
		cout << julianInput.CStr() << endl;
	}
	else if (input == 2)
	{
		char array[8] = { 'H','e','l','l','o',',',' ','\0' };
		//char array2[7] = { 'W','o','r','l','d','!','\0'};
		char array3[5] = { 'e','l','l','o','\0' };
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
		cout << "The character at index 7 (out of bounds): " << str2.CharacterAt(7) << endl;

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
		if (foundIndex != -1)
		{
			cout << "We found it! The string starts at index: " << foundIndex << endl;
		}
		else
		{
			cout << "We didn't find the string..." << endl;
		}

					//FIND (FROM INDEX)
		cout << "\n	---FIND (FROM INDEX) OUTPUT---" << endl;
		cout << "Now can we find 'ello' in our str2? if we start search from index 9? Or 10?: " << endl;
		cout << "str2 is: " << str2.CStr() << endl;
		cout << "what we want to find: " << findMe.CStr() << endl;
		int foundIndexFrom9 = str2.Find(9, findMe);
		int foundIndexFrom10 = str2.Find(10, findMe);
		if (foundIndexFrom9 != -1)
		{
			cout << "We found it! The string starts at index: " << foundIndex << endl;
		}
		else
		{
			cout << "We didn't find the string starting from index 9..." << endl;
		}
		if (foundIndexFrom10 != -1) {
			cout << "We found it! The string starts at index: " << foundIndex << endl;
		}
		else
		{
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
		if (str1 == str3)
		{
			cout << "str1 and str3 are equal!!!" << endl;
		}
		else
		{
			cout << "The are not equal!!!" << endl;
		}

					//OPERATOR OVERLOAD !=
		cout << "\n	---OPERATOR OVERLOAD != OUTPUT---" << endl;
		cout << "Are st1 and str2 equal?" << endl;
		if (str1 != str2)
		{
			cout << "str1 is not equal to str2 :(((" << endl;
		}

					//OPERATOR OVERLOAD > & <
		cout << "\n	---OPERATOR OVERLOAD < OUTPUT---" << endl;
		cout << "Str1: " << str1.CStr() << endl;
		cout << "Srt3: " << str3.CStr() << endl;
		cout << "Does str1 come before str3 alphabetically?" << endl;
		if (str1 < str3) {
			cout << "Yes it does!" << endl;
		}
		else
		{
			cout << "No it doesn't!" << endl;
		}
		cout << "\n	---OPERATOR OVERLOAD > OUTPUT---" << endl;
		cout << "Does str1 come after str3 alphabetically?" << endl;
		if (str1 > str3) {
			cout << "Yes it does!" << endl;
		}
		else
		{
			cout << "No it doesn't!" << endl;
		}

					//OPERATOR OVERLOAD []
		cout << "\n	---OPERATOR OVERLOAD [] OUTPUT---" << endl;
		//Look for character at [1] in str2
		cout << "The character at index 1 of str1 is: " << str1[1] << endl;
		//Out of bound checks
		cout << "The character at index -1 of str1 (out of bounds): " << str1[-1] << endl;
		cout << "The character at index 7 of str1 (out of bounds): " << str1[7] << endl;

					//OPERATOR OVERLOAD +
		cout << "Str1: " << str1.CStr() << endl;
		cout << "Srt3: " << str3.CStr() << endl;
		cout << "\n	---OPERATOR OVERLOAD + OUTPUT---" << endl;
		String newString(str1 + str3);
		cout << "newString = str1 + str3 is: " << newString.CStr() << endl;
		cout << "Str1: " << str1.CStr() << endl;
		cout << "Srt3: " << str3.CStr() << endl;
		cout << "See Julian! They don't change :D" << endl;

					//OPERATOR OVERLOAD +=
		cout << "\n	---OPERATOR OVERLOAD += OUTPUT---" << endl;
		newString += str1;
		cout << "newString + str1 is: " << newString.CStr() << endl;
	}
	else { //AT3
		//run all the tests
		//save outcome of test to an array
		//write to file if the test passed or failed, 1== pass, 0== fail

		const int numOfTests = 21;
		//an array of strings which stores the name of all the functions being tested
		String allTestNames[] = { 
			String("Length"), 
			String("CharacterAt"), 
			String("EqualTo"),
			String("Append"),
			String("Prepend"),
			String("CStr"),
			String("ToLower"),
			String("ToUpper"),
			String("Find"),
			String("FindFromIndex"),
			String("Replace"),
			String("ReadFromConsole"),
			String("WriteToConsole"),
			String("Operator=="),
			String("Operator!="),
			String("Operator="),
			String("Operator<"),
			String("Operator>"),
			String("Operator[]"),
			String("Operator+"),
			String("Operator+=")
		};

		int testPassed[numOfTests] = { 0 };
		//test all functions in String class
		testFunctions(&testPassed[0]);

		//check how many tests passed
		float success = 0; //how many tests passed
		for (int i = 0; i < numOfTests; i++) {
			if (testPassed[i] == 1) {
				success++;
			}
		}
		//tests are ran in order they are listed in the Sting.h file

					//FILE STUFF
		//lets create and open a new file
		const char* fileName = { "testOutput.txt" };
		ofstream outputFile; 
		//open file for appending, create if doesnt exisit
		outputFile.open(fileName, ios::out | ios::app);

		//the date/ time based on the current system
		time_t timeNow = time(0);
		tm buff;
		//gets the time from timeNow and stores it into the buff struct
		if (localtime_s(&buff, &timeNow) != 0) {
			//if failed to get the time
			cout << "Failed to get the local time" << endl;
		}

		//using string to store the Date and Time to make output neater
		//string Date = to_string(buff.tm_mday) + "/" + to_string(buff.tm_mon + 1) + "/" + to_string(buff.tm_year + 1900);
		//string Time = to_string(buff.tm_hour) + ":" + to_string(30 + buff.tm_min) + ":" + to_string(buff.tm_sec);
		//outputFile << "Date: " << Date << " Time: " << Time << " Success Rate: " << endl;

		cout << "Writing ALL tests to file... " << fileName << endl;

		//without using strings
		outputFile << "Date: " << buff.tm_mday << "/" << buff.tm_mon + 1 << "/" << buff.tm_year + 1900;
		outputFile << " Time: " << buff.tm_hour << ":" << 30 + buff.tm_min << ":" << buff.tm_sec;
		outputFile << " Success Rate: " << setprecision(3) << (success/numOfTests)*100.00 << "%" << endl;

		//write out the success of all tests
		for (int i = 0; i < numOfTests; i++) {
			outputFile << "Test " << i + 1 << " " << allTestNames[i].CStr() << " ";
			if (testPassed[i] == 1) 
			{ //if the test passed
				outputFile << "Successful" << endl;
			}
			else
			{
				outputFile << "Failed" << endl;
			}
		}

		//close the file once complete
		outputFile.close(); 
	}

	system("pause");
	return 0;
}

int TakeInput() { //function to make sure the input is only a 1 or 2 (intInput, only checks for valid int input)
	bool correctInput = false;
	int inputNum = 0;
	while (correctInput == false) 
	{
		inputNum = intInput();
		if (inputNum == 1 || inputNum == 2 || inputNum == 3)
		{
			correctInput = true;
			return inputNum;
		}
		cout << "It needs to be a 1 or 2 !" << endl;
	}
	return inputNum;
}

void testFunctions(int* passArray) {
	//test all function
	String test1("King Kong"); //len 9
	String test2("Awesome Sauce! "); //len 14
	String test3("Julien"); // len 6
				//Length - test 0
	//len of test1 = 9
	int lenOfTest1 = 9;
	if (lenOfTest1 == test1.Length()) {
		passArray[0] = 1;
	}
				//characterAt - test 1
	//Character at index 13 of test2 = !
	char charAt13 = '!';
	if (charAt13 == test2.CharacterAt(13)) {
		passArray[1] = 1;
	}
				//equalTo - test 2
	//test2 contains 'Awesome Sauce! '
	bool test2Check = test2.EqualTo("Awesome Sauce! ");
	if (test2Check == true) {
		passArray[2] = 1;
	}
				//append - test 3
	//Adding Julien to Awesome Sauce! 
	test2.Append(test3);
	//cout << test2.CStr() << endl;
	if (strcmp(test2.CStr(), "Awesome Sauce! Julien") == 0) {
		passArray[3] = 1;
	}
				//prepend - test 4
	test2.Prepend(" ");
	test2.Prepend(test3);
	if (strcmp(test2.CStr(), "Julien Awesome Sauce! Julien") == 0) {
		passArray[4] = 1;
	}
				//CStr - test 5
	//should return 'King Kong'
	if (strcmp(test1.CStr(), "King Kong") == 0) {
		passArray[5] = 1;
	}
				//ToLower - test 6	
	//test1 should be 'king kong'
	test1.ToLower();
	if (strcmp(test1.CStr(), "king kong") == 0) {
		passArray[6] = 1;
	}
				//ToUpper - test 7
	//test1 should be 'KING KONG'
	test1.ToUpper();
	if (strcmp(test1.CStr(), "KING KONG") == 0) {
		passArray[7] = 1;
	}
				//Find - test 8
	//find en in Julien, should be index 4
	int test8Find = test3.Find("en");
	if (test8Find == 4) {
		passArray[8] = 1;
	}
				//FindFromIndex - test 9
	//Find 'K' in 'King Kong', from index 3 onwards, should be index 5
	int test9Find = test1.Find(2, "K");
	//cout << "found 'K' at index: " << test9Find << endl;
	if (test9Find == 5) {
		passArray[9] = 1;
	}
	//Found error in my find function which causes it to not find value if the seach string is len 1
	//fixed, but found that my replace function doesn't work properly
	//fixed, problem was with the loop of elements after value being replaced
	
				//Replace - test 10
	//replace Kong in test1 with Julien from test3
	//cout << "test1 now is: " << test1.CStr() << endl;
	//cout << "test3 now is: " << test3.CStr() << endl;
	test1.Replace("KONG", test3);
	//cout << "new string is: " << test1.CStr() << endl;
	if (strcmp(test1.CStr(), "KING Julien") == 0) {
		passArray[10] = 1;
	}
				//ReadFromConsole - test 11
	//take in user input and check new stored value
	bool correctInput = false;
	String userInput;
	while (correctInput == false)
	{
		cout << "Please enter the Chinese zodiac for 2024: " << endl;
		userInput.ReadFromConsole();
		//if the user enters Dragon
		//convert the input to all lower case to check if input is correct
		userInput.ToLower();
		if (strcmp(userInput.CStr(), "dragon") == 0)
		{
			correctInput = true;
			passArray[11] = 1;
			break;
		}
		cout << "That's not right! The answer is: Dragon\n" << endl;
	}
				//WriteToConsole - test 12
	//not sure how to test this oop
	// Julian help plz
	
				//operator== - test 13
	//compare the user into to expected value of "dragon" using ==
	//expected output of true (they are equal)
	if (userInput == "dragon") {
		passArray[13] = 1;
	 }
				//operator!= - test 14
	//compare the user into to expected value of "dragon" using ==
	//expected output of true (they are not equal)
	if (userInput != test1) {
		passArray[14] = 1;
	}
				//operator= - test 15
	test1 = "King Julien";
	//change test1 from KING Julien to King Julien
	if (strcmp(test1.CStr(), "King Julien") == 0) {
		passArray[15] = 1;
	}
				//operator< - test 16
	//'Julien' comes before 'King Julien'
	if (test3 < test1) {
		passArray[16] = 1;
	}
				//operator> - test 17
	//'dragon' comes after 'King Julien' (due to capital letters coming first)
	if (userInput > test1) {
		passArray[17] = 1;
	}
				//operator[] - test 18	
	//returns the char at index 1, should return u from 'Julien'
	if (test3[1] == 'u') {
		passArray[18] = 1;
	}
				//operator+ - test 19
	test2 = userInput + " ";
	//test2 should be 'dragon '
	if (strcmp(test2.CStr(), "dragon ") == 0) {
		passArray[19] = 1;
	}
				//operator+= - test 20
	test2 += test1;
	//test2 should be 'dragon King Julien!'
	if (strcmp(test2.CStr(), "dragon King Julien") == 0) {
		passArray[20] = 1;
	}
}