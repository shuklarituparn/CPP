//
// Created by rituparn on 28.05.23.
//

#include <iostream>
#include <unordered_set>

class Set {
private:
    std::unordered_set<int> set_;

public:
    void Add(int number) { set_.insert(number); }

    void Remove(int number) { set_.erase(number); }

    bool Contains(int number) { return set_.find(number) != set_.end(); }
};

int main() {
    Set set;

    char operation;
    int number;

    int queries;
    std::cin >> queries;

    while (queries != 0) {
        std::cin >> operation >> number;

        if (operation == '+') {
            set.Add(number);
        } else if (operation == '-') {
            set.Remove(number);
        } else if (operation == '?') {
            if (set.Contains(number)) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        }
        queries--;
    }

    return 0;
}
