// Author: Aaron Rodriguez
// Assignment Number: Lab 6
// File Name: L6_Rodriguez.cpp
// Course/Section: COSC 1337 Section 006
// Date: 4/09/2022
// Instructor: Dr. B. Hohlt
//
/*
    Program Description:
    In this program this is a bubble function that is built from scratch using the book and implement it
    in a way that it works with our program.
    There are two versions to the both sort function the use of second one called "a more efficient bubble sort " is written with cleaner code.
    A swap function is built from scratch in order to rearrange the integers throughout the array and display the output as specified.
    The user will be prompt to enter a radius between 1.0 and 6.0 a binary search function is built to find the circle in the sorted array.
    if the radius is found a display with show what position it is at. If it is not found and output of "Cannot find the circle with radius"


*/
// This program demonstrates how overloaded constructors
// are used in the initialization list of an array
// of Circle objects at the time the array is created.
#include <iostream>
#include <iomanip>
#include <cmath>		// pow function
using namespace std;

// Circle class declaration
class Circle
{
private:
	double radius;                    // Circle radius
	int centerX, centerY;             // Center coordinates

public:
	// member function prototypes
	Circle();						// Default constructor
	Circle(double r);				// Constructor 2
	Circle(double r, int x, int y);	// Constructor 3

	void setRadius(double r);
	double getRadius() const;
	int getXcoord() const;
	int getYcoord() const;
	double findArea() const;
};

// function prototypes before the main
void bubbleSort(Circle[], int);
void swap(Circle &,Circle&);
int binary_search(const Circle[], int, double);
// main
int main()
{
	// Define an array of 7 Circle objects. Use an initialization list
	// to call the 1-argument constructor for the first 3 objects.
	// The default constructor will be called for the final object.
	const int NUM_CIRCLES = 7;
	Circle circle[NUM_CIRCLES] = {2.5, 4.0, 1.0, 3.0, 6.0, 5.5, 2.0}; //array of 7 circles
	double value;
	// Display the area of each object

	cout << fixed << showpoint << setprecision(2);
	cout << "\nHere are the areas of the " << NUM_CIRCLES
	     << " circles.\n";
	bubbleSort(circle,NUM_CIRCLES);  // Sorted circles in array in ascending order

	for (int index = 0; index < NUM_CIRCLES; index++)
	{	cout << "circle " << (index+1) << setw(8)
		     << circle[index].findArea() << endl;
	}
	cout << "Enter the radius between 1.0 and 6.0  ";   //Prompting the user to enter a radius between 1.0 and 6.0
	cin >> value;
	int position = binary_search(circle,NUM_CIRCLES,value);
	if (position == -1){

		cout << "Cannot find the circle with radius"<< endl; // If radius was not found output
	}
	else
	{
		cout << "The circle you are looking for is at position " << position << endl; // Radius was found output
	}

	return 0;
}

// class member function definitions
Circle::Circle()				// Default constructor
{  radius = 1.0;				// accepts no arguments
   centerX = centerY = 0;
}

Circle::Circle(double r)		// Constructor 2
{  radius = r;					// accepts 1 argument
   centerX = centerY = 0;
}

Circle::Circle(double r, int x, int y)	// Constructor 3
{  radius = r;					// accepts 3 arguments
   centerX = x;
   centerY = y;
}

void Circle::setRadius(double r)
{  radius = r;
}

double Circle::getRadius() const
{  return radius;
}

int Circle::getXcoord() const
{  return centerX;
}

int Circle::getYcoord() const
{  return centerY;
}

double Circle::findArea() const
{  return 3.14 * pow(radius, 2);
}

// A more efficient Bubble Sort
void bubbleSort(Circle circle[], int size)
{
	bool madeAswap = true; //Allows loop to begin
	for (int maxElement = size -1; maxElement > 0 && madeAswap; maxElement--)
	{
		madeAswap = false;

		for (int index =0; index < maxElement; index++)
		{
		  if (circle[index].getRadius() > circle[index + 1].getRadius())
		  {
			swap(circle[index], circle[index + 1]);
			madeAswap = true;
			}
		}

	}
}
// Swap Funciton
void swap(Circle &a, Circle &b) // Swap initiated with & which represents address
{
	Circle temp = a;
	a = b;
	b = temp;
}
// Binary Search function to find the circle object in the sorted araay
int binary_search(const Circle circle[], int size, double value){
	int first = 0,
	last = size -1,
	middle,
	position = -1;
	bool found = false;
	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (circle[middle].getRadius() == value)
		{
			found = true;
			position = middle;
		}
		else if (circle[middle].getRadius() > value)
			last = middle - 1;
		else first = middle + 1;
	}
	return position;  // Return the position
}
/*
Output :

Here are the areas of the 7 circles.
circle 1    3.14
circle 2   12.56
circle 3   19.62
circle 4   28.26
circle 5   50.24
circle 6   94.98
circle 7  113.04
Enter the radius between 1.0 and 6.0  2.0
The circle you are looking for is at position 1

*/
