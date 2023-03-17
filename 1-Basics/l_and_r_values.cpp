#include<iostream>

int &getnum(){   //it's a reference in the memory that is returned. 

    static int value=10;  
    return value;
}

int main (){

int x=10; //Here X is a lvalue as it has an address in the memory and can place a value at that memory location

//in the above expression 10 is a rvlaue as it doesnn't have a location in the memory

x=getnum();

std::cout<<x;

getnum()=122;  //So here we are storing the integer at the reference in the memory that the function returned to us.

x=getnum();

std::cout<<x;

return 0;

}