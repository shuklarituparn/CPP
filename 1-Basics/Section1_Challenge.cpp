#include <iostream>

int main(){

    int favNum;
    
    std::cout<<"Enter your favorite number: ";
    std::cin>>favNum;
    std::cout<<"Amazing!! That's my fav number too!\n";
    std::cout<<"No really!!"<< favNum <<"is my favorite number\n"<<std::endl;
    return 0;
}

//putting a space before and after favNum in line 10 doesn't have any effect on output.