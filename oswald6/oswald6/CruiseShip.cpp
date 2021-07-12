/*	Leah Oswald
*	11/16/2020
*	Defines derived class CruiseShip functions.
*/
//Adds herader file for CruiseShip.
#include "CruiseShip.h"

//Parameterized constructor that calls base class Ship constructor.
CruiseShip::CruiseShip(string n, string y, int p) : Ship(n, y) {
	//Assigns incoming argument to local variable.
	passengers = p;
}
//printShip will override Ship class version of printShip.
void CruiseShip::printShip()
{
	//Calls getName function from base class ship and displays Crusie Ship information.
	cout << "_____________________\n\n     Cruise Ship\n_____________________\n\nName: " << getName() << "\nOccupancy: " << passengers << endl;
}