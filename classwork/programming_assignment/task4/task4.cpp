#include <iostream>

template<typename T>
struct add_const {
  typedef const T type;
};
template<typename T>
struct add_const<const T> {
  typedef const T type;
};

template<typename T>
struct remove_const{
  typedef T type ;
};

template<typename T>
struct remove_const<const T>{
  typedef T type ;
};

int main() {
  add_const<int>::type constInt = 45; 
  remove_const<const int>::type nonConstInt = constInt; 
 
  // check if constInt is const
  bool constIntIsConst = std::is_same<decltype(constInt), const int>::value;

  if (constIntIsConst) {
    std::cout << "constInt is const." << std::endl;
  } else {
    std::cout << "constInt is not const." << std::endl;
  }

  // check if nonConstInt is const
  bool nonConstIntIsConst = std::is_same<decltype(nonConstInt), const int>::value;

  if (nonConstIntIsConst) {
    std::cout << "nonConstInt is const." << std::endl;
  } else {
    std::cout << "nonConstInt is not const." << std::endl;
  }

  return 0;
}
