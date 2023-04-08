//
// Created by rituparn on 07.04.23.
//


#include <iostream>
class vector {

private:
  int *data;
  int capacity;
  int size;

public:
  vector();
  void push(int input);
  void pop();
  void at(int index);
  void resize(int NewCapacity);
  int size_() const {return size;}
  int capacity_() const{return capacity;}
  //int get_capacity(){return capacity;}
  void clear();
  void exit();
};

int main() {
  vector Vector;
  std::string input;
  while (std::cin >> input) {
    if (input == "push") {
     int value;
     std::cin >> value;
     Vector.push(value);
    
    } 
    else if (input == "pop") {
      Vector.pop();
    } else if (input == "at") {
      int index;
      std::cin >> index;
      Vector.at(index);
    } 
    else if (input == "resize") {
      int newCapacity;
      std::cin >> newCapacity;
      Vector.resize(newCapacity);
    } else if (input == "size") {
      std::cout<<Vector.size_()<<std::endl;
    } else if (input == "capacity") {
      std::cout<<Vector.capacity_()<<std::endl;
    } else if (input == "clear") {
      Vector.clear();
    } else if (input == "exit") {
      std::cout<<"bye"<<std::endl;
      break;
    }
  }
  return 0;
}

vector::vector(){
    capacity=1;
    size=0;
    data= new int[capacity];

}
void vector::push(int input){
    if (capacity==size) {

      capacity=capacity*2;
      data[size++]=input;
      std::cout<<"ok"<<std::endl;  


    }
    else {
      data[size]= input;
      size++;
      std::cout<<"ok"<<std::endl;  
        //std::cout<<"error: Increase capacity";
    }
}
void vector::pop(){}
void vector::at(int index){}
void vector::resize(int NewCapacity){}
void vector::clear(){}
