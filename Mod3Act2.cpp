/* Leah Oswald 10/29/2020
Program that tests for a clean open and closes file.
Uses functions and a structure to open and calculate corporate sales data.
Displays calculations*/

#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
//Constant used to size arrays.
const int SIZE = 4;


struct SalesData {
	//Array to hold characters of division name.
	char divisionName[6];
	//Array to hold quarter int.
	int quarter[SIZE]{};
	//Array to hold quarterly sales double.
	double quarterlySales[SIZE]{};
};


//Prototypes.
double totalDivisionSales(SalesData);
double avgQuarterlyPerDivision(double);
void totalQuartelySalesCalculations(SalesData[], double[]);
void minMax(double[], double&, double&);

int main()
{
	//Array to hold file input of type SalesData.
	SalesData records[SIZE + 1];
	//Variable of type SalesData.
	SalesData record;
	//File stream object.
	ifstream inFile;
	
	//Array of sales for each division.	
	double divisions[SIZE]{0, 0, 0, 0};
	//Array of sales for each quarter.
	double quarterTotal[SIZE] = {0, 0, 0, 0};
	//Total yearly corporate sales.
	double allTotal = 0;
	//Highest and lowest quarters for corporation.
	double max = 0, min = 0;
	//Used as a counter.
	int count = 0;
	
	//Open file for input in binary mode.
	inFile.open("data.dat", ios::in | ios::binary);

	//Test for errors.
	if (!inFile) {
		//Display error message and abort program.
		cout << "Cannot read file, error." << endl;
		return 0;
	}

	//Loops till end of file.
	while (!inFile.eof()) {

		//Reads structure from file and assigns to variable record.
		inFile.read(reinterpret_cast<char*>(&record), sizeof(record));
		//Store record variable into records array and increments to next index. 
		records[count++] = record;

	}

	//Loops through divisions array.
	for (int i = 0; i < SIZE; i++) {
		//Calls totalDivisionSales function, passes element from records array as argument, 
		//and assigns to divisions array. 
		divisions[i] = totalDivisionSales(records[i]);
		//Accumulates total corporate sales.
		allTotal += divisions[i];
	}

	//Call totalQuarterlySalesCalculations function with records array and quarterTotal array as arguments.
	totalQuartelySalesCalculations(records, quarterTotal);
	//Call minMax function with quarterTotal array and double variables as arguments.
	minMax(quarterTotal, min, max);

	//Format output.
	cout << fixed << setprecision(2);
	cout << "\tCorporate Sales Data" << endl;

	cout << "_______________________________________________\n" << endl;
	//Loop through quarter sales.
	for (int i = 0; i < 4; i++) {
		//Display quarter sales.
		cout << "Quarter " << i + 1 << " Sales: $" << quarterTotal[i] << endl;
		cout << endl;
	}

	cout << "_______________________________________________\n" << endl;
	//Loop through yearly division sales.
	for (int i = 0; i < SIZE; i++) {
		//Display yearly division sales.
		cout << records[i].divisionName << " Yearly Division Sales: $" << divisions[i] << endl;
		cout << endl;
	}

	cout << "_______________________________________________\n" << endl;
	//Display yearly corporate sales.
	cout << "Yearly Corporate Sales: $" << allTotal << "\n" << endl;

	cout << "_______________________________________________\n" << endl;
	//Loop through quarter sales.
	for (int i = 0; i < SIZE; i++) {
		//Display average quarterly sales.
		cout << records[i].divisionName << " Average Quaterly Sales: $" <<
			avgQuarterlyPerDivision(divisions[i]) << endl;
		cout << endl;
	}

	cout << "_______________________________________________\n" << endl;
	//Display lowest and highest quarter sales.
	cout << "Lowest quarter: $" << min << endl;
	cout << "\nHighest quarter: $" << max << endl;

	//Close file.
	inFile.close();
	return 0;
}


//Function that accepts type SalesData variable as a parameter.
double totalDivisionSales(SalesData division) {
	double total = 0;
	//Loops through division quarters.
	for (int i = 0; i < 4; i++) {
		//Accumulates quarterly sales.
		total += division.quarterlySales[i];
	}
	//Return total sales.
	return total;
}

//Function that accpts a double as a parameter.
double avgQuarterlyPerDivision(double quarterlyTotal) {
	//Calculates and returns average.
	return quarterlyTotal / 4;
}

//Function that accepts SalesData array and double array as parameters.
void totalQuartelySalesCalculations(SalesData arr[], double arr2[]) {
	//Loops through SalesData records array.
	for (int i = 0; i < 4; i++) {
		//Loops through quarterTotals array.
		for (int j = 0; j < 4; j++) {
			//If quarter 1.
			if (j == 0) {
				//Accumulates quarter 1 sales.
				arr2[0] += arr[i].quarterlySales[j];
			}
			//If quarter 2.
			else if (j == 1) {
				//Accumulates quarter 2 sales.
				arr2[1] += arr[i].quarterlySales[j];
			}
			//If quarter 3.
			else if (j == 2) {
				//Accumulates quarter 3 sales.
				arr2[2] += arr[i].quarterlySales[j];
			}
			//If quarter 4.
			else {
				//Accumulates quarter 4 sales.
				arr2[3] += arr[i].quarterlySales[j];
			}
		}
	}
}

//Function that accepts quarterlyTotals array and reference to min & max variables.
void minMax(double arr[], double& min, double& max) {
	//Assign first quarterlyTotals array element to min & max.
	min = max = arr[0];
	//Loop through quarterlyTotals array.
	for (int i = 0; i < SIZE; i++) {
		//Assigns current element to min if less than min.
		if (min > arr[i]) {
			min = arr[i];
		}
		//Assign current element to max if less than max.
		if (max < arr[i]) {
			max = arr[i];
		}
	}
}










