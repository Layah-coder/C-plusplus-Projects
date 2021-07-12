/* Leah Oswald 10/29/2020
Program that  creates or opens file.
Tests for a clean open and closes file.
Uses a structure and functions to add user input into a file.*/

//To read and write files.
#include <fstream>
//To use cin and cout.
#include <iostream>

using namespace std;
//Constant used to size arrays.
const int SIZE = 4;

struct SalesData {
	//Character array to hold division name characters.
	char divisionName[6];
	//Array to hold quarter int.
	int quarter[SIZE]{};
	//Array to hold sales numbers from user input.
	double quarterlySales[SIZE]{};
};
//Prototypes.
void getData(SalesData &);
void writeFile(fstream &, SalesData);

int main()
{
	//Declare and initalize variables of SalesData type.
	SalesData north = { "North",{1, 2, 3, 4 } };
	SalesData east = { "East",{1, 2, 3, 4 } };
	SalesData south = { "South",{1, 2, 3, 4 } };
	SalesData west = { "West",{1, 2, 3, 4 } };
	//Open a file for binary output.
	fstream outFile("data.dat", ios::out | ios::binary);
	//Test for errors.
	if (outFile.fail()) {
		//Display error message and abort program.
		cout << "Error creating file.";
		return 0;
	}
	//Call getData function for each divison, pass original SalesData variable as argument.
	getData(north);
	getData(east);
	getData(south);
	getData(west);

	//Call writeFile function with outFile and updated SalesData variable arguments.
	writeFile(outFile, north);
	writeFile(outFile, east);
	writeFile(outFile, south);
	writeFile(outFile, west);

	cout << "Sales record saved to file." << endl;
	//Close file.
	outFile.close();
	return 0;
}

//Function that accepts SalesData type reference variable as parameter.
void getData(SalesData &division) {
	//Loop through quarters.
	for (int index = 0; index < SIZE; index++) {
		//Prompt user sales information.
		cout << "Please enter sales for " << division.divisionName << " division, quarter " << (division.quarter[index]) << ": ";
		//Assigns user input to current arry index.
		cin >> division.quarterlySales[index];
		cout << endl;
		//Validates user input to accept values greater than 0.
		while (division.quarterlySales[index] < 0){
			//Prompt user of invalid input.
			cout << "Invalid input, enter positive sales figures.\n" << endl;
			//Prompt user again.
			cout << "Please enter sales for " << division.divisionName << " division, quarter " << (division.quarter[index]) << ": ";
			cin >> division.quarterlySales[index];
			cout << endl;
		}

	}
}


//Function that accepts a reference to fstream variable and a SalesData variable.
void writeFile(fstream &file, SalesData division){
	//Writes SalesData variable to file.
	//reinterpret_cast converts address to char pointer.
	//sizeof determines number of bytes used by structure.
	file.write(reinterpret_cast<char *>(&division), sizeof(division));
}


