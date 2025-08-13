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

}