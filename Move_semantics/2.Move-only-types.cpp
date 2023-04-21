#include <iostream>
#include <mutex>

int main() {
    std::unique_lock<std::mutex> lock(std::mutex()); // create a move-only object
    // ...
    return 0;
}
/* In this example, we create a std::unique_lock object, which is move-only. This allows us to ensure that the mutex is always locked by a single object at a time, and by moving it instead of copying it, we can transfer ownership of the lock to another object */