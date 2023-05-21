#include <iostream>
#include <stack>
#include <stdexcept> // Include the exception header

using namespace std;

class Queue {
private:
    stack<int> e_stk;
    stack<int> d_stk;
    stack<int> min_stk; // new stack to track minimum elements

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
    if (min_stk.empty() || x <= min_stk.top()) {
        min_stk.push(x);
    }
}

int Queue::dequeue() {
    if (d_stk.empty()) {
        if (e_stk.empty()) {
            throw runtime_error("error"); // Throw exception when dequeueing an empty queue
        } else {
            while (!e_stk.empty()) {
                d_stk.push(e_stk.top());
                e_stk.pop();
            }
        }
    }
    int x = d_stk.top();
    d_stk.pop();

    if (x == min_stk.top()) {
        min_stk.pop();
    }
    return x;
}

int Queue::front() {
    if (d_stk.empty()) {
        if (e_stk.empty()) {
            throw runtime_error("Queue is empty"); // Throw exception when accessing the front of an empty queue
        } else {
            while (!e_stk.empty()) {
                d_stk.push(e_stk.top());
                e_stk.pop();
            }
        }
    }
    return d_stk.top();
}

int Queue::size() {
    return e_stk.size() + d_stk.size();
}

void Queue::clear() {
    while (!e_stk.empty()) {
        e_stk.pop();
    }
    while (!d_stk.empty()) {
        d_stk.pop();
    }
    while (!min_stk.empty()) {
        min_stk.pop();
    }
}

int Queue::min() {
    if (min_stk.empty()) {
        throw runtime_error("Queue is empty"); // Throw exception when finding the minimum element of an empty queue
    }
    return min_stk.top();
}

int main() {
    Queue q;
    string cmd;
    while (cin >> cmd) {
        try {
            if (cmd == "enqueue") {
                int x;
                cin >> x;
                q.enqueue(x);
                cout << "ok" << endl;
            } else if (cmd == "dequeue") {
                cout << q.dequeue() << endl;
            } else if (cmd == "front") {
                cout << q.front() << endl;
            } else if (cmd == "size") {
                cout << q.size() << endl;
            } else if (cmd == "clear") {
                q.clear();
                cout << "ok" << endl;
            } else if (cmd == "min") {
                cout << q.min() << endl;
            } else {
                break;
            }
        } catch (const exception& e) {
            cout<<e.what() << endl;
        }
    }
    return 0;
}
