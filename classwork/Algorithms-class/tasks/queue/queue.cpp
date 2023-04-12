#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Queue {
private:
    string* arr;
    int front, rear, size;

public:
    Queue(int maxSize) {
        arr = new string[maxSize];
        front = -1;
        rear = -1;
        size = maxSize;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear == size - 1);
    }

    void enqueue(string x) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }

    string peek() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return "";
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }
        for_each(arr + front, arr + rear + 1, [](string s){ cout << s << " "; });
        cout << endl;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q(5);

    q.enqueue("2");
    q.enqueue("World");
    q.enqueue("How");
    q.enqueue("Are");
    q.enqueue("You");
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    cout << "Front element is: " << q.peek() << endl;

    return 0;
}
