/* Program that checks if users password meets requirements.
10/18/2020
*/
//For cout and cin.
#include <iostream>
//For character functions.
#include <cctype>
//Needed for using strlen function.
#include <cstring>
//Needed to access namespace names.
using namespace std;

//Prototype.
bool testPassword(char[]);

int main() 
{
	//Constant for array length.
	const int SIZE = 21;
	//Create array to hold 20 characters to accept user input.
	char passwordArray[SIZE];
	//Prompt user to enter a password.
	cout << "Enter a password with 6 to 20 characters: ";
	//Assign input to passwordArray.
	cin.getline(passwordArray, SIZE);
	//Get size of passwordArray.
	int size = strlen(passwordArray);
	//Check if the user entered enough characters.
	while (size < 6)
	{
		//Prompt user that the password was too short.
		cout << "Password must be at least 6 characters long.\n";
		break;
	}
	//Call function with passwordArray as argument.
	if (testPassword(passwordArray))
	{
		//Display if function returns true.
		cout << "Password accepted." << endl;
	
	}



}
//Boolean function that accepts a char array as parameter.
bool testPassword(char array[])
{
	//Local bool variables.
	bool upper = false, lower = false, digit = false, punct = false;
	//Increment through array.
	for (int index = 0; index < array[index]; index++)
	{
		//Assign true to boolean values when met.
		if (isupper(array[index]))
			upper = true;
		if (islower(array[index]))
			lower = true;
		if (isdigit(array[index]))
			digit = true;
		if (ispunct(array[index]))
			punct = true;
	}
	//Return true if all conditions are met.
	while ((upper && lower && digit && punct))
	{
		return true;
	}
	//Display if user is missing a digit.
	if(!digit)
	{
		cout << "Must have a digit" << endl;;
	}
	//Display if user if missing an upper case character.
	if (!upper)
	{
		cout << "Must have an upper case character" << endl;
	}
	//Display if user is missing a lower case character.
	if (!lower)
	{
		cout << "Must have a lower case character" << endl;
	}
	//Display if user is missing a punctuation.
	if (!punct)
	{
		cout << "Must have a punctuation" << endl;
	}
	//Return false if conditions are not met
	return false;

}