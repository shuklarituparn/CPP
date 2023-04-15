#include <iostream>
#include <vector>
#include <string>

template<typename... Args>
size_t size_of_args(Args&&... args) {
    return (sizeof(args) + ...);
}

int main() {
    std::vector<std::string> inputs;
    std::string input;
    std::cout << "Enter input (enter empty line to stop):\n";
    while (std::getline(std::cin, input) && !input.empty()) {
        inputs.push_back(input);
    }
    std::cout << "Total size of arguments: " << size_of_args(inputs.size(), inputs) << '\n';
    return 0;
}
