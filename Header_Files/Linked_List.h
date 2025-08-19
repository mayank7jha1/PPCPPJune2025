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

template<typename T>
T MidPoint1(ListNode<T>*head) {

	int len = Length(head);
	len /= 2;

	while (len > 0) {
		head = head->next;
		len--;
	}

	return head->val;
}


//Second Mid Point in case of Even Length LL.
template<typename T>
ListNode<T>* MidPoint2(ListNode<T>*head) {

	ListNode<T>*slow = head;
	ListNode<T>*fast = head;

	while (fast != NULL and fast->next != NULL) {
		// fast = fast->next;
		// fast = fast->next;
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}


//First Mid Point in case of Even Length LL.
template<typename T>
ListNode<T>* MidPoint3(ListNode<T>*head) {

	ListNode<T>*slow = head;
	ListNode<T>*fast = head->next;

	while (fast != NULL and fast->next != NULL) {
		// fast = fast->next;
		// fast = fast->next;
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}

template<typename T>
void ReverseLLIteratively(ListNode<T>*&head) {

	ListNode<T>*current = head;
	ListNode<T>*prev = NULL;
	ListNode<T>*n;

	while (current != NULL) {
		n = current->next;
		current->next = prev;
		prev = current;
		current = n;
	}

	head = prev;
}


template<typename T>
ListNode<T>* ReverseLLRecursively(ListNode<T>*head) {

	if (head == NULL or head->next == NULL) {
		return head;
	}


	ListNode<T>*reversed_head = ReverseLLRecursively(head->next);

	//Task
	head->next->next = head;
	head->next = NULL;

	return reversed_head;
}

//We are reversing the actual nodes.
template<typename T>
ListNode<T>* reverseBetween(ListNode<T>* head, T left, T right) {

	if (left == right) {
		return head;
	}

	ListNode<T>*prev = NULL;
	ListNode<T>*current = head;

	for (int i = 1; i < left; i++) {
		prev = current;
		current = current->next;
	}

	/*
		prev is at left-1 position
		current is at left position.
	*/

	ListNode<int>*start = prev;
	ListNode<int>*end = current;
	ListNode<int>*n = current->next;

	for (int i = 0; i < right - left + 1; i++) {
		current->next = prev;
		prev = current;
		current = n;
		//My current and n are at the same point.
		//Baad me update kar raha hu main n ko.
		if (n != NULL) {
			n = current->next;
		}
	}

	//Connect the edge points:
	if (start != NULL) {
		start->next = prev;
	} else {
		head = prev;
	}

	end->next = current;
	return head;
}


//We are now reversing the values using recursion.
template<typename T>

//This solve function is there for iteration only and that too for end pointer.
ListNode<T>*start = nullptr;
bool stop = 0;

void Solve(ListNode<int>*end, T left, T right) {

	if (right == 1) {
		return;
	}

	end = end->next;
	if (left > 1) {
		start = start->next;
	}

	Solve(end, left - 1, right - 1);

	//Task:
	if (end == start or end->next == start) {
		stop = 1;
	}

	//Swap
	if (stop == 0) {
		swap(end->val, start->val);
		start = start->next;
	}

	return;
}


ListNode<T>* reverseBetween(ListNode<T>* head, T left, T right) {
	start = head;
	Solve(head, left, right);
	return head;
}



