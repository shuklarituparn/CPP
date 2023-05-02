#include <iostream>
#include <memory>

struct MyClass {
    MyClass() {
        std::cout << "MyClass constructed" << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass destructed" << std::endl;
    }
};

void customDeleter(MyClass* ptr) {
    std::cout << "Custom deleter called" << std::endl;
    delete ptr;
}

int main() {
    std::unique_ptr<MyClass, void(*)(MyClass*)> ptr(new MyClass, customDeleter);

    return 0;
}

/* In C++, a custom deleter is a function object that can be provided to a smart pointer to define the way that it releases the memory it manages. This allows for more flexibility and control over how memory is managed and can be especially useful when dealing with resources that are not managed by the standard C++ library. */

/* In this example, we define a struct MyClass which has a constructor and a destructor that print messages to the console. We then define a custom deleter function customDeleter that takes a pointer to a MyClass object and deletes it using the standard delete operator.

We then create a unique_ptr to a MyClass object, passing both the object and the custom deleter function to the constructor of the unique_ptr. The second template parameter of the unique_ptr specifies the type of the deleter, which in this case is a function pointer to customDeleter.

When the unique_ptr goes out of scope, it will automatically call the custom deleter function to release the memory it manages. In this case, the custom deleter function will be called instead of the default delete operator, and will print a message to the console.

Custom deleters can also be used with other smart pointers, such as shared_ptr and weak_ptr, and can be useful for managing resources such as files, network connections, or other external resources that need to be released in a specific way. */