#include <iostream>
#include <vector>
#include <type_traits>

// A function that copies or moves its argument depending on its size
template <typename T>
typename std::enable_if<sizeof(T) <= sizeof(void*), T>::type
copy_or_move(T&& arg) {
    return arg; // copy if the object is small
}

template <typename T>
typename std::enable_if<sizeof(T) > sizeof(void*), T>::type
copy_or_move(T&& arg) {
    return std::move(arg); // move if the object is large
}

int main() {
    std::vector<int> v1(100); // create a large object
    std::vector<int> v2 = copy_or_move(v1); // move the object
    return 0;
}

/* In this example, we define two versions of the copy_or_move function, one that copies its argument if the object is small, and one that moves it if the object is large. We use the std::enable_if type trait to conditionally enable one version or the other based on the size of the object. This allows us to choose whether to copy or move an object based on its characteristics, optimizing for performance as needed. */