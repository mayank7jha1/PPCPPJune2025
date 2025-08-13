#include<iostream>
using namespace std;

template<typename T>
class ListNode {
public:
	T val;
	ListNode *next;//Self Referencing Pointers.

	ListNode() {
		next = NULL;
	}

	ListNode(int x) {
		val = x;
		next = NULL;
	}

};