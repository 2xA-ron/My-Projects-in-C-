// Author:                      Aaron Rodriguez
// Assignment Number:           Lab10
// File Name:                   L10_Rodriguez.cpp
// Course/Section:              COSC 1337 Section 006
// Date:                        5/11/2022
// Instructor:                  Dr. B. Hohlt
//
//  Chapter 11 --  Inheritance
//

#include <iostream>
using namespace std;

// Insect class declaration
class Insect
{
protected:
	int antennae;
	int legs;
	int eyes;

public:
	// default constructor
	Insect();

	// getters
	int getAntennae() const;
	int getLegs() const;
	int getEyes() const;
};

// BumbleBee class declaration
class BumbleBee :public Insect
{
public:
	void sting();  // inherits getter variables from Insect
				   // And protected variable from Insect
};


void BumbleBee::sting()
{
	cout << "sting! " << endl;
}
// GrassHopper class declaration
class GrassHopper :public Insect
{
public:
	void hop();    // inherits getter variables from Insect
				  // And protected variable from Insect
};

void GrassHopper::hop()
{
	cout << "hop! " << endl;
}
int main()
{
	BumbleBee *bumblePtr = new BumbleBee;
	GrassHopper *hopperPtr = new GrassHopper;

	cout << "A bumble bee has " << bumblePtr->getLegs() << " legs and can ";
	bumblePtr->sting();

	cout << endl;

	cout << "A grass hopper has " << hopperPtr->getLegs() << " legs and can ";
	hopperPtr->hop();

	delete bumblePtr;
	bumblePtr = nullptr;
	delete hopperPtr;
	hopperPtr = nullptr;

	return 0;
}

// member function definitions
Insect::Insect()
{
	antennae = 2;
	eyes = 2;
	legs = 6;
}
int Insect::getAntennae() const
{ return antennae; }
int Insect::getLegs() const
{ return legs; }
int Insect::getEyes() const
{ return eyes; }

/*
 Output:

 A bumble bee has 6 legs and can sting!

A grass hopper has 6 legs and can hop!

*/
