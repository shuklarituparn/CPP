#include<iostream>

int &getnum(){   //it's a reference in the memory that is returned. 

    static int value=10;  
    return value;
}

void set_value(int &&value){ //passing the rvlaue using "&&"

     std::cout<<value;
}

void set_value1(int value){



}

int main (){

int x=10; //Here X is a lvalue as it has an address in the memory and can place a value at that memory location

//in the above expression 10 is a rvlaue as it doesnn't have a location in the memory

x=getnum();

//std::cout<<x;

getnum()=122;  //So here we are storing the integer at the reference in the memory that the function returned to us.

x=getnum();

//std::cout<<x;

//set_value(10);//here we are passing an rvalue and that value gets stored in the int value

//set_value1(x); // passing a lvalue to the function

/*

Since, the function takes an integer, we can pass the rvalue or the lvalue.

If we'll pass the lvalue it'll be assigned to the function and the variable that we passed

Same for the rvalue

*/ 

set_value(10);

//set_value can now take the rvalues

return 0;

}