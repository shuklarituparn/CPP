#include<iostream>
#include <string>
#include <vector>

int main(){

std::string userInput;
std::cin>>userInput;

for(int i{0}; i<userInput.length()-1; i++){

    
    for(int j{1}; j<userInput.length(); j++){
        
        if(userInput[i]==userInput[j])
            std::cout<<userInput[j];
    }
}




}