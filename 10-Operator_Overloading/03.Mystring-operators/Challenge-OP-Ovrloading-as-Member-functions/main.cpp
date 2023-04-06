#include"Money.h"
#include<cstring>

Money::Money(int dollars, int cents) : dollars{dollars}, cents{cents} {}

Money::Money(int total) : dollars {total/100}, cents{total%100}  {}
   

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR METHOD DEFINITIONS BELOW THIS LINE----

bool Money::operator==(const Money &rhs)const{
    return dollars==rhs.dollars&& cents==rhs.cents; //if "this" dollars are equal to the one passed
                                //if "this" cents are equal to the one that we are giving it
    
    
}
bool Money::operator!=(const Money &rhs)const{
    
    return dollars !=rhs.dollars &&cents!= rhs.cents; //same thing but for the case of non-equal

    
}

//----WRITE YOUR METHOD DEFINITIONS ABOVE THIS LINE----


#ifndef _MONEY_MONEY_H
#define _MONEY_MONEY_H


#include <iostream>

class Money {
    int dollars;
    int cents;
public:
    Money(int dollars, int cents); //Money can be written as dollars and cents
    Money(int total);  //money can also be written as total 

    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR METHOD DECLARATIONS BELOW THIS LINE----
    
    bool operator==(const Money &rhs)const;  //operator declaration
    bool operator!=(const Money &rhs)const;  //passing the reference of the money we wanna compare

    
    //----WRITE YOUR METHOD DECLARATIONS ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
};


#endif //_MONEY_MONEY_H
