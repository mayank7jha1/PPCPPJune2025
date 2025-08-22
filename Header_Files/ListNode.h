#include<iostream>
using namespace std;

template<typename T>
class ListNode {
public:
	T val;
	ListNode *next;//Self Referencing Pointers.
	// ListNode *prev;

	ListNode() {
		next = NULL;
		// prev = NULL;
	}

	ListNode(int x) {
		val = x;
		next = NULL;
		// prev=NULL;
	}

};
