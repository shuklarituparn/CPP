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

// full specialization for classes
template <typename T>
class S{...}

template <>
class<int> S{...};



template <typename T>
void f(T, T) {
    std::cout << 2;
}

template <typename T, typename U>
class M{...}

template <typename T>
class M<T,T*>{};

int main()
{
    f(2,3);
    return 0;
}
