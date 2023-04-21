#include<iostream>

template<typename T, typename U>
void f(T, U){
    std::cout<<1;
}
template<>
void f(int, int){
    std::cout<<3;

}

//full specialization for classes

template<typename T>
class S{......};

template <>
class <int> S{.......};

