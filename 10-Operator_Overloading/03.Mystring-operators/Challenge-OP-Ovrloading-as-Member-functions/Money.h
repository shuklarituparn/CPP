
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
