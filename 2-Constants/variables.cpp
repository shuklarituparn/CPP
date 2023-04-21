#include<iostream>

int main(){

    int length {};
    int breadth {};
    int height {};

    std::cout<<"Enter Length:\t",std::cin>>length;
    std::cout<<"Enter Breadth:\t",std::cin>>breadth;
    std::cout<<"Enter Height:\t",std::cin>>height;

    // int volume=length*breadth*height; we can do like this

    std::cout<<"Volume of cuboid is"<<length*breadth*height;

    return 0;
}

