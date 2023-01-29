#include <iostream>
#include<string>

int main(){

    std::string s1 {"frank"};
    std::string s2 {"leo"};
    std::string *p2 {&s2};
    std::string *p3 {&s1};
    //std::cout<<&s2;

    std::string *p1 {&s1};
    std::cout<<*p1<<std::endl;
    //std::string *p1 {s1};
    //std::cout<<*p1;

    std::cout<<(p1==p2)<<std::endl; //False
    std::cout<<(p1==p3)<<std::endl; //True

}

//Pointer comparision happens based on the basis of address in the memory
//Pointer doesn't compare the value but just the address