#include<iostream>

extern int x;

int main(){

    std::cout<<"Hello WOrld"<<std::endl;
    std::cout<<x; //Here we are trying to print X that is externally defined

    return 0;

//since we are not including its definition. We'll get a linker error. Our program will compile
//but we won't be able to run it
}