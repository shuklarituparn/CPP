#include <iostream>
#include <stdexcept>

template<typename T>
class Stack {
private:
    T* data;
    std::size_t capacity;
    std::size_t topIndex;

public:
    Stack(std::size_t capacity): capacity(capacity), topIndex(-1) {
        data = new T[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    void push(const T& element) {
        if (topIndex == capacity - 1) {
            throw std::overflow_error("Stack is full");
        }
        topIndex++;
        data[topIndex] = element;
    }

    void pop() {
        if (topIndex == -1) {
            throw std::underflow_error("Stack is empty");
        }
        topIndex--;
    }

    const T& top() const {
        if (topIndex == -1) {
            throw std::underflow_error("Stack is empty");
        }
        return data[topIndex];
    }

    bool empty() const {
        return topIndex == -1;
    }
};

int main() {
    std::size_t capacity;
    std::cout << "Enter stack capacity: ";
    std::cin >> capacity;

    Stack<int> stack(capacity);
    std::string input;

    while (std::cin >> input) {
        try {
            if (input == "push") {
                int value;
                std::cin >> value;
                stack.push(value);
            } else if (input == "pop") {
                stack.pop();
            } else if (input == "top") {
                std::cout << stack.top() << std::endl;
            } else if (input == "empty") {
                std::cout << std::boolalpha << stack.empty() << std::endl;
            } else {
                std::cout << "Invalid input" << std::endl;
            }
        } catch (const std::exception& exception) {
            std::cerr << "Error: " << exception.what() << std::endl;
        }
    }

    return 0;
}
