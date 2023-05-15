#include <vector>
#include <iostream>

class FenwickTree {
private:
    std::vector<int> tree;

    // Computes the parent index of a given index
    int getParent(int index) {
        return index - (index & -index);
    }

    // Computes the next index that should be updated after a given index
    int getNext(int index) {
        return index + (index & -index);
    }

public:
    // Constructor that initializes the Fenwick tree with an array of values
    FenwickTree(std::vector<int>& values) {
        int n = values.size();
        tree.resize(n + 1);

        for (int i = 1; i <= n; i++) {
            update(i, values[i - 1]);
        }
    }

    // Updates the value at a given index in the Fenwick tree
    void update(int index, int delta) {
        int n = tree.size() - 1;

        while (index <= n) {
            tree[index] += delta;
            index = getNext(index);
        }
    }

    // Computes the sum of values from 1 to a given index in the Fenwick tree
    int sum(int index) {
        int result = 0;

        while (index > 0) {
            result += tree[index];
            index = getParent(index);
        }

        return result;
    }

    // Computes the sum of values from a given index to another given index in the Fenwick tree
    int rangeSum(int start, int end) {
        return sum(end) - sum(start - 1);
    }
};

int main() {
    // Initialize an array of values
    std::vector<int> values = {1, 3, 2, 5, 6, 4};

    // Create a FenwickTree object with the array of values
    FenwickTree tree(values);

    // Update the value at index 3 to 4
    tree.update(3, 4);

    // Retrieve the sum of values from 1 to index 4
    std::cout << "Prefix sum from 1 to 4: " << tree.sum(4) << std::endl;

    // Retrieve the sum of values from index 2 to index 5
    std::cout << "Sum from index 2 to 5: " << tree.rangeSum(2, 5) << std::endl;

    return 0;
}