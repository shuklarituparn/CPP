#include <iostream>
#include <utility>

// A simple function that prints its argument
void print(const std::string& s) {
    std::cout << s << std::endl;
}

// A function that forwards its argument to another function
template <typename T>
void forward(T&& arg) {
    print(std::forward<T>(arg));
}

int main() {
    std::string s = "Hello";
    forward(s); // pass an lvalue
    forward("World"); // pass an rvalue
    return 0;
}

/* In this example, the forward function uses perfect forwarding to pass its argument to the print function without losing any type information. This allows us to pass both lvalues (such as the s variable) and rvalues (such as the string literal "World") to forward and have them correctly forwarded to print */