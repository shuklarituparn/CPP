#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_N = 1000005; // maximum number of freshmen

int a[MAX_N]; // array to store intelligence levels
int n = 0; // number of freshmen currently remembered

void enqueue(int x) {
    a[n++] = x;
    cout << "ok\n";
}

void dequeue() {
    if (n == 0) {
        cout << "error\n";
    } else {
        cout << a[0] << '\n';
        for (int i = 1; i < n; i++) {
            a[i - 1] = a[i];
        }
        n--;
    }
}

void front() {
    if (n == 0) {
        cout << "error\n";
    } else {
        cout << a[0] << '\n';
    }
}

void size() {
    cout << n << '\n';
}

void clear() {
    n = 0;
    cout << "ok\n";
}

void min() {
    if (n == 0) {
        cout << "error\n";
    } else {
        int min_val = *min_element(a, a + n);
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


/* This implementation uses an array a to store the intelligence levels, and n to keep track of how many freshmen are currently remembered. The enqueue function appends a new intelligence level to the end of the array, and increments n. The dequeue function removes the first element of the array (i.e., the oldest remembered freshman), shifts all remaining elements to the left, and decrements n. The front function simply prints the first element of the array. The size function prints n. The clear function resets n to 0. The min function finds the minimum intelligence level using the min_element function from the <algorithm> library.

Note that this implementation assumes that the input is well-formed (i.e., each enqueue command is followed by an integer argument, and there are no extra arguments).
 */