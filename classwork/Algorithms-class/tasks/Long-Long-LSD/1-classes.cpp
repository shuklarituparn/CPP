#include <iostream>
#include <vector>
#include <cmath>

// Class representing LSD sort with medians of medians
class LSDSort {
private:
    std::vector<int> arr;  // Input array
    int digits;            // Number of digits in the maximum element

    // Function to find the median of a vector
    int findMedian(std::vector<int>& vec) {
        insertionSort(vec); // Using insertion sort to find the median
        return vec[vec.size() / 2];
    }

    // Function to perform partitioning using medians of medians
    int partition(int low, int high, int pivot) {
        int pivotIndex;
        for (pivotIndex = low; pivotIndex < high; pivotIndex++) {
            if (arr[pivotIndex] == pivot)
                break;
        }
        swap(arr[pivotIndex], arr[high]);

        int i = low;
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[high]);
        return i;
    }

    // Recursive function to perform LSD sort with medians of medians
    void lsdSort(int low, int high, int digit) {
        if (low < high && digit >= 0) {
            std::vector<int> bucket(10, 0); // 10 buckets for digits 0-9

            // Partition using median of medians as pivot
            int medianIndex = low + (high - low) / 2;
            int medianValue = findMedian(arr);
            int pivot = partition(low, high, medianValue);

            // Recursive calls on each bucket
            for (int i = 0; i < 10; i++) {
                int nextDigit = digit - 1;
                int bucketLow = low;
                int bucketHigh = high;

                // Find the range for the current bucket
                for (int j = low; j <= high; j++) {
                    int currentDigit = (arr[j] / static_cast<int>(std::pow(10, digit))) % 10;
                    if (currentDigit < i) {
                        bucketLow++;
                    } else if (currentDigit > i) {
                        bucketHigh--;
                    }
                }

                // Sort the elements in the current bucket
                lsdSort(bucketLow, bucketHigh, nextDigit);
            }
        }
    }

    // Function to swap two elements
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Function to perform insertion sort
    void insertionSort(std::vector<int>& vec) {
        int n = vec.size();
        for (int i = 1; i < n; i++) {
            int key = vec[i];
            int j = i - 1;
            while (j >= 0 && vec[j] > key) {
                vec[j + 1] = vec[j];
                j--;
            }
            vec[j + 1] = key;
        }
    }

public:
    // Constructor
    LSDSort(std::vector<long long int>& input) : arr(input) {
        int maxElement = 0;
        for (int num : arr) {
            if (num > maxElement)
                maxElement = num;
        }
        digits = static_cast<long long int>(std::log10(maxElement) + 1);
    }

    // Function to perform LSD sort with medians of medians
    void sort() {
        lsdSort(0, arr.size() - 1, digits - 1);
    }

    // Function to get the sorted array
    std::vector<long long int> getSortedArray() {
        return arr;
    }
};

// Function to print a vector
void printVector(const std::vector<long long int>& arr) {
    for (long long num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Main function
int main(int argc, char* argv[]) {
    std::vector<long long int> arr;

    if (argc < 2) {
        std::cout << "Usage: ./lsd_sort <element1> <element2> <element3> ..." << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        arr.push_back(std::atoll(argv[i]));
    }

    std::cout << "Original array: ";
    printVector(arr);

    LSDSort lsd(arr);
    lsd.sort();

    std::cout << "Sorted array: ";
    printVector(lsd.getSortedArray());

    return 0;
}
