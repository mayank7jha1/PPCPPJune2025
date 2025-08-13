#include<iostream>
#include"..\Header_Files\ListNode.h"
using namespace std;


template<typename T>
void InsertAtHead(ListNode<T>*&h, int data) {
	ListNode<T>*n = new ListNode<T>(data);
	// (*n).next = head;
	n->next = h;
	h = n;
	return;
}


template<typename T>
void Print(ListNode<T>*head) {
	while (head != NULL) {
		cout << head->val << " ---> ";
		head = head->next;
	}
	cout << "NULL" << endl;

	// ListNode<T>*temp = head;
	// while (temp != NULL) {
	// 	cout << temp->val << " ---> ";
	// 	temp = temp->next;
	// }

	// cout << "NULL" << endl;
}

template<typename T>
int Length(ListNode<T>*head) {

	int ans = 0;
	while (head != NULL) {
		ans++;
		head = head->next;
	}
	return ans;
}

template<typename T>
int SearchInLL(ListNode<T>*head, int target) {
	while (head != NULL) {
		if (head->val == target) {
			return true;
		}
		head = head->next;
	}
	return false;
}


template<typename T>
bool SearchInLLRecursively(ListNode<T>*head, int target) {
	if (head == NULL) {
		return false;
	}

	if (head->val == target) {
		return true;
	}

	return SearchInLLRecursively(head->next, target);
}








