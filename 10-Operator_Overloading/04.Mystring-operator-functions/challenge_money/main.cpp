#ifndef _MONEY_MONEY_H
#define _MONEY_MONEY_H


#include <iostream>

class Money {
    
    int dollars; //private class attributes
    int cents;
public:
    Money(int dollars, int cents); //constructors
    Money(int total); //constructor. Class of type money that's initialized with int total
    int get_dollars() const {return dollars;} //getters
    int get_cents() const {return cents; } //getters
    

    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR METHOD DECLARATIONS BELOW THIS LINE----
    friend Money operator +(const Money &lhs, const Money &rhs); //method declaration
                        //operator ovelroading with "+" that's passed address of lhs and rhs
    
    //----WRITE YOUR METHOD DECLARATIONS ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
};


#endif //_MONEY_MONEY_H


#include "Money.h"

Money::Money(int dollars, int cents) : dollars{dollars}, cents{cents} {} //Using money constructor from outside

Money::Money(int total) : dollars {total/100}, cents{total%100}  {} //using money constructor that stores total
   

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR METHOD DEFINITIONS BELOW THIS LINE----

 Money operator+(const Money &lhs, const Money &rhs) {   //operator definition taking two reference 
int total= (rhs.dollars+lhs.dollars)*100;  //storing value in type int all the dollars
total+= lhs.cents+rhs.cents; //adding cents to it

return Money{total};  //returning the class type money with total
}
//----WRITE YOUR METHOD DEFINITIONS ABOVE THIS LINE----


