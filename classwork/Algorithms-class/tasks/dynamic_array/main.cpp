#include <iostream>
class vector {

private:
  int *data_;
  int capacity_;
  int size_;

public:
  vector();
  ~vector();
  void push_(int input);
  void pop_();
  void at_(int index);
  void resize_(int NewCapacity);
  int get_size_() const { return size_; }
  int get_capacity_() const { return capacity_; }
  void clear_();
  void exit_();
};

int main() {
  vector Vector;
  std::string input;
  while (std::cin >> input) {
    if (input == "push") {
      int value;
      std::cin >> value;
      Vector.push_(value);

    } else if (input == "pop") {
      Vector.pop_();
    } else if (input == "at") {
      int index;
      std::cin >> index;
      Vector.at_(index);
    } else if (input == "resize") {
      int newCapacity;
      std::cin >> newCapacity;
      Vector.resize_(newCapacity);
    } else if (input == "size") {
      std::cout << Vector.get_size_() << std::endl;
    } else if (input == "capacity") {
      std::cout << Vector.get_capacity_() << std::endl;
    } else if (input == "clear") {
      Vector.clear_();
    } else if (input == "exit") {
      std::cout << "bye" << std::endl;
      break;
    }
  }
  return 0;
}

vector::vector() {
  capacity_ = 1;
  size_ = 0;
  data_ = new int[capacity_];
}
void vector::push_(int input) {
  if (capacity_ == size_) {

    capacity_ = capacity_ * 2;
    data_[size_++] = input;
    std::cout << "ok" << std::endl;

  } else {
    data_[size_] = input;
    size_++;
    std::cout << "ok" << std::endl;
    // std::cout<<"error: Increase capacity";
  }
}
void vector::pop_() {
  if (size_ == 0) {
    std::cout << "error" << std::endl;
    return;
  }
  std::cout << data_[--size_] << std::endl;
  if (size_ <= capacity_/2) {
    int new_capacity = capacity_/2;
    int *new_data = new int[new_capacity];
    for (int i = 0; i < size_; i++) {
      new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
}
}
void vector::at_(int index) {
  if (index < 0 || index >= size_) {
    std::cout << "error" << std::endl;
  } else {
    std::cout << data_[index] << std::endl;
  }
}
void vector::resize_(int newCapacity) {
  int *newData = new int[newCapacity];

  int newSize = (size_< newCapacity) ? size_ : newCapacity;
  for (int i = 0; i < newSize; i++) {
    newData[i] = data_[i];
  }

  delete[] data_;
  data_ = newData;
  capacity_ = newCapacity;
  size_ = newSize;

  std::cout << "ok" << std::endl;
}
void vector::clear_() {
  delete[] data_;
  size_ = 0;
  capacity_ = 1;
  data_ = new int[capacity_];
  std::cout << "ok" << std::endl;
}

vector::~vector() { delete[] data_; }