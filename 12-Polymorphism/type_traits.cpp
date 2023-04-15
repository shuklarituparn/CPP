/*
Type traits are a feature in C++ that allow you to introspect on the properties of types at compile-time. They provide a way to determine information about a type, such as whether it is a pointer, an array, or an enumeration, and what its size and alignment requirements are.

Type traits are implemented as templates, where the template parameter is the type you want to introspect on. The template itself contains a set of traits that provide information about the type.

Here is an example of using type traits to determine whether a type is an integer:

*/

#include <type_traits>
#include <iostream>

template<typename T>
struct is_integer {
    static constexpr bool value = std::is_integral<T>::value;
};

int main() {
    std::cout << is_integer<int>::value << std::endl; // Output: 1
    std::cout << is_integer<float>::value << std::endl; // Output: 0
}

/*
we define a template struct is_integer that has a single static member variable value. The value of value is determined by the std::is_integral trait, which is part of the <type_traits> header. std::is_integral<T>::value is a boolean value that is true if T is an integral type, and false otherwise.

In main(), we use is_integer to determine whether int and float are integers. We do this by accessing the value member of is_integer<int> and is_integer<float>, respectively. Since int is an integer and float is not, the output of the program is 1 and 0, respectively.

*/