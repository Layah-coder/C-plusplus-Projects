/* 
* 
This program uses a structure to display movie info.
Leah oswald
10/22/2020

*/
//Needed for input and output.
#include <iostream>
//Needed for strings.
#include <string>
using namespace std;

//Structure named MovieData.
struct MovieData
{
	string title, director;
	int releaseYear;
	int runTime;
};

//Function prototype.
void displayMovieData(const MovieData &movie);

int main()
{
	//Define variables with initialization lists.
	MovieData movieOne = { "The Fifth Element" , "Luc Besson", 1997, 126 };
	MovieData movieTwo = { "Sonic The Hedgehog",  "Jeff Fowler", 2020, 98 };


	//Call functions that pass MovieData variable as argument.
	displayMovieData(movieOne);
	displayMovieData(movieTwo);

}
//Functions that accepts MovieData type reference as parameter and returns nothing. 
void displayMovieData(const MovieData &movie)
{
	//Formatted to display movie information.
	cout << "Title: " << movie.title << "\nDirector: " << movie.director << "\nYear Released: "
		<< movie.releaseYear << "\nRunning Time: " << movie.runTime << " minutes\n" << endl;
}
