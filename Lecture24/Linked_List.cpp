#include<iostream>
#include"..\Header_Files\Linked_List.h"
#include<forward_list>//Singly Linked List
#include<list>//Doubly Linked List
using namespace std;


int main() {

	int n;
	cin >> n;

	//Initialised using constructor.
	ListNode<int>* head = NULL;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		//Insert the current data in your linked list.
		InsertAtHead(head, x);
	}

	Print(head);
	Print(head);
	cout << Length(head) << endl;
	cout << SearchInLL(head, 12) << endl;
	cout << SearchInLLRecursively(head, 12) << endl;
	cout << MidPoint1(head) << endl;

	ListNode<int>*mid = MidPoint2(head);
	cout << mid->val << endl;

	cout << MidPoint3(head)->val << endl;
	ReverseLLIteratively(head);
	Print(head);

	ListNode<int>*head1 = ReverseLLRecursively(head);
	Print(head1);

}