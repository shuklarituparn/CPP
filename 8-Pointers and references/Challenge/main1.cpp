  
#include <iostream>

using namespace std;
void print(const int *const array, size_t size);
int *apply_all(const int *const array1, size_t size1, const int *const array2, size_t size2);

int main() {
    size_t array1_size {0};
    size_t array2_size {0};

    cout<<"Enter the size of the first array: ";
    cin>>array1_size;

    int array1[array1_size];

    for (size_t i {0}; i < array1_size; i++)
    {
        cin>>array1[i];
    }
    int array2[array2_size];

    for (size_t i {0}; i < array2_size; i++)
    {
        cin>>array1[i];
    }
    
    cout << "Array 1: " ;
    print(array1,array1_size);
    
    cout << "Array 2: " ;
    print(array2,array2_size);
    
    int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size {array1_size * array2_size};

    cout << "Result: " ;
    print(results, results_size);
    
    delete [] results;
    cout << endl;

    return 0;
}
void print(const int *const array, size_t size){

  for (size_t i {0}; i <size; ++i) //If we use "<=" it'll overshoot and give error
  {
    cout<<(array[i])<<" ";
  }
cout<<endl;

}
int *apply_all(const int *const array1, size_t size1, const int *const array2, size_t size2){

int position {0};
int *new_storage{nullptr};
new_storage= new int [size1*size2];

for(size_t i {0}; i<=size1; ++i){

  for(size_t j{0}; j<=size2; ++j){

    new_storage[position]= array2[j]*array1[i];
    position++;  
  }

}
return new_storage;
}
