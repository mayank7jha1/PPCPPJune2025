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


//This solve function is there for iteration only and that too for end pointer.

ListNode<int>*start = NULL;
bool stop = 0;
template<typename T>
void Solve(ListNode<T>*end, int left, int right) {

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

template<typename T>
ListNode<T>* reverseBetween(ListNode<T>* head, int left, int right) {
	start = head;
	Solve(head, left, right);
	return head;
}


template<typename T>
void Cycle_Creation(ListNode<T>*head) {

	if (head == NULL or head->next == NULL) {
		//This Linked List cannot have a cycle.
		return;
	}

	//Reach to the tail.
	ListNode<T>*tail = head;
	while (tail->next != NULL) {
		tail = tail->next;
	}

	tail->next = head->next->next;
}

template<typename T>
bool IsCycle(ListNode<T>*head) {

	ListNode<T>*slow = head;
	ListNode<T>*fast = head;

	while (fast != NULL and fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow) {
			return true;
		}
	}

	return false;
}

template<typename T>
void Break_Cycle(ListNode<T>*head) {

	if (IsCycle(head) == 0) {
		return;
	}

	ListNode<T>*slow = head;
	ListNode<T>*fast = head;

	while (fast != NULL and fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow) {
			break;
		}
	}

	slow = head;
	ListNode<T>*prev = head;
	while (prev->next != fast) {
		prev = prev->next;
	}

	while (fast != slow) {
		fast = fast->next;
		slow = slow->next;
		prev = prev->next;
	}

	// while (prev->next != fast) {
	// 	prev = prev->next;
	// }

	prev->next = NULL;

	//Printing the cycle:
	while (fast != NULL) {
		cout << fast->val << "-->";
		fast = fast->next;
	}

	cout << "NULL" << endl;
}


template < typename T>
bool isPalindrome(ListNode<T>* head) {

	//For 0 length Linked List and 1 length Linked List.
	if (head == NULL or head->next == NULL) {
		return true;
	}

	ListNode<T>*M = MidPoint3(head);//Logic Based on First Mid Point of In Case of Even Linked List
	ListNode<T>*Sh = M->next;
	M->next = NULL;

	ReverseLLIteratively(Sh);

	while (Sh != NULL) {
		if (head->val != Sh->val) {
			return false;
		}

		head = head->next;
		Sh = Sh->next;
	}

	return true;
}


template<typename T>
void reorderList(ListNode<T>* head) {

	ListNode<T>*h1 = head;
	ListNode<T>*M = MidPoint2(head);//Logic Based on Second Mid Point of In Case of Even Linked List
	ListNode<T>*h2 = M->next;
	M->next = NULL;

	ReverseLLIteratively(h2);

	//Merging:
	ListNode<T>*x, *y;
	while (h2 != NULL) {

		x = h1->next;
		y = h2->next;

		h1->next = h2;
		h1 = x;
		h2->next = h1;
		h2 = y;
	}

}


template<typename T>
ListNode<T>* partition(ListNode<T>* head, int x) {

	ListNode<T>*n = NULL, *bh = NULL, *bt = NULL, *ch = NULL, *ct = NULL;

	//Task: To Create two new Linked list :
	while (head != NULL) {

		n = head->next;

		if (head->val < x) {
			//This node will be part of chota linked list.

			if (ct == NULL) {
				//This means my chota linked list is empty till now.
				ch = ct = head;
				//Break:
				head->next = NULL;
				head = n;

			} else {
				//This means my chota linked list is not empty.
				ct->next = head;
				ct = head;
				head->next = NULL;
				head = n;

			}


		} else {
			//This node will be part of bigger linked list.

			if (bt == NULL) {
				//My bigger linked list is empty.
				bh = bt = head;
				//Break
				head->next = NULL;
				head = n;
			} else {

				bt->next = head;
				bt = head;
				head->next = NULL;
				head = n;

			}

		}

	}


	if (ct != NULL) {
		ct->next = bh;
		return ch;

	} else {
		return bh;
	}
}

template<typename T>
ListNode<T>* oddEvenList(ListNode<T>* head) {

	if (head == NULL or head->next == NULL) {
		return head;
	}

	ListNode<T>*evenhead = head->next;
	ListNode<T>*oddhead = head;

	ListNode<T>*current = head, *n = NULL, *prev = NULL;
	int jump = 1;//Ye batayega ki aapki linked list odd length ki thi ya even.

	while (current != NULL and current->next != NULL) {
		n = current->next;
		current->next = n->next;
		prev = current;
		current = n;
		jump++;

	}

	if (jump % 2 == 1) {
		current->next = evenhead;
	} else {
		prev->next = evenhead;
	}

	return oddhead;

}



