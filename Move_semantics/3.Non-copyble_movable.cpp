#include <iostream>
#include <future>

// A function that returns a future object
std::future<int> get_result() {
    // ...
}

int main() {
    std::future<int> f = get_result(); // create a non-copyable but movable object
    // ...
    return 0;
}

/* In this example, we create a std::future object, which is non-copyable but movable. This allows us to transfer ownership of the future object to another object, such as a callback function that will be executed when the future's result becomes available. */