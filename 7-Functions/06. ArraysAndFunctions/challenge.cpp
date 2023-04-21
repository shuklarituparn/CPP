/*
In this exercise you will create a program that will be used to print the guest_list to an event and then clear the guest_list when the event is over.

Begin by completing the function prototypes print_guest_list and clear_guest_list which are both passed an array of std::string and a size_t value. Ensure that the array cannot be modified within the print_guest_list function by using the keyword const in the parameter list.

Now that the function prototypes have been declared, at the bottom of the file define both functions.

Both the print_guest_list and clear_guest_list functions will be passed the array argument guest_list and the size_t argument guest_list_size which have both been provided to you.

The print_guest_list function should print the values contained within the guest_list from left to right with each element being printed on a new line.  Use a for loop to iterate through the array.

The clear_guest_list function should replace each element of the array with the string value " ", a single space.  Use a for loop to iterate through the array.

Now, from the function body of event_guest_list, make the following function calls in this order:

print_guest_list

clear_guest_list

print_guest_list

and passing the array argument guest_list and the size_t argument guest_list_size with each function call.

You can find my solution by clicking on the solution.txt file on the left pane. But please make sure you give it a go yourself first, and only check the solution if you really get stuck.


*/
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE THE FUNCTION PROTOTYPES BELOW THIS LINE----

string print_guest_list(const string[], size_t);//----WRITE THE FUNCTION PARAMETER LIST WITHIN THE PARENTHESES
void clear_guest_list(string[], size_t);//----WRITE THE FUNCTION PARAMETER LIST WITHIN THE PARENTHESES
                                      
//----WRITE THE FUNCTION PROTOTYPES ABOVE THIS LINE----                                      
//----DO NOT MODIFY THE CODE BELOW THIS LINE----

void event_guest_list() {

    string guest_list[] {"Larry", "Moe", "Curly"};
    size_t guest_list_size {3};

    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE THE FUNCTION CALLS BELOW THIS LINE----

    print_guest_list(guest_list,  guest_list_size);    
    clear_guest_list(guest_list,  guest_list_size);
    print_guest_list(guest_list,  guest_list_size);
    

    //----WRITE THE FUNCTION CALLS ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
}

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE THE FUNCTION DEFINITION BELOW THIS LINE----

string print_guest_list(const string guest_list[], size_t guest_list_size) {//----WRITE THE FUNCTION PARAMETER LIST WITHIN THE PARENTHESES

    //----WRITE THE FUNCTION BODY BELOW THIS LINE----
    
    for(size_t i {0}; i<guest_list_size; i++){
        
        cout<<guest_list[i]<<endl;
    }
        
    
        
    //----WRITE THE FUNCTION BODY ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    return typeid(guest_list).name();
}

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE THE FUNCTION DEFINITION BELOW THIS LINE----

void clear_guest_list(string guest_list[], size_t guest_list_size) {//----WRITE THE FUNCTION PARAMETER LIST WITHIN THEPARENTHESES

    //----WRITE THE FUNCTION BODY BELOW THIS LINE----
    
    for(size_t i {0}; i<guest_list_size; i++){
        guest_list[i]=" ";
    
    }
    //----WRITE THE FUNCTION BODY ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
}