#include<iostream>
using namespace std;
#define MAX 1000

template<typename T>
class Queue {

public:
	T * a;
	int front;
	int back;

	int cs;
	int ts;

	Queue() {
		a = new T[MAX];
		front = back = -1;
		cs = 0;
		ts = MAX;
	}

	Queue(int size) {
		a = new T[size];
		front = back = -1;
		cs = 0;
		ts = size;
	}

	void push(T x) {

		if (cs == ts) {
			return;
		}

		if (cs == 0) {
			front = 0;
		}

		back = (back + 1) % ts;
		a[back] = x;
		cs++;
	}

	void pop() {

		if (cs == 0) {
			return;
		}

		if (cs == 1) {
			front = back = -1;
		} else {
			front = (front + 1) % ts;
		}

		cs--;
	}

	T front1() {
		return a[front];
	}

	bool empty() {
		if (cs == 0) {
			return true;
		} else {
			return false;
		}
	}
};