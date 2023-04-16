#include <iostream>

// Add const qualifier to the given type
template<typename T>
struct add_const {
    using type = const T;
};

// Remove const qualifier from the given type
template<typename T>
struct remove_const {
    using type = T;
};

// Specialization of remove_const for const types
template<typename T>
struct remove_const<const T> {
    using type = T;
};

int main() {
    using non_const_int = int;
    using const_int = const int;

    // Add const qualifier to non-const int
    using const_non_const_int = typename add_const<non_const_int>::type;
    std::cout << std::boolalpha << std::is_same<const_non_const_int, const int>::value << '\n';

    // Remove const qualifier from const int
    using non_const_const_int = typename remove_const<const_int>::type;
    std::cout << std::boolalpha << std::is_same<non_const_const_int, int>::value << '\n';

    return 0;
}

/*
The above program can be written as using typedef

type_def used to define a variable to new name

SYNTAX:

typedef existing_type new_name;

#include <iostream>

// Add const qualifier to the given type
template<typename T>
struct add_const {
    typedef const T type;
};

// Remove const qualifier from the given type
template<typename T>
struct remove_const {
    typedef T type;
};

// Specialization of remove_const for const types
template<typename T>
struct remove_const<const T> {
    typedef T type;
};

int main() {
    typedef int non_const_int;
    typedef const int const_int;

    // Add const qualifier to non-const int
    typedef add_const<non_const_int>::type const_non_const_int;
    std::cout << std::boolalpha << std::is_same<const_non_const_int, const int>::value << '\n';

    // Remove const qualifier from const int
    typedef remove_const<const_int>::type non_const_const_int;
    std::cout << std::boolalpha << std::is_same<non_const_const_int, int>::value << '\n';

    return 0;
}





*/

/*

Here, non_const_int and const_int are defined as aliases for int and const int, respectively. The typename keyword is used to indicate that add_const<non_const_int>::type and remove_const<const_int>::type are dependent names, which means that they depend on a template parameter and may not be resolved until template instantiation.

The using keyword is then used again to define const_non_const_int and non_const_const_int as aliases for the types returned by the add_const and remove_const meta-functions, respectively.

Using type aliases can make the code more readable by giving descriptive names to types, rather than using their full names or repeatedly typing out complex type expressions.
*/