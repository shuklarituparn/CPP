// Constants

/* 
    Frank's Carpet Cleaning Service
    Charges $30 per room
    Sales tax rate is 6%
    Estimates are valid for 30 days

    Prompt the user for the number of rooms they would like cleaned
    and provide an estimate such as:
     
Estimate for carpet cleaning service:
Number of rooms: 2
Price per room: $30
Cost: $60
Tax: $3.6
====================================
Total estimate: $63.6
This estimate is valid for 30 days

Pseudocode:
    Prompt the user to enter the number of rooms
    Display number of rooms
    Display price per room
    
    Display cost:  (number of rooms * price per room)
    Display tax:   number of rooms * price per room * tax rate
    Display total estimate: (number of rooms * price per room) + (number of rooms * price per room * tax rate)
    Display estimate expiration time
*/

#include <iostream>

int main(){

    int rooms;
    const int pricePerRoom {30};
    const float taxRate {0.06};
    const int expiry {30};
    float totalEstimate;

    std::cout << "Hello, welcome to Frank's Carpet Cleaning Service" <<std::endl;
    std::cout << "\nHow many rooms would you like cleaned? ";

    std::cin>>rooms;
    std::cout<<"\nEstimate for carpet cleaning service: ";
    std::cout<<"\nNumber of rooms: "<<rooms;
    std::cout<<"\nPrice per room: "<<pricePerRoom;
    std::cout<<"\nCost: "<<rooms*pricePerRoom;
    std::cout<<"\nTaxes: "<<taxRate*(rooms*pricePerRoom);
    std::cout <<"\n===============================" <<std::endl;
    std::cout<<"\nTotal Estimate: "<<(rooms*pricePerRoom)+(taxRate*(rooms*pricePerRoom));
    std::cout<<"\nThis Estimate is valid till "<<expiry<<" days";

    return 0;



    
}