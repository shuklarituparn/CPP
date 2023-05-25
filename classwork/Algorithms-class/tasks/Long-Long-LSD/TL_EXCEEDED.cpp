#include <iostream>
#include <vector>

class LSDRadixSort {
public:
    static void Sort(std::vector<long long>& arr) {
        const int kBits = 64; // Number of bits in a long-long integer
        const int kRadix = 2; // Radix for binary digits

        for (int i = 0; i < kBits; i++) {
            std::vector<int64_t> temp[kRadix];

            // Group elements based on the i-th bit
            for (long long j : arr) {
                int64_t digit = (j >> i) & 1;
                temp[digit].push_back(j);
            }

            // Merge the groups back into the original array
            int index = 0;
            for (auto& j : temp) {
                for (long long k : j) {
                    arr[index++] = k;
                }
            }
        }
    }
};

// Function to print an array
void PrintArray(const std::vector<long long>& arr) {
    for (long long i : arr) {
        std::cout << i << std::endl;
    }
}

int main() {
    int num_inputs;
    std::cin >> num_inputs;

    std::vector<long long> arr;
    arr.resize(num_inputs);

    for (int i = 0; i < num_inputs; ++i) {
        std::cin >> arr[i];
    }

    LSDRadixSort::Sort(arr);
    PrintArray(arr);

    return 0;
}
