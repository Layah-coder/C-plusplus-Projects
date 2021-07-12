//	Leah Oswald
//	11/5/2020

//Specification file for Car class.

//If CAR_H has not beed defined.
#ifndef CAR_H
//Define CAR_H.
#define CAR_H
#include <string>

using namespace std;

//Car class declatarion.

class Car
{
	//Accessable inside Car class.
	private:
		int yearModel;
		string make;
		int speed;
	//Accessible outside Car class.
	public:
		//Car class constructor that uses a default argument for s.
		Car(int y, string m, int s = 0)
		{
			//Assign values to private variables of Car class.
			yearModel = y;
			make = m;
			speed = s;
		}
		//Class constant accessor functions do not change data.
		int getYearModel() const
		{ 
			return yearModel;  
		}
		string getMake() const
		{ 
			return make; 
		}
		int getSpeed() const
		{
			return speed;
		}
		//Functions that modify class variable speed.
		void accelerate()
		{
			speed += 5;
		}
		void brake()
		{
			speed -= 5;
		}
};

//End if.
#endif
