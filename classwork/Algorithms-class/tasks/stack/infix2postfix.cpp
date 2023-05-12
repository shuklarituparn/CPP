#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

int isOperand(char operand) {
  if (operand == '+' || operand == '-' || operand == '*' || operand == '/' ||
      operand == '^' || operand == '(' || operand == ')') {

    return 0;
  }
  return 1;
}

int outPrecedence(char operand) {
  if (operand == '+' || operand == '-') {
    return 1;
  } else if (operand == '*' || operand == '/') {
    return 3;
  } else if (operand == '^') {
    return 6;
  } else if (operand == '(') {
    return 7;
  } else if (operand == ')') {
    return 0;
  }

  return -1;
}

int inPrecedence(char operand) {

  if (operand == '+' || operand == '-') {
    return 2;
  } else if (operand == '*' || operand == '/') {
    return 4;
  } else if (operand == '^') {
    return 5;
  } else if (operand == ')') {
    return 0;
  }

  return -1;
}

char *convert(char *infix) {
  char *postfix = new char[strlen(infix) + 1];

  stack<char> stak;

  int i = 0;

  int j = 0;

  while (infix[i] != '\0') {//loop through the infix
    if (isOperand(infix[i])) {//check if the current character is the operand
      postfix[j++] = infix[i++]; //added to postfix string and both increment by `
    } else {
      if (stak.empty() || outPrecedence(infix[i]) > inPrecedence(stak.top())) {
        stak.push(infix[i++]);
      } else if (outPrecedence(infix[i]) == inPrecedence(stak.top())) {
        stak.pop();
      } else {
        postfix[j++] = stak.top();
        stak.pop();
      }
    }
  }
  /*
  If the character at the current index of the infix string is not an operand, it must be an operator. This code block checks whether the operator at the current index has higher precedence than the top element of the stk stack (i.e., stk.top()), or whether the stack is empty. If either of these conditions is true, then the operator is pushed onto the stack, and i is incremented by 1.

If the operator at the current index has the same precedence as the top element of the stack, then the top element is popped off the stack, but not added to the postfix string.

If the operator at the current index has lower precedence than the top element of the stack, then the top element of the stack is added to the postfix string at the current index j, j is incremented by 1, and the top element is popped off the stack.
  */

  while (!stak.empty() && stak.top() != ')') {
    postfix[j++] = stak.top();
    stak.pop();
  }
  /*
This while loop runs as long as the stack is not empty and the top element of the stack is not a closing parenthesis ). In this loop, the remaining operators in the stack are added to the postfix string at the current index j, j is incremented by 1, and the elements are popped off the stack.
*/

  postfix[j] = '\0';

  return postfix;
}

/*
Finally, the null terminator character \0 is added to the end of the postfix string at index j. This is necessary to indicate the end of the string. The postfix string is then returned by the function.
*/

int main() {

  char infix[] = "((a+b)*c)-d^e^f";

  cout << convert(infix) << endl;
}