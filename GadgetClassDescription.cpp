// Author: Aaron Rodriguez
// Assignment Number: Lab 4
// File Name: L4b_Rodriguez.cpp
// Course/Section: COSC 1337 Section 006
// Date: 3/12/2022
// Instructor: Dr. B. Hohlt
//
/*
    Program Description: This program is intended hold/display gadget number, the description of gadget, and it price.
    with and discount constant function implemented that represnts the discount percentage. Two intances will be created to test both constructors.

*/


#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;

// Gadget Class Description
class Gadget
{
private :
    int gadgetNum;
    string description;
    double price;
public :
Gadget();
Gadget(int gadgetNum,string description,double price);
double discountPrice(double percent);
int getGadgetNum();
void setGadgetNum(int gadgetNum);
string getDescription();
void setDescription(string description);
double getPrice();
void setPrice(double price);
};

Gadget::Gadget()  // Default Constructor
{
   this->gadgetNum=0;
   this->price=0.0;
   this->description="";
}
Gadget::Gadget(int gadgetNum,string description,double price)
{
   this->gadgetNum=gadgetNum;
   this->price=price;
   this->description=description;
   }
double Gadget::discountPrice(double percent)
{
    double amount = 0.0;
    if(percent>0 && percent<1)
    {
        amount = price*percent;
       }
       return amount;
   }

int Gadget::getGadgetNum() {
       return gadgetNum;
   }


   void Gadget::setGadgetNum(int gadgetNum) {
       this->gadgetNum = gadgetNum;
   }


   string Gadget::getDescription() {
       return description;
   }


   void Gadget::setDescription(string description) {
       this->description = description;
   }

double Gadget::getPrice() {
   return price;
}


void Gadget::setPrice(double price) {
   if(price>0.0)
   this->price = price;
}

int main()
{
   // Creating instances of Gadget class
   Gadget g1;
   g1.setGadgetNum(1);
   g1.setDescription("Desktop");
   g1.setPrice(15000);
   cout<<"Gadget#1:"<<endl;
   cout<<"Gadget No :"<<g1.getGadgetNum()<<endl;
   cout<<"Description :"<<g1.getDescription()<<endl;
   cout<<"Price :$"<<g1.getPrice()<<endl;
   cout<<"Discount Prcie :$"<<g1.discountPrice(0.20)<<endl;

   Gadget g2(2,"Hard Disk",120);
       cout<<"\nGadget#2:"<<endl;
   cout<<"Gadget No :"<<g2.getGadgetNum()<<endl;
   cout<<"Description :"<<g2.getDescription()<<endl;
   cout<<"Price :$"<<g2.getPrice()<<endl;
   cout<<"Discount Prcie :$"<<g2.discountPrice(0.10)<<endl;
   return 0;
}

/*
 OUTPUT:
 Gadget#1:
Gadget No :1
Description :Desktop
Price :$15000
Discount Prcie :$3000

Gadget#2:
Gadget No :2
Description :Hard Disk
Price :$120
Discount Prcie :$12

--------------------------------
Process exited after 0.0129 seconds with return value 0

*/
