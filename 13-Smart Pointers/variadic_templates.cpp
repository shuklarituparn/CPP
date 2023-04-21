/* Variadic templates are a feature of the C++ programming language that allow a template to accept an arbitrary number of arguments of any type. This means that a function or class template can be written to handle a variable number of arguments, rather than a fixed number of arguments.

The syntax for defining a variadic template is to use an ellipsis (...) after the template parameter list. This indicates that the template will accept an arbitrary number of arguments of any type */

template <typename... Args>
void print(Args... args) {
    ((std::cout << args << " "), ...);
}


/* In this example, the template parameter pack is named "Args". The function uses a fold expression to print each argument to the console, separated by a space.

Variadic templates are useful when you need to write a generic function or class that can handle a variable number of arguments, such as a logging function that needs to accept any number of log messages. They can also be used to implement type-safe formatting functions, or to implement recursive template functions. */


// EXAMPLES OF VARIADIC TEMPLATES IN C++

//1. Print function that accepts a variable number of arguments.

template<typename... Args>
void print(Args&&... args) {
    ((std::cout << args << " "), ...);
}

// Usage example
print("Hello", 42, 3.14, 'A');
// Output: Hello 42 3.14 A


//2. Variadic template class that recursively calculates the number of arguments.

template<typename... Args>
struct Product {
    static constexpr int value = 1;
};

template<typename T, typename... Args>
struct Product<T, Args...> {
    static constexpr int value = T::value * Product<Args...>::value;
};

struct A { static constexpr int value = 2; };
struct B { static constexpr int value = 3; };
struct C { static constexpr int value = 5; };

// Usage example
static_assert(Product<A, B, C>::value == 30);

/* 
In this example, the Product class template recursively calculates the product of the value member of its template arguments using template specialization. The static_assert at the end checks that the calculation is correct when A, B, and C are used as template arguments. */