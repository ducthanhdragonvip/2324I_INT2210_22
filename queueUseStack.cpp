#include <iostream>
#include <stack>

using namespace std;

class QueueUsingStack {
private:
    stack<int> stack1, stack2;

public:
    void enqueue(int value) {
        stack1.push(value);
    }

    int dequeue() {
        if (empty()) {
            cout << "Queue is empty!" << endl;
            return -1; 
        }

        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        int frontValue = stack2.top();
        stack2.pop();
        return frontValue;
    }

    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    QueueUsingStack queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Front element: " << queue.dequeue() << endl;

    queue.enqueue(4);

    cout << "Front element after enqueue: " << queue.dequeue() << endl;

    return 0;
}
