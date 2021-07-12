/* Program that accepts user input and displays number of words.
* 10/18/2020
*/
//Needed for cin cout.
#include <iostream>
//Needed for organizing names.
using namespace std;

//Function prototype.
int wordCount(char *);

int main() 
{
	//Constant for array length.
	const int SIZE = 46;
	//Array of character input.
	char input[SIZE];
	//Prompt user.
	cout << "Enter a string up to 45 characters: ";
	//Get line of input including whitespace characters and store it in input array.
	//SIZE is the maxium lenght of string including null terminator.
	cin.getline(input, SIZE);
	//Call function with pointer to input c-string array as argument and assign to variable words.
	int words = wordCount(input);
	//Display word count to user.
	cout << "The string you entered contains " << words << " words.";
	
}
//Function that accepts a pointer as a parameter and returns an int.
int wordCount(char* pointer)
{
	int words = 0;
	//When not pointing to null terminator.
	while (*pointer != '\0')
	{	
		//When pointer reaches a space.
		if (*pointer == ' ')
		{
			//Increment words.
			words++;
		}
		//Increment pointer to next position.
		*pointer++;
	}
	//Add last word to words.
	words++;
	//Return int words.
	return words;
	
	
}