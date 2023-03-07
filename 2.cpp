#include <iostream>

using namespace std;
//void print(const int *const array, size_t size);
//int *apply_all(const int *const array1, size_t size1, const int *const array2, size_t size2);

int main() {
   size_t size_array_1{0};
   size_t size_array_2{0};

    cout<<"Enter the size of the first array: ";
    cin>>size_array_1;

    size_t array1[size_array_1];

    for (size_t i {0}; i < size_array_1; i++)
    {
        cin>>array1[i];
    }
    
    cout<<"Enter the size of the second array: ";
    cin>>size_array_2;

   size_t array2[size_array_2];

    for (size_t i = 0; i < size_array_2; i++)
    {
        cin>>array2[i];
    }

    for (size_t i = 0; i < size_array_1; i++)
    {
        cout<<array1[i];
    }
    for (size_t i = 0; i < size_array_2; i++)
    {
        cout<<array2[i];
    }

    return 0;


}