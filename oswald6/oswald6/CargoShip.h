/*	Leah Oswald
*	11/16/2020
*	Cargo Ship header file for derived class CargoShip.
*/

//Needed to add header file Ship.
#include "Ship.h"
//Check if defined.
#ifndef CARGOSHIP_H
//Define.
#define CARGOSHIP_H

// CargoShip class that is derived from Ship base class.
class CargoShip :public Ship
{
	//Members only available in Cargoship.
private:
	//Max tonnage capacity.
	int capacity = 0;
//Member functions available to all in project.
public:
	//Parameterized constructor.
	CargoShip(string, string, int);

	//Virtual print function, can be overridden.
	virtual void printShip();
};
//End if def.
#endif
