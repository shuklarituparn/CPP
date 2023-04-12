#include <iostream>
#include <vector>

class Person {
public:
    std::string name;
    int age;

    Person(std::string name, int age) {
        this->name = name;
        this->age = age;
    }
};

int main() {
    // Create a vector of Person objects
    std::vector<Person> people = {
        Person("Alice", 25),
        Person("Bob", 30),
        Person("Charlie", 35)
    };

    // Iterate over the vector and display each Person's name and age
    for (const auto& person : people) {
        std::cout << "Name: " << person.name << ", Age: " << person.age << std::endl;
    }

    return 0;
}


/*
In this example, we create a custom class Person with two member variables name and age, and a constructor that takes values for these variables. We then create a vector of Person objects and initialize it with three instances of the class.

To display the information about each person, we use a range-based for loop to iterate over the vector and access the name and age member variables of each Person object. We use the std::cout object to output the information to the console.

Note that we use const auto& as the loop variable type to avoid copying the Person objects unnecessarily.



*/