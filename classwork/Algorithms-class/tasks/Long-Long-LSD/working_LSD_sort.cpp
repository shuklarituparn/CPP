//
// Created by rituparn on 24.05.23.
//
#include <cstdint>
#include <iostream>

class LSDRadixSort {
public:
    static void Sort(long long* arr, int size) {
        const int kBits = 64;
        const int kRadix = 10;

        long long* temp[kRadix];
        for (auto& i : temp) {
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

        for (auto& i : temp) {
            delete[] i;
        }
    }
};

void PrintArray(const long long* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << "\n";
    }
}

int main() {
    int num_inputs;
    std::cin >> num_inputs;

    auto* arr = new long long[num_inputs];

    for (int i = 0; i < num_inputs; ++i) {
        std::cin >> arr[i];
    }

    LSDRadixSort::Sort(arr, num_inputs);
    PrintArray(arr, num_inputs);

    delete[] arr;

    return 0;
}
