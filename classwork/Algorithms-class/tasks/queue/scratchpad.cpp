#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v; // vector to store intelligence levels

void enqueue(int x) {
    v.push_back(x);
    cout << "ok\n";
}

void dequeue() {
    if (v.empty()) {
        cout << "error\n";
    } else {
        cout << v.front() << '\n';
        v.erase(v.begin());
    }
}

void front() {
    if (v.empty()) {
        cout << "error\n";
    } else {
        cout << v.front() << '\n';
    }
}

void size() {
    cout << v.size() << '\n';
}

void clear() {
    v.clear();
    cout << "ok\n";
}

void min() {
    if (v.empty()) {
        cout << "error\n";
    } else {
        int min_val = *min_element(v.begin(), v.end());
        cout << min_val << '\n';
    }
}

int main() {
    string cmd;
    while (cin >> cmd) {
        if (cmd == "enqueue") {
            int x;
            cin >> x;
            enqueue(x);
        } else if (cmd == "dequeue") {
            dequeue();
        } else if (cmd == "front") {
            front();
        } else if (cmd == "size") {
            size();
        } else if (cmd == "clear") {
            clear();
        } else if (cmd == "min") {
            min();
        }
    }
    return 0;
}


/*
In order to get the time complexity o(1) we need to make two stacks and implement the following approach:


    enQueue(q, x): 

        While stack1 is not empty, push everything from stack1 to stack2.
        Push x to stack1 (assuming size of stacks is unlimited).
        Push everything back to stack1.

    Here time complexity will be O(n)

    deQueue(q): 

        If stack1 is empty then error
        Pop an item from stack1 and return it

    Here time complexity will be O(1)


*/