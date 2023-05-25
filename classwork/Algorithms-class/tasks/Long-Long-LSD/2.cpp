#include <iostream>
#include <vector>
#include <cmath>

// Class representing LSD sort with medians of medians
class LSDSort {
private:
    std::vector<long long int> arr;  // Input array
    int digits;                     // Number of digits in the maximum element

    // Function to find the median of a vector
    long long int findMedian(std::vector<long long int>& vec) {
        insertionSort(vec); // Using insertion sort to find the median
        return vec[vec.size() / 2];
    }

    // Function to perform partitioning using medians of medians
    long long int partition(long long int low, long long int high, long long int pivot) {
        long long int pivotIndex;
        for (pivotIndex = low; pivotIndex < high; pivotIndex++) {
            if (arr[pivotIndex] == pivot)
                break;
        }
        swap(arr[pivotIndex], arr[high]);

        long long int i = low;
        for (long long int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[high]);
        return i;
    }

    // Recursive function to perform LSD sort with medians of medians
    void lsdSort(long long int low, long long int high, int digit) {
        if (low < high && digit >= 0) {
            std::vector<long long int> bucket(10, 0); // 10 buckets for digits 0-9

            // Partition using median of medians as pivot
            long long int medianIndex = low + (high - low) / 2;
            long long int medianValue = findMedian(arr);
            long long int pivot = partition(low, high, medianValue);

            // Recursive calls on each bucket
            for (int i = 0; i < 10; i++) {
                int nextDigit = digit - 1;
                long long int bucketLow = low;
                long long int bucketHigh = high;

                // Find the range for the current bucket
                for (long long int j = low; j <= high; j++) {
                    long long int currentDigit = (arr[j] / static_cast<long long int>(std::pow(10, digit))) % 10;
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
    void swap(long long int& a, long long int& b) {
        long long int temp = a;
        a = b;
        b = temp;
    }

    // Function to perform insertion sort
    void insertionSort(std::vector<long long int>& vec) {
        long long int n = vec.size();
        for (long long int i = 1; i < n; i++) {
            long long int key = vec[i];
            long long int j = i - 1;
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
        long long int maxElement = 0;
        for (long long int num : arr) {
            if (num > maxElement)
                maxElement = num;
        }
        digits = static_cast<int>(std::log10(maxElement) + 1);
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
    for (long long int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    int numInputs;
    std::cin >> numInputs;

    std::vector<long long int> arr;
    arr.resize(numInputs);

    for (int i = 0; i < numInputs; ++i) {
        std::cin >> arr[i];
    }

    LSDSort lsdSort(arr);
    lsdSort.sort();
    std::vector<long long int> sortedArr = lsdSort.getSortedArray();
    printVector(sortedArr);


    return 0;
}
