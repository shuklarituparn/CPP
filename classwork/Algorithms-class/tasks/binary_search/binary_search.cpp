#include <iostream>

bool BinarySearch(const int* begin, const int* end, int target) {
    const int* left = begin;
    const int* right = end - 1;

    while (left <= right) {
        const int* mid = left + (right - left) / 2;
        if (*mid == target) {
            return true;
        } else if (*mid < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

int main() {
    int n;
    std::cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        int l, r, t;
        std::cin >> l >> r >> t;

        bool found = BinarySearch(a + l, a + r, t);
        std::cout << (found ? "YES" : "NO") << std::endl;
    }

    return 0;
}
