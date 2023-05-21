#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Queue {
private:
    stack<int> e_stk;
    stack<int> d_stk;

public:
    Queue() {}
    ~Queue() {}

    void enqueue(int x);
    int dequeue();
    int front();
    int size();
    bool empty();
    void clear();
    int min(); 
};

void Queue::enqueue(int x) {
    e_stk.push(x);
}

int Queue::dequeue() {
    int x = -1;
    if (d_stk.empty()) {
        if (e_stk.empty()) {
            cout << "Queue Underflow" << endl;
            return x;
        } else {
            while (!e_stk.empty()) {
                d_stk.push(e_stk.top());
                e_stk.pop();
            }
        }
    }
    x = d_stk.top();
    d_stk.pop();
    return x;
}

int Queue::front() {
    int x = -1;
    if (d_stk.empty()) {
        if (e_stk.empty()) {
            cout << "Queue is empty" << endl;
            return x;
        } else {
            while (!e_stk.empty()) {
                d_stk.push(e_stk.top());
                e_stk.pop();
            }
        }
    }
    x = d_stk.top();
    return x;
}

int Queue::size() {
    return e_stk.size() + d_stk.size();
}

bool Queue::empty() {
    return e_stk.empty() && d_stk.empty();
}

void Queue::clear() {
    while (!e_stk.empty()) {
        e_stk.pop();
    }
    while (!d_stk.empty()) {
        d_stk.pop();
    }
}

int Queue::min() {
    if (empty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    stack<int> temp = d_stk;
    while (!temp.empty()) {
        e_stk.push(temp.top());
        temp.pop();
    }
    int minimum = *min_element(e_stk.begin(), e_stk.end());
    while (!e_stk.empty()) {
        temp.push(e_stk.top());
        e_stk.pop();
    }
    while (!temp.empty()) {
        d_stk.push(temp.top());
        temp.pop();
    }
    return minimum;
}

int main() {
    Queue q;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "enqueue") {
            int x;
            cin >> x;
            q.enqueue(x);
        } else if (cmd == "dequeue") {
            cout << q.dequeue();
        } else if (cmd == "front") {
            cout << "Front element: " << q.front() << endl;
        } else if (cmd == "size") {
            cout << "Queue size: " << q.size() << endl;
        } else if (cmd == "empty") {
            if (q.empty()) {
                cout << "Queue is empty" << endl;
            } else {
                cout << "Queue is not empty" << endl;
            }
        } else if (cmd == "clear") {
            q.clear();
            cout << "Queue cleared" << endl;
        } else if (cmd == "min") {
            cout << "Minimum element: " << q.min() << endl;
        } else {
            cout << "Invalid command" << endl;
        }
    }
    return 0;
}
