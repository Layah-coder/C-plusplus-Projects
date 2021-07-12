/*
*
This program modifies module 2 activity 1 , uses a structure to display movie information with new variables.
Leah Oswald
10/22/2020

*/
//Needed for input and output.
#include <iostream>
//Needed for strings.
#include <string>
//Needed to setprecision.
#include <iomanip>

using namespace std;

//Structure named MovieData.
struct MovieData
{
	string title, director;
	int releaseYear;
	int runTime;
	double costs, revenue;


};

//Function prototype.
void displayMovieData(const MovieData &movie);

int main()
{
	//Define variables with initialization lists.
	MovieData movieOne = { "The Fifth Element" , "Luc Besson", 1997, 126, 90000000.0, 263900000.0};
	MovieData movieTwo = { "Sonic The Hedgehog",  "Jeff Fowler", 2020, 98, 81000000.0, 308400000.0 };


	//Call function that passes MovieData variable as argument.
	displayMovieData(movieOne);
	displayMovieData(movieTwo);

}
//Functions that accepts 2 MovieData types as parameters and returns nothing. 
void displayMovieData(const MovieData &movie)
{
	//Calculate subtract budget costs from first year revenue to get a profit or loss.
	//Assign to double report.
	double report = movie.revenue - movie.costs;
	//Fixed format all decimals to two places.
	cout << setprecision(2) << fixed << endl;
	//Formatted to display movie information.
	cout << "Title: " << movie.title << "\nDirector: " << movie.director << "\nYear Released: "
		<< movie.releaseYear << "\nRunning Time: " << movie.runTime << " minutes\n";

	if (report >= 0)
	{
		//Display if movie profited.
		cout << "First Year Net Profit: $" << report << "\n\n";
	}
	else
	{
		//Display if movie was at a loss.
		cout << "First Year Net Loss: $" << report << "\n\n";
	}
}