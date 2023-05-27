#include <iostream>
#include <vector>

class SortingAlgorithm {
public:
    virtual void sort(std::vector<int>& arr, int low, int high) = 0;
};

class Quicksort : public SortingAlgorithm {
public:
    void sort(std::vector<int>& arr, int low, int high) override {
        if (low < high) {
            if (high - low + 1 <= 256) {
                insertionSort(arr, low, high);
            } else {
                int pivotIndex = partition(arr, low, high);
                sort(arr, low, pivotIndex);
                sort(arr, pivotIndex + 1, high);
            }
        }
    }

private:
    int partition(std::vector<int>& arr, int low, int high) {
        int pivot = arr[(low + high) / 2];
        int left = low;
        int right = high;

        while (true) {
            while (arr[left] < pivot) {
                left++;
            }
            while (arr[right] > pivot) {
                right--;
            }
            if (left >= right) {
                break;
            }
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }

        return right;
    }

    void insertionSort(std::vector<int>& arr, int low, int high) {
        for (int i = low + 1; i <= high; ++i) {
            int key = arr[i];
            int j = i - 1;
            while (j >= low && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
};

int main() {
    int N;
    std::cin >> N;

    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    Quicksort quicksort;
    quicksort.sort(arr, 0, N - 1);

    for (int i = 0; i < N; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
