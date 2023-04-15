/*
Compile-time factorial calculation: A simple example of TMP is calculating the factorial of a number at compile-time. This can be achieved using recursive templates, where each template instantiation calculates the factorial of the previous number:
*/

#include <type_traits>
template <int N>
struct Factorial {
    static const int value = N * Factorial<N-1>::value; //basically multiplying N with the value we got for N-1 initialization. that's why ::value
};

template <>
struct Factorial<0> {
    static const int value = 1;
};

/*
::value is used to access the static constant member variable value of the Factorial struct. Since Factorial is a template struct, its value member can have different values for different instantiations of the template. By using ::value, we can retrieve the value of value for a particular instantiation of the Factorial struct.
*/

template <typename T>
struct is_pointer {
    static const bool value = false;
};

template <typename T>
struct is_pointer<T*> {
    static const bool value = true;
};

/*
Template meta programming also used to Manipulate and query types at compile-time. The above template determines if the type is a pointer or not
*/

template <typename T>
T add(T a, T b) {
    return a + b;
}

template <typename T, typename U>
typename std::common_type<T, U>::type add(T a, U b) {
    return a + b;
}

/*
. For example, the following template generates a function that adds two numbers of the same type, and a different version for adding two numbers of different types
*/


/*

EXPLANATIONS OF THE ABOVE CODE AND STD::COMMON

In the add function template, the std::common_type<T, U>::type is used as the return type. This means that the return type of the add function will be the common type of T and U.

For example, let's say we call the add function with T as int and U as float. The common type of int and float is float, so the return type of the add function will be float.

The typename keyword is used to indicate that std::common_type<T, U>::type is a type name. In C++, there are some cases where the compiler cannot determine whether a name refers to a type or a value. Such names are called dependent names. Since std::common_type<T, U>::type depends on the template parameters T and U, it is a dependent name. In order to tell the compiler that std::common_type<T, U>::type is a type name, we use the typename keyword.

In summary, the add function template uses std::common_type<T, U>::type as the return type to ensure that the result of the function is always the correct type, regardless of the input types.
*/

