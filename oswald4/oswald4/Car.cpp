/*		Leah Oswald
		11/5/2020
Program that accepts a car make/year, and uses class functions to accelerate and brake.
*/
# include <iostream>
//Include everything in header file.
#include "Car.h"

int main()
{
	//Local variables.
	int year;
	string make;
	//Prompt user to enter car data.
	cout << "Enter the car's year: \n" << endl;
	//Assign user input to local variable.
	cin >> year;
	cin.ignore(4, '\n');
	cout << "\nEnter the car's make: \n" << endl;
	getline(cin, make);
	cout << endl;
	//Create car object of type Car and pass local variables as arguments.
	Car car(year, make);
	//Loop five times.
	for (int i = 0; i < 5; i++)
	{
		//Call accelerate function from car class.
		car.accelerate();
		//Display car make/year and current speed.
		cout << "The " << car.getYearModel() << " " << car.getMake() << " is accelerating, current speed: " << car.getSpeed() << "\n\n";
	}
	cout << endl;

	//Loop five times.
	for (int i = 0; i < 5; i++)
	{
		//Call brake function from car class.
		car.brake();
		//Display car make/year and current speed.
		cout << "The " << car.getYearModel() << " " << car.getMake() << " is braking, current speed: " << car.getSpeed() << "\n\n";
	}

	return 0;
	
}