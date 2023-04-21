#include <iostream>

class Vector {
public:
    Vector() {
        capacity = 1;
        size = 0;
        data = new int[capacity];
    }

    ~Vector() {
        delete[] data;
    }

    void push(int value) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        data[size++] = value;
        else{
         return 1;
        }
    }

    void pop() {
        if (size == 0) {
            std::cout << "error" << std::endl;
            return;
        }
        std::cout << data[--size] << std::endl;
    }

    void at(int index) {
        if (index < 0 || index >= size) {
            std::cout << "error" << std::endl;
            return;
        }
        std::cout << data[index] << std::endl;
    }

    void resize(int newCapacity) {
        int* newData = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
        std::cout << "ok" << std::endl;
    }

    void clear() {
        delete[] data;
        size = 0;
        capacity = 1;
        data = new int[capacity];
        std::cout << "ok" << std::endl;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }

private:
    int* data;
    int capacity;
    int size;
};

int main() {
    Vector vector;
    std::string command;
    while (std::cin >> command) {
        if (command == "push") {
            int value;
            std::cin >> value;
            vector.push(value);
        } else if (command == "pop") {
            vector.pop();
        } else if (command == "at") {
            int index;
            std::cin >> index;
            vector.at(index);
        } else if (command == "resize") {
            int newCapacity;
            std::cin >> newCapacity;
            vector.resize(newCapacity);
            std::cout<<"ok"<<std::endl;
        } else if (command == "size") {
            std::cout << vector.getSize() << std::endl;
        } else if (command == "capacity") {
            std::cout << vector.getCapacity() << std::endl;
        } else if (command == "clear") {
            vector.clear();
        } else if (command == "exit") {
            std::cout << "bye" << std::endl;
            break;
        }
    }
    return 0;
}
