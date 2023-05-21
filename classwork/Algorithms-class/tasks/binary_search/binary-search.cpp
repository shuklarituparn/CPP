#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Target not found
}

int main() {
    std::vector<int> arr = {2,4,6,8,10,12,14};
    int target = 8;

    int result = binarySearch(arr, target);

    if (result != -1) {
        std::cout << "Target found at index " << result << std::endl;
    } else {
        std::cout << "Target not found" << std::endl;
    }

    return 0;
}
