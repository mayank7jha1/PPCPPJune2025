#include<iostream>
using namespace std;
#define MAX 1000

template<typename T>
class Stack {
public:
	T a[MAX];
	int topofstack;//This is the index of the array a.

	Stack() {
		topofstack = -1;
	}

	void push(T x) {

		if (topofstack == MAX) {
			cout << "Stack Overflow " << endl;
			return;
		}

		topofstack++;
		a[topofstack] = x;
	}

	bool empty() {
		if (topofstack == -1) {
			return true;
		} else {
			return false;
		}
	}

	T top() {
		if (topofstack == -1) {
			return -1;
		}
		return a[topofstack];
	}

	void pop() {
		if (topofstack == -1) {
			cout << "Underflow" << endl;
			return;
		}
		topofstack--;
	}

};
