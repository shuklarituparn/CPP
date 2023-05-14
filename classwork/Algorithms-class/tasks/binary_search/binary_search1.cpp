#include <iostream>

bool BinarySearch(const int* begin, const int* end, int target) {
    const int* left = begin;//pointer to the beginning of the array
    const int* right = end - 1; //pointer to the end of the array. end-1 as end is the null terminator

    while (left <= right) {//runs till the beginning of the array is larger thsn the end
        const int* mid = left + (right - left) / 2; //creating a pointer to the mid of the array
        if (*mid == target) { //if the middle element is the target then return true
            return true;
        } else if (*mid < target) { //if the middle element is smaller than the target then 
            left = mid + 1; //as the left was before the beginning of the array, so we shit it to the right 
        } else {
            right = mid - 1; //as the right was the end of the array, so we shit it to the left of the middle element
        }
    }

    return false; //return false if the element not found
}
int main() {
    int n;
    std::cin >> n;

    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
/*
A loop is used to read in n integers from the standard input, which are stored in the a array.
*/
    int q;
    std::cin >> q;

    /*
    Another integer q is read in from the standard input, which represents the number of queries to perform on the array.
    */

    for (int i = 0; i < q; i++) {
        int l, r, t;
        std::cin >> l >> r >> t;

        bool found = BinarySearch(a + l, a + r, t);
        std::cout << (found ? "YES" : "NO") << std::endl;
    }

    /*
    A loop is used to perform q queries on the array. In each iteration of the loop, three integers l, r, and t are read in from the standard input, which represent the range [l, r) to search within the array for the target value t. The BinarySearch function is called with the appropriate parameters, and the result is printed to the standard output using std::cout. The ternary operator (found ? "YES" : "NO") is used to print either "YES" or "NO" depending on whether the target was found.
    */

    delete[] a;
    return 0;
}
