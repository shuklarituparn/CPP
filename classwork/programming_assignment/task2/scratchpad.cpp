

    // Resizes the vector so that it has new_size elements
    // If new_size is greater than the current size, the new elements are initialized to val
        // Resizes the vector so that it has new_size elements
    // If new_size is greater than the current size, the new elements are initialized to val
    void resize(size_t new_size, const T& val = T()) {
        if (new_size > m_size) {
            reserve(new_size);
            for (size_t i = m_size; i < new_size; ++i) {
                m_data[i] = val;
            }
        }
        m_size = new_size;
    }

    // Adds a new element to the end of the vector
    void push_back(const T& val) {
        if (m_size == m_capacity) {
            reserve(m_capacity == 0 ? 1 : m_capacity * 2);
        }
        m_data[m_size++] = val;
    }

    // Inserts a new element at the specified index in the vector
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

    // Removes all elements from the vector
    void clear() {
        m_size = 0;
    }

private:
    size_t m_size; // Number of elements in the vector
    size_t m_capacity; // Number of elements that the vector can hold
    T* m_data; // Pointer to the dynamically allocated array of elements
};