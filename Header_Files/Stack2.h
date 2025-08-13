#include<iostream>

//Implement Stack using 2 queues.
class MyStack {
public:
    std::queue<int> queue1;
    std::queue<int> queue2;
    MyStack() {

    }

    void push(int x) {
        // Enqueue the new element into the non-empty queue
        if (!queue1.empty()) {
            queue1.push(x);
        } else {
            queue2.push(x);
        }
    }

    int pop() {
        // Move elements from the non-empty queue to the empty queue, leaving only the last element
        std::queue<int>& nonEmptyQueue = queue1.empty() ? queue2 : queue1;
        std::queue<int>& emptyQueue = queue1.empty() ? queue1 : queue2;

        while (nonEmptyQueue.size() > 1) {
            emptyQueue.push(nonEmptyQueue.front());
            nonEmptyQueue.pop();
        }

        // Dequeue and return the last element from the non-empty queue
        int popped = nonEmptyQueue.front();
        nonEmptyQueue.pop();
        return popped;
    }


    int top() {
        // Similar to pop, move elements to the empty queue until only the last element remains
        std::queue<int>& nonEmptyQueue = queue1.empty() ? queue2 : queue1;
        std::queue<int>& emptyQueue = queue1.empty() ? queue1 : queue2;

        while (nonEmptyQueue.size() > 1) {
            emptyQueue.push(nonEmptyQueue.front());
            nonEmptyQueue.pop();
        }

        // Return the last element without dequeuing
        int topElement = nonEmptyQueue.front();
        emptyQueue.push(topElement);
        nonEmptyQueue.pop();
        return topElement;
    }

    bool empty() {
        // Return true if both queues are empty, indicating an empty stack; false otherwise
        return queue1.empty() && queue2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */