#include<iostream>
using namespace std;


class MyQueue {
public:
    std::stack<int> stack1;
    std::stack<int> stack2;

    MyQueue() {

    }

    void push(int x) {
        stack1.push(x);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        // Dequeue the element from the top of stack2, simulating a dequeue operation
        int popped = stack2.top();
        stack2.pop();
        return popped;
    }

    int peek() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        // Peek at the top element of stack2, providing the element at the front of the queue without dequeuing
        return stack2.top();
    }

    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */