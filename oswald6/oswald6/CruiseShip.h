/*	Leah Oswald
*	11/16/2020
*	Cruise Ship header file with derived class CrusieShip.
*/
//Needed to access Ship header file.
#include "Ship.h"
//Check if defined.
#ifndef CRUISESHIP_H
//Define.
#define CRUISESHIP_H

//Define CruiseShip class that is derived from Ship base class.
class CruiseShip :public Ship
{
//Members only available in CruiseShip.
private:
	//Holds maximum number of passengers.
	int passengers = 0;

//Member functions available to all in project.
public:
	//Parameterized constructor.
	CruiseShip(string, string, int);
	//Virtual void print function will display ship information.
	virtual void printShip();
};
//End if define.
#endif