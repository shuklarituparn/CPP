#include <iostream>

template<int N>
struct Fibonacci {
    static constexpr int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

template<>
struct Fibonacci<0> {
    static constexpr int value = 0;
};

template<>
struct Fibonacci<1> { 
    static constexpr int value = 1;
};

int main() {
    constexpr int fib = Fibonacci<10>::value;
    std::cout << "The 10th Fibonacci number is: " << fib << std::endl;
    return 0;
}
