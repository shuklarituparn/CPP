#include <iostream>
#include <sstream>
#include <utility>
#include <type_traits>
#include <stdexcept>

class Printer {
public:
    template<typename T>
    void print(T&& arg)
    {
        printSingleArg(std::forward<T>(arg));
        std::cout << std::endl;
    }

    template<typename T, typename... Args>
    void print(T&& arg, Args&&... args)
    {
        printSingleArg(std::forward<T>(arg));
        std::cout << ", ";
        print(std::forward<Args>(args)...);
    }

private:
    template<typename T>
    void printSingleArg(T&& arg)
    {
        if constexpr (std::is_same_v<std::decay_t<T>, std::string>) {
            printStringArg(std::forward<T>(arg));
        } else {
            printOtherArg(std::forward<T>(arg));
        }
    }

    void printStringArg(const std::string& arg)
    {
        std::cout << arg;
    }

    template<typename T>
    void printOtherArg(T&& arg)
    {
        std::ostringstream oss;
        oss << std::to_string(std::forward<T>(arg));
        std::cout << oss.str();
    }
};

int main()
{
    Printer printer;

    std::cout << "Enter an integer: ";
    int num;
    std::cin >> num;

    std::cout << "Enter a floating-point number: ";
    double pi;
    std::cin >> pi;

    std::cout << "Enter a string: ";
    std::string message;
    std::cin.ignore(); // Ignore the newline character
    std::getline(std::cin, message);

    try {
        printer.print(num, pi, message);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
