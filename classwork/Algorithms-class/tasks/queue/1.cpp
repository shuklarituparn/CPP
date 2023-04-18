#include <iostream>

class Stack1 {
private:
    int top_;
    int* data_;
    int capacity_;

public:
    Stack1(int capacity) {
        top_ = -1;
        capacity_ = capacity;
        data_ = new int[capacity];
    }

    ~Stack1() {
        delete[] data_;
    }

    void push(int value) {
        if (top_ == capacity_ - 1) {
            std::cout << "Stack Overflow\n";
            return;
        }

        data_[++top_] = value;
    }

    int pop() {
        if (top_ == -1) {
            std::cout << "Stack Underflow\n";
            return -1;
        }

        return data_[top_--];
    }

    int peek() {
        if (top_ == -1) {
            std::cout << "Stack is empty\n";
            return -1;
        }

        return data_[top_];
    }

    bool isEmpty() {
        return top_ == -1;
    }
};

class Stack2 {
private:
    int top_;
    int* data_;
    int capacity_=1;
    int size=0;

public:
    Stack2(int capacity) {
        top_ = -1;
        capacity_ = capacity;
        data_ = new int[capacity];
    }

    ~Stack2() {
        delete[] data_;
    }

    void push(int value) {
        if (top_ == capacity_ - 1) {
            std::cout << "Stack Overflow\n";
            return;
        }
        if (capacity_ == size_) {

    Resize(capacity_ * 2);
    data_[size_++] = input;

  } else {
    data_[size_] = input;
    size_++;
  }
        data_[++top_] = value;
    }

    int pop() {
        if (top_ == -1) {
            std::cout << "Stack Underflow\n";
            return -1;
        }

        return data_[top_--];
    }

    int peek() {
        if (top_ == -1) {
            std::cout << "Stack is empty\n";
            return -1;
        }

        return data_[top_];
    }

    bool isEmpty() {
        return top_ == -1;
    }
};

   /*  enQueue(q, x): 

        While stack1 is not empty, push everything from stack1 to stack2.
        Push x to stack1 (assuming size of stacks is unlimited).
        Push everything back to stack1.

    Here time complexity will be O(n)

    deQueue(q): 

        If stack1 is empty then error
        Pop an item from stack1 and return it

    Here time complexity will be O(1) */



 /* enQueue(x)
  1) Push x to stack1.

deQueue:
  1) If stack1 is empty then error.
  2) If stack1 has only one element then return it.
  3) Recursively pop everything from the stack1, store the popped item 
    in a variable res,  push the res back to stack1 and return res */