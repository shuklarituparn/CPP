#ifndef _I_PRINTABLE_H_
#define _I_PRINTABLE_H_
#include <iostream>

class I_Printable   //printable class that is an Interface for the other classes
{
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
public:
    virtual void print(std::ostream &os) const = 0;   //virtual methods so that it can be used in other class. Virtual Methods are initialized with 0 always
    virtual ~I_Printable() = default;  //default destructor. using default to not nuke the main class accidently
};


#endif // _I_PRINTABLE_H_
