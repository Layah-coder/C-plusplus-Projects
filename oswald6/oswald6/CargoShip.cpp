/*	Leah Oswald
*	11/16/2020
*	Defines derived class CargoShip functions.
*/
//Needed to add header file for CargoShip.
#include"CargoShip.h"

//Parameterized constructor that calls Ship constructor.
CargoShip::CargoShip(string n, string y, int c) :Ship(n, y) {
	//Assigns incoming argument to local variable.
	capacity = c;
}

//Calls getName function from base class ship and displays Cargo Ship information.
void CargoShip::printShip() {
	cout << "_____________________\n\n\     Cargo Ship\n_____________________\n\nName: " << getName() << "\nCargo Capacity: " << capacity << " tonnage.\n";
}