#include <iostream>
#include "I_Printable.h"

std::ostream &operator<<(std::ostream &os, const I_Printable &obj) {  //definition of the printable method outside the class
    obj.print(os);
    return os;
}