// Section 9
// Challenge
#include <iostream>
#include <vector>

int main() {
    
    std::vector<int> numbers {};
    char choice {};
    
    do{
    std::cout<<"\nHello to this program\n"<<std::endl;
    std::cout<<"Here are the things you can do\n"<<std::endl;
    std::cout<<"P - Print numbers"<<std::endl;
    std::cout<<"A - Add a number"<<std::endl;
    std::cout<<"M - Display mean of the numbers"<<std::endl;
    std::cout<<"S - Display the smallest number"<<std::endl;
    std::cout<<"L - Display the largest number"<<std::endl;
    std::cout<<"Q - Quit"<<std::endl;
    std::cout<<"\nEnter your option: ";
    std::cin>> choice;

    if(choice== 'P' || choice== 'p'){
        if (numbers.size()==0)
            std::cout<<"\nThere are no numbers"<<std::endl;
        else{
            std::cout<<"[";
            for(auto num: numbers){
                std::cout<<num;
            }
            std::cout<<"]"<<std::endl;
        }  
    } 
    else if(choice== 'A' || choice== 'a'){
        int user_input{};
        std::cout<<"Enter an element: "<<std::endl;
        std::cin>>user_input;
        numbers.push_back(user_input);
        std::cout<<user_input<< " added succesfully\n"<<std::endl;
    }
    else if(choice== 'M' || choice== 'm'){
        double total{};
        double mean{};
        if(numbers.size()!=0){
            for(auto num: numbers){
                total+=num;
            }

            mean= total/numbers.size();
            std::cout<<"The mean is "<<mean<<std::endl;
        }
        else
            std::cout<<"There are no elements"<<std::endl;
    }
    else if(choice== 'S' || choice== 's'){
        int smallest = numbers.at(0); //so that we can get a number to compare our result to
        if(numbers.size()!=0){

            for(auto comp:numbers){
                if(comp<smallest)
                    smallest=comp;
            }
        }
        else {
            std::cout<<"There are no elements"<<std::endl;
        }
            
    }
    else if(choice== 'L' || choice== 'l'){
        int largest = numbers.at(0);
        if(numbers.size()!=0){

            for(auto comp:numbers){
                if(comp>largest)
                    largest=comp;
            }
        }
        else{
            std::cout<<"There are no elements"<<std::endl;
        }
            
    }
    else if (choice== 'Q' || choice== 'q'){
        std::cout<<"BYE"<<std::endl;
    }
    else
        std::cout<<"Invalid choice try again "<<std::endl;
          
    }while ( choice != 'q' && choice != 'Q');

    return 0;

}

