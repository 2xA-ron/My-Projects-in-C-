/*
    Program Description: This Program present on math problem per program execution at random after you give your answer it will provide the solution.
*/
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{

   //declaration of double variables which will hold our random numbers
   double random1, random2, result;
   //seed a random generator
   srand(time(0));

   cout << "\t\tMath Tutor " << endl;
   cout<<"Play addition of two random numbers "<<endl;

   //Generate two random numbers in between 1 and 9 each time the program is executed
   random1 = 1 + rand() % 9;
   random2 = 1 + rand() % 9;

   cout << "\n";
   cout << random1 << " + " << random2 << " = " << endl;
   cout << "Enter your answer. Then hit enter to check the answer"<<endl;
   //Read a key from the user to display the result
   cin.get();

   //add the two random numbers and store in result
   result = random1 + random2;
   cout << "" << endl;
   cout << random1 << " + " << random2<< " = " << result << endl;

   system("pause");
   return 0;
}


