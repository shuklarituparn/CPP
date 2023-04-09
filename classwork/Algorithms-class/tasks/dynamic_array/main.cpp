#include <iostream>
class Vector {

private:
  int *data_;
  int capacity_;
  int size_;

public:
  Vector();
  ~Vector();
  void Push(int input);
  void Pop();
  void At(int index);
  void Resize(int NewCapacity);
  int GetSize() const { return size_; }
  int GetCapacity() const { return capacity_; }
  void Clear();
  void Exit();
};

int main() {
  Vector Vector1;
  std::string input;
  while (std::cin >> input) {
    if (input == "push") {
      int value;
      std::cin >> value;
      Vector1.Push(value);
      std::cout << "ok" << std::endl;

    } else if (input == "pop") {
      if (Vector1.GetSize() == 0) {
        std::cout << "error" << std::endl;
      } else {
        Vector1.Pop();
      }

    } else if (input == "at") {
      int index;
      std::cin >> index;
      Vector1.At(index);

    } else if (input == "resize") {
      int newCapacity;
      std::cin >> newCapacity;
      Vector1.Resize(newCapacity);
      std::cout << "ok" << std::endl;
    } else if (input == "size") {
      std::cout << Vector1.GetSize() << std::endl;
    } else if (input == "capacity") {
      std::cout << Vector1.GetCapacity() << std::endl;
    } else if (input == "clear") {
      Vector1.Clear();
      std::cout << "ok" << std::endl;
    } else if (input == "exit") {
      std::cout << "bye" << std::endl;
      break;
    }
  }
  return 0;
}

Vector::Vector() {
  capacity_ = 1;
  size_ = 0;
  data_ = new int[capacity_];
}
void Vector::Push(int input) {
  if (capacity_ == size_) {

    Resize(capacity_ * 2); 
    data_[size_++] = input;

  } else {
    data_[size_] = input;
    size_++;
  }
}
void Vector::Pop() {

  int removed = data_[size_ - 1];
  size_--;
  if (size_ <= capacity_ / 2 && capacity_ > 1) {
    Resize(capacity_ / 2);
  }
  std::cout << removed << std::endl;
}

void Vector::At(int index) {
  if (index < 0 || index >= size_) {
    std::cout << "error" << std::endl;
  } else {
    std::cout << data_[index] << std::endl;
  }
}
void Vector::Resize(int newCapacity) {
  int *newData = new int[newCapacity];

  int newSize = (size_ < newCapacity) ? size_ : newCapacity;
  for (int i = 0; i < newSize; i++) {
    newData[i] = data_[i];
  }

  delete[] data_;
  data_ = newData;
  capacity_ = newCapacity;
  size_ = newSize;
}
void Vector::Clear() {
  delete[] data_;
  size_ = 0;
  capacity_ = 1;
  data_ = new int[capacity_];
}

Vector::~Vector() { delete[] data_; }