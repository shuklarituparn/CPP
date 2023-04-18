#include <iostream>
#include <stdexcept>

template<typename T>
class MyVector {

private:
    size_t m_size; 
    size_t m_capacity; 
    T* m_data; 
public:
   
    MyVector() : m_size(0), m_capacity(0), m_data(nullptr) {}
    MyVector(size_t size, const T& val = T()) : m_size(size), m_capacity(size), m_data(new T[size]) {
        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = val;
        }
    }
    MyVector(const MyVector& other) : m_size(other.m_size), m_capacity(other.m_capacity), m_data(new T[other.m_capacity]) {
        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }
    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            m_size = other.m_size;
            m_capacity = other.m_capacity;
            delete[] m_data;
            m_data = new T[m_capacity];
            for (size_t i = 0; i < m_size; ++i) {
                m_data[i] = other.m_data[i];
            }
        }
        return *this;
    }
    ~MyVector() {
        delete[] m_data;
    }
    T& operator[](size_t index) {
        if (index >= m_size) {
            throw std::out_of_range("MyVector::operator[] - index out of range");
        }
        return m_data[index];
    }
    const T& operator[](size_t index) const {
        if (index >= m_size) {
            throw std::out_of_range("MyVector::operator[] - index out of range");
        }
        return m_data[index];
    }
    size_t size() const {
        return m_size;
    }
    size_t capacity() const {
        return m_capacity;
    }
    bool empty() const {
        return m_size == 0;
    }
    void reserve(size_t new_capacity) {
        if (new_capacity > m_capacity) {
            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < m_size; ++i) {
                new_data[i] = m_data[i];
            }
            delete[] m_data;
            m_data = new_data;
            m_capacity = new_capacity;
        }
    }
    void resize(size_t new_size, const T& val = T()) {
        if (new_size > m_size) {
            reserve(new_size);
            for (size_t i = m_size; i < new_size; ++i) {
                m_data[i] = val;
            }
        }
        m_size = new_size;
    }
    void push_back(const T& val) {
        if (m_size == m_capacity) {
            reserve(m_capacity == 0 ? 1 : m_capacity * 2);
        }
        m_data[m_size++] = val;
    }
    void insert(size_t index, const T& val) {
        if (index > m_size) {
            throw std::out_of_range("MyVector::insert - index out of range");
        }
        if (m_size == m_capacity) {
            reserve(m_capacity == 0 ? 1 : m_capacity * 2);
        }
        for (size_t i = m_size; i > index; --i) {
            m_data[i] = m_data[i-1];
        }
        m_data[index] = val;
        ++m_size;
    }
    void clear() {
        m_size = 0;
    }
};

int main() {
    
    MyVector<int> vector1; //using the default constructor
    std::cout << "vector1 size: " << vector1.size() << " capacity: " << vector1.capacity() << std::endl; //showing the size and programming 

    MyVector<int> vector2(5, 10);//using the overloaded constructor
    std::cout << "vector2 size: " << vector2.size() << " capacity: " << vector2.capacity() << std::endl;
    for (size_t i = 0; i < vector2.size(); ++i) {
        std::cout << vector2[i] << " ";
    }
    std::cout << std::endl;

 
    MyVector<int> vector3(vector2); //Using the copy constructor
    std::cout << "v3 size: " << vector3.size() << " capacity: " << vector3.capacity() << std::endl;
    for (size_t i = 0; i < vector3.size(); ++i) {
        std::cout << vector3[i] << " ";
    }
    std::cout << std::endl;

    
    MyVector<int> vector4;  // Using the Assignment
    vector4 = vector3;
    std::cout << "v4 size: " << vector4.size() << " capacity: " << vector4.capacity() << std::endl;
    for (size_t i = 0; i < vector4.size(); ++i) {
        std::cout << vector4[i] << " ";
    }
    std::cout << std::endl;

    
    vector4.push_back(20); // push_back method on the vector 
    std::cout << "v4 size: " << vector4.size() << " capacity: " << vector4.capacity() << std::endl;
    for (size_t i = 0; i < vector4.size(); ++i) {
        std::cout << vector4[i] << " ";
    }
    std::cout << std::endl;

    
    vector4.insert(2, 30);// insert method on the vector
    std::cout << "v4 size: " << vector4.size() << " capacity: " << vector4.capacity() << std::endl;
    for (size_t i = 0; i < vector4.size(); ++i) {
        std::cout << vector4[i] << " ";
    }
    std::cout << std::endl;

    
    vector4.clear();//using the clear method
    std::cout << "v4 size: " << vector4.size() << " capacity: " << vector4.capacity() << std::endl;
    

    return 0;
}
