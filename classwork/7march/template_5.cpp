#include <iostream>

// full specialization for functions
template <typename T, typename U>
void f(T, U) {
    std::cout << 1;
}

template <>
void f(int, int) {
    std::cout << 3;
}

template <typename T>
void f(T, T) {
    std::cout << 2;
}



int main()
{
    f(2,3);
    return 0;
}
