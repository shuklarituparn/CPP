/*

Make an array that takes the size of the array as the template argument and return the size of the array

*/

#include<iostream>
#include <string>

template <typename T, int N>
class Array {
    int size {N};         
    T values[N];        
    friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr) {
        os << "[ ";
        for (const auto &val: arr.values)
            os << val << " ";
        os << "]" << std::endl;
        return os;
    }
public:
    Array() = default;
    Array(T init_val) {
        for (auto &item: values)
            item = init_val;
    }
    void fill(T val) {
        for (auto &item: values )
            item = val;
    }
    int get_size() const {
        return size;
    }
    // overloaded subscript operator for easy use
    T &operator[](int index) {
        return values[index];
    }
};

int main() {
    
    Array<int, 5> nums;
    std::cout << "The size of nums is: "<< nums.get_size() << std::endl;
    std::cout << nums << std::endl;

}