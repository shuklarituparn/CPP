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

  while (infix[i] != '\0') {
    if (isOperand(infix[i])) {
      postfix[j++] = infix[i++];
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

  while (!stak.empty() && stak.top() != ')') {
    postfix[j++] = stak.top();
    stak.pop();
  }

  postfix[j] = '\0';

  return postfix;
}

int main() {

  char infix[] = "((a+b)*c)-d^e^f";

  cout << convert(infix) << endl;
}