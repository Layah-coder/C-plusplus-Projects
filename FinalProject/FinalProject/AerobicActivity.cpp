/* Leah Oswald
12-1-2020
Class definitions.*/

#include "AerobicActivity.h"

//Parameterized constructor.
AerobicActivity::AerobicActivity(int inMinutes) : PhysicalActivity()
{
	minutes = inMinutes;
}

//Default constructor.
AerobicActivity::AerobicActivity()
{

}

//Mutator.
void AerobicActivity::setMinutes(int inMinutes)
{
	//Check for negative input.
	if (inMinutes >= 0)
		minutes = inMinutes;
	else
		//Throw exception if negative input.
		throw NegativeMinutes();
}

//Accessor.
const int AerobicActivity::getMinutes()
{
	return minutes;
}



