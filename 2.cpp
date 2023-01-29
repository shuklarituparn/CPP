#include <iostream>
#include<string>

int main(){

    std::string s1 {"frank"};
    std::string s2 {"leo"};
    std::string *p2 {&s2};
    std::cout<<&s2;

    std::string *p1 {&s1};
    std::cout<<*p1;
    //std::string *p1 {s1};
    //std::cout<<*p1;


}