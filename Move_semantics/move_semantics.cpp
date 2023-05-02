#include <iostream>
#include <cstring>
 
class MyString {
public:
    MyString() : data(nullptr), len(0) {}
 
    // Constructor
    MyString(const char* s) {
        len = strlen(s);
        data = new char[len + 1];
        strcpy(data, s);
    }
 
    // Copy constructor
    MyString(const MyString& other) {
        len = other.len;
        data = new char[len + 1];
        strcpy(data, other.data);
    }
 
    // Move constructor
    MyString(MyString&& other) noexcept {
        len = other.len;
        data = other.data;
        other.len = 0;
        other.data = nullptr;
    }
 
    // Destructor
    ~MyString() {
        delete[] data;
    }
 
    // Assignment operator
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] data;
            len = other.len;
            data = new char[len + 1];
            strcpy(data, other.data);
        }
        return *this;
    }
 
    // Move assignment operator
    MyString& operator=(MyString&& other) noexcept {
        if (this != &other) {
            delete[] data;
            len = other.len;
            data = other.data;
            other.len = 0;
            other.data = nullptr;
        }
        return *this;
    }
 
private:
    char* data;
    size_t len;
};
 
int main() {
    MyString str1("Hello");
    MyString str2(std::move(str1)); // move constructor
 
    MyString str3("World");
    str2 = std::move(str3); // move assignment operator
 
    return 0;
}
