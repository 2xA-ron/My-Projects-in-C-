// Author: Aaron Rodriguez
// Assignment Number: Lab 3
// File Name: L3_AaronRodriguez.cpp
// Course/Section: COSC 1337 Section 006
// Date: 3/4/2022
// Instructor: Dr. B. Hohlt
//
/*
    Program Description: This menu driven program converts kilo grams to pounds and pounds. Upon startup a menu will display giving you 3 option
    Converting kilograms to pounds, Convert pounds to Kilograms or the Quit the program.

 OUTPUT:


    MENU
1. Convert kilograms to pounds
2. Convert pounds to kilograms
3. Quit
Enter your choice: 1
Weight to be converted: 89
89 kilograms = 195.8 pounds.


MENU
1. Convert kilograms to pounds
2. Convert pounds to kilograms
3. Quit
Enter your choice: 2
Weight to be converted: 715
715 pounds = 325 kilograms.


MENU
1. Convert kilograms to pounds
2. Convert pounds to kilograms
3. Quit
Enter your choice:



*/
// Function prototypes
   #include <iostream>
    #include <fstream>
    #include <string>
    using namespace std;


void displayMenu();
int getChoice();
double kilosToPounds(double );
double poundsToKilos(double );

/***** main *****/
int main()
{
//variable to store the user choice
int ch=0;

//variable to store the user input
double x;

//While not to quit
while(ch!=3)
{
   //display the menu
   displayMenu();

   //take the choice
   ch=getChoice();

   //if user choice is 1
   if(ch==1)
   {
       //take the input
       cout<<"Weight to be converted: ";
       cin>>x;

       //calculate and display the result
       cout<<x<<" kilograms = "<<kilosToPounds(x)<<" pounds.\n";
   }

   //if user choice is 2
   if(ch==2)
   {
       //take the input
       cout<<"Weight to be converted: ";
       cin>>x;

       //calculate and display the result
       cout<<x<<" pounds = "<<poundsToKilos(x)<<" kilograms.\n";
   }

   if(ch==3)
   {
       cout<<"Good bye!!!"<<endl<<endl;
   }


}

return 0;
}

/*** displayMenu function ***/
void displayMenu()
{
   cout<<"\n\nMENU"<<endl;
   cout<<"1. Convert kilograms to pounds"<<endl;
   cout<<"2. Convert pounds to kilograms"<<endl;
   cout<<"3. Quit"<<endl;
}

/*** getChoice ***/
int getChoice()
{
   cout<<"Enter your choice: ";
   int ch;
   cin>>ch;
   return ch;
}

/*** kilosToPounds ***/
double kilosToPounds(double kilos)
{
   return 2.2*kilos;
}

/*** poundsToKilos ***/
double poundsToKilos(double pounds)
{
   return pounds/2.2;
}
