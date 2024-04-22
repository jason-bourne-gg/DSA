#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    static const int MAX_SIZE = 100;
    vector<int> data;
    int top;

public:
    Stack() : top(-1), data(MAX_SIZE) {}

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        data[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1; // or throw an exception
        }
        return data[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1; // or throw an exception
        }
        return data[top];
    }
};

int main() {
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.pop() << endl; // Output: 3
    cout << s.pop() << endl; // Output: 2

    s.push(4);

    cout << s.peek() << endl; // Output: 4

    return 0;
}
