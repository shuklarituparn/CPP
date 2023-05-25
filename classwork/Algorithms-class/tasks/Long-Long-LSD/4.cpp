//
// Created by rituparn on 25.05.23.
//

//
// Created by rituparn on 24.05.23.
//

#include <cstdint>
#include <iostream>
#include <vector>

class LSDRadixSort {

public:
    long long *arr;
    int size;
public:
    LSDRadixSort() : arr(nullptr), size(0) {}
    ~LSDRadixSort(){delete [] arr;}
    void Sort() {
        const int kBits = 64;
        const int kRadix = 10;

        long long* temp[kRadix];
        for (auto & i : temp) {
            i = new long long[size];
        }

        for (int i = 0; i < kBits; i++) {
            int counts[kRadix] = {0};

            for (int j = 0; j < size; j++) {
                int64_t digit = (arr[j] >> i) & 1;
                temp[digit][counts[digit]++] = arr[j];
            }

            int index = 0;
            for (int j = 0; j < kRadix; j++) {
                for (int k = 0; k < counts[j]; k++) {
                    arr[index++] = temp[j][k];
                }
            }
        }

        for (auto & i : temp) {
            delete[] i;
        }
    }

    void Data(int num_inputs){
        size=num_inputs;
        arr= new long long [size];

        for (int i = 0; i < size; ++i) {
            std::cin>>arr[i];
        }
    }
    void PrintArray() {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] <<"\n";
        }
}


};

int main() {
    int num_inputs;
    std::cin >> num_inputs;
    LSDRadixSort lsdRadixSort;
    lsdRadixSort.Data(num_inputs);
    lsdRadixSort.Sort();
    lsdRadixSort.PrintArray();




    return 0;
}
