/* Leah Oswald
12-1-2020
Header file.
*/

#include "PhysicalActivity.h"

//Check if defined.
#ifndef AEROBICACTIVITY_H
//Define.
#define AEROBICACTIVITY_H

//AerobicActivity class derived from base class PhysicalActivity.
class AerobicActivity : public PhysicalActivity
{
private:

	//Holds minutes of aerobic activity.
	int minutes = 0;

public:

	//Exception class.
	class NegativeMinutes {};

	//Constructors.
	AerobicActivity();
	AerobicActivity(int);

	//Member functions.
	void setMinutes(int);
	const int getMinutes();

};
#endif 
