#include <iostream>
#include <iostream>
#include <string>

template <typename T>
size_t calculate_size(const T& arg) {
  return sizeof(arg);
}

size_t calculate_size(const std::string& str) {
  return sizeof(str[0]) * str.size() + sizeof(str);
}

template <typename T, typename... Args>
size_t calculate_size(const T& arg, const Args&... args) {
  return calculate_size(arg) + calculate_size(args...);
}

int main() {
  int x;
  std::cout << "\nEnter the integer: ";
  std::cin >> x;

  double y;
  std::cout << "\nEnter a double: ";
  std::cin >> y;

  std::string s;
  std::cout << "\nEnter a string: ";
  std::cin >> s;

  size_t total_size = calculate_size(x, y, s);
  std::cout << "Total size: " << total_size << std::endl;
  return 0;
}


