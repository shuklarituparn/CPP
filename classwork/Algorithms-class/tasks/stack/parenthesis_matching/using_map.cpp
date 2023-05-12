#include <iostream>
#include<cstring>
#include <stack>
#include <map>

using namespace std;
 
int isBalanced(char* exp){//function to check if the expression is balanced
 
    // Create map
    map<char, char> mapping; 
    mapping['}'] = '{'; //mapping the closing bracket to the opening bracket
    mapping[')'] = '(';
    mapping[']'] = '[';//closing bracket is the key, opening bracket is the value (or first and second respectively)
 
    // Create map iterator
    map<char, char>::iterator itr;  
 
    // Create stack
    stack<char> stk;
 
    for (int i=0; i<strlen(exp); i++){ //looping through the expression
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '('){//if its opening brakcet then push
            stk.push(exp[i]); //pushing the opening bracket
        } else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')'){ //if its closing bracket then checking the code
            if (stk.empty()){ //if we are encountering closing bracket but not an open bracket then we have an unbalanced expression
                return false;
            } else {
                char temp = stk.top();  //storing the top of the stack in the a temp char variable
                itr = mapping.find(exp[i]); //using the itr to find the expression in the map
                if (temp == itr->second){  // itr->first is key, itr->second is value
                    stk.pop(); //if we find the expression in the map to be matching then we pop it out
                } else {
                    return false;
                }
            }
        }
    }
    return stk.empty() ? true : false; //if in the end we still have some element in the stack them it's not balanced otherwise it is
}
 
int main() {
 
    char A[] = "{([a+b]*[c-d])/e}";
    cout << isBalanced(A) << endl;
 
    char B[] = "{([a+b]}*[c-d])/e}";
    cout << isBalanced(B) << endl;
 
    char C[] = "{([{a+b]*[c-d])/e}";
    cout << isBalanced(C) << endl;
 
    return 0;
}