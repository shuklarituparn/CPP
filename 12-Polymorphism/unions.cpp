/*
Unions are a C++ language feature that allow for multiple members of different types to occupy the same memory location. This means that a single union variable can be interpreted as multiple different types, depending on which member is accessed. Here are some common uses of unions in C++:

    Representing different data types: Unions can be used to represent multiple data types within a single memory location. For example, a union could be used to represent an integer, a float, and a character string all at once.

    Type punning: Type punning is the practice of using the same memory location to represent different data types. Unions can be used for type punning because they allow you to access the same memory location using different types. For example, you could use a union to reinterpret a block of memory as a different data type.

    Efficient storage of data: Unions can be used to efficiently store data by minimizing the amount of memory required. Since only one member of a union can be accessed at a time, you can use unions to represent a range of different types in a small amount of memory.

    Interoperability with C: Unions are a feature of both C and C++, making them useful for interoperability between the two languages. For example, a C++ program could use a union to represent a C data structure, allowing it to interface with a C library.

    Bit manipulation: Unions can be used for bit manipulation by representing different bit patterns within a single memory location. This can be useful for low-level programming tasks such as working with hardware or optimizing performance.

Overall, unions are a useful tool for representing multiple data types in a flexible and efficient way. However, they can be tricky to use correctly, so it's important to understand their limitations and be careful when working with them.

*/

#include <iostream>
#include <cstring>

union Data {
    int i;
    float f;
    char str[20];
};


int main() {
    Data data;

    data.i = 42;
    std::cout << data.i << std::endl; // Output: 42

    data.f = 3.14;
    std::cout << data.f << std::endl; // Output: 3.14

    strcpy(data.str, "Hello, world!");
    std::cout << data.str << std::endl; // Output: Hello, world!
}

//In the above code the member of the memory access the same memory location so everytime they are called they overwrite the memory location with a new data