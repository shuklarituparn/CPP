//
// Created by rituparn on 24.05.23.
//

#include <cstdint>
#include <iostream>
#include <vector>

class LSDRadixSort {

public:
    long long *arr;
    int size;
public:
    static void Sort(long long* arr, int size) {
        const int kBits = 64;
        const int kRadix = 10;

        long long* temp[kRadix];
        for (auto & i : temp) {
            i = new long long[size];
        }

        for (int i = 0; i < kBits; i++) {
            int counts[kRadix] = {0};

            for (int j = 0; j < size; j++) {
                int64_t digit = (arr[j] >> i) & 1;
                temp[digit][counts[digit]++] = arr[j];
            }

            int index = 0;
            for (int j = 0; j < kRadix; j++) {
                for (int k = 0; k < counts[j]; k++) {
                    arr[index++] = temp[j][k];
                }
            }
        }

        for (auto & i : temp) {
            delete[] i;
        }
    }

void Data(int num_inputs){
        size=num_inputs;
        arr= new long long [size];

    for (int i = 0; i < size; ++i) {
        std::cin>>arr[i];
    }
    }
};

void PrintArray(const long long* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] <<"\n";
    }
}

int main() {
    int num_inputs;
    std::cin >> num_inputs;

    auto* arr = new long long[num_inputs];

    for (int i = 0; i < num_inputs; ++i) {
        std::cin >> arr[i];
    }

    LSDRadixSort::Sort(arr, num_inputs);
    PrintArray(arr, num_inputs);

    delete[] arr;

    return 0;
}

/*
 * Static Member Function: When a member function is declared as static, it means that the function belongs to the
 * class itself rather than an instance of the class. Static member functions can be called using the class name
 * without creating an object of the class. They don't have access to the instance-specific data members and can
 * only access other static members of the class.

    Static Member Variable: A static member variable is shared among all the instances of a class. It exists
    independently of any class instance, and all the objects of the class share the same copy of the static member
    variable. Static member variables must be defined outside the class declaration to allocate memory for them.
 */