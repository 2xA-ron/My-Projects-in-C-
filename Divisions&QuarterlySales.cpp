// Corporate Sales
/*  Program Description:
	This program dimestracts the different usage of static member variables
	and the usage of overloading the ouput operator<< with arrays and objects.
	Further detail of what each components purpose is below in the code segments.

*/

#include <iostream>
#include <iomanip>
using namespace std;

// class declaration
class DivSales
{
private:
    double sales[4];
    static double totalSales; // a private static variable of type double

public:
    DivSales();
    void setSales(double first, double second, double third, double fourth); //member function that takes 4 arguements
    double getQSales (int i) const; // constant member function
    static double getCorpSales();
    friend ostream& operator<<(ostream& out, const DivSales& right);



};
	// Part II output operator
    // Creating an overloaded output operator<<
ostream &operator<<(ostream &out, const DivSales &right)
{
     out << right << endl;
     return out;
}


// default constructor
DivSales::DivSales()
{
    for (int i = 0; i < 4; i++)
        sales[i] = 0;
}

// function definitions
double DivSales::getCorpSales()
{
    return totalSales; // returns the total corporate sales
}

void DivSales::setSales(double first, double second, double third, double fourth)
{
    if (first < 0)
    {
        first = 0;
    }
    else if (second < 0)
    {
        second = 0;
    }
    else if (third < 0)
    {
        third = 0;
    }
    else if (fourth < 0)
    {
        fourth = 0;
    }
    sales[0] = first;
    sales[1] = second;
    sales[2] = third;
    sales[3] = fourth;
    totalSales += first + second + third + fourth;
}
double DivSales::getQSales(int i) const
{
    if (i >= 0 && i <= 3)
    {
        return sales[i];
    }
    else
    {
        return 0;
    }
}
double DivSales::totalSales = 0;
// function prototypes


int main()     // main
{

    const int NUM_DIV = 6;      	// number of divisions
    DivSales divisions[NUM_DIV]; 	// an array of DivSales objects
                                    // initialized with the default constructor

    // Part II
    // Output sales by division with operator<<

    // set values for all objects in divisions array
    divisions[0].setSales(3000.00, 4000.00, 5000.00, 6000.00);
    divisions[1].setSales(3500.00, 4500.00, 5500.00, 6500.00);
    divisions[2].setSales(1111.00, 2222.20, 3333.30, 4444.00);
    divisions[3].setSales(3050.00, 4050.00, 5050.00, 6050.00);
    divisions[4].setSales(3550.00, 4550.00, 5550.00, 6550.00);
    divisions[5].setSales(5000.00, 6000.00, 7000.00, 8000.00);

    cout << endl;
    for (int j = 0; j < 1; j++)
    cout << "Output sales by division : " << endl;

    double total = 0;
    for (int j = 0; j < 6; j++)
    {
        cout << "Sales for Division "<<(j+1) << endl;     // Output sales by division
        for (int i = 0; i < 4; i++)
        {
            cout << "Quarter " << (i + 1) << ": " << divisions[j].getQSales(i) << endl;
            total += divisions[j].getQSales(i);
        }
        cout << endl;
    }
    printf("Total Corporate Sales: $ %.2f", total);
    cout << endl;
    // Output total sales

    //DivSales using with operator<<
   	DivSales sl1[NUM_DIV];
   	sl1[0].setSales(3000.00, 4000.00, 5000.00, 6000.00);
    sl1[1].setSales(3500.00, 4500.00, 5500.00, 6500.00);
    sl1[2].setSales(1111.00, 2222.20, 3333.30, 4444.00);
    sl1[3].setSales(3050.00, 4050.00, 5050.00, 6050.00);
    sl1[4].setSales(3550.00, 4550.00, 5550.00, 6550.00);
    sl1[5].setSales(5000.00, 6000.00, 7000.00, 8000.00);

	 cout << endl;
	// Output sales by division with operator<<
    for (int j = 0; j < 1; j++)
    cout << "Output sales by division using operator<< : " << endl;

     total = 0;
    for (int j = 0; j < 6; j++)
    {
        cout << "Sales for Division "<<(j+1) << endl;     // Output sales by division
        for (int i = 0; i < 4; i++)
        {
            cout << "Quarter " << (i + 1) << ": " << sl1[j].getQSales(i) << endl;
            total += sl1[j].getQSales(i);
        }
        cout << endl;
    }
    printf("Total Corporate Sales: $ %.2f", total);
    cout << endl;
    return 0;
}

/*
Output:
Output sales by division :
Sales for Division 1
Quarter 1: 3000
Quarter 2: 4000
Quarter 3: 5000
Quarter 4: 6000

Sales for Division 2
Quarter 1: 3500
Quarter 2: 4500
Quarter 3: 5500
Quarter 4: 6500

Sales for Division 3
Quarter 1: 1111
Quarter 2: 2222.2
Quarter 3: 3333.3
Quarter 4: 4444

Sales for Division 4
Quarter 1: 3050
Quarter 2: 4050
Quarter 3: 5050
Quarter 4: 6050

Sales for Division 5
Quarter 1: 3550
Quarter 2: 4550
Quarter 3: 5550
Quarter 4: 6550

Sales for Division 6
Quarter 1: 5000
Quarter 2: 6000
Quarter 3: 7000
Quarter 4: 8000

Total Corporate Sales: $ 113510.50

Output sales by division using operator<< :
Sales for Division 1
Quarter 1: 3000
Quarter 2: 4000
Quarter 3: 5000
Quarter 4: 6000

Sales for Division 2
Quarter 1: 3500
Quarter 2: 4500
Quarter 3: 5500
Quarter 4: 6500

Sales for Division 3
Quarter 1: 1111
Quarter 2: 2222.2
Quarter 3: 3333.3
Quarter 4: 4444

Sales for Division 4
Quarter 1: 3050
Quarter 2: 4050
Quarter 3: 5050
Quarter 4: 6050

Sales for Division 5
Quarter 1: 3550
Quarter 2: 4550
Quarter 3: 5550
Quarter 4: 6550

Sales for Division 6
Quarter 1: 5000
Quarter 2: 6000
Quarter 3: 7000
Quarter 4: 8000

Total Corporate Sales: $ 113510.50
*/
