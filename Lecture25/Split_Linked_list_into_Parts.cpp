#include<iostream>
#include<vector>
using namespace std;


int Length(ListNode* h) {
	int count = 0;

	while (h != NULL) {
		count++;
		h = h->next;
	}
	return count;
}


vector<ListNode*> splitListToParts(ListNode* root, int k) {
	int n = Length(root);
	ListNode*head = root;
	int ME = (n / k);
	int EE = (n % k);
	vector<ListNode*>ans;
	int count = 1;

	if (ME == 0) {
		// k > n
		for (int i = 1; i <= k; i++) {
			if (head != NULL) {
				ListNode*n = head->next;
				head->next = NULL;
				ans.push_back(head);
				head = n;
			} else {
				ans.push_back(NULL);
			}
		}

	} else {

		//n>=k

		while (head != NULL) {
			ans.push_back(head);
			int x = 0;
			if (EE > 0) {
				x = 1;
			}
			EE--;

			for (int i = 1; i < ME + x; i++) {
				head = head->next;
			}

			ListNode*n = head->next;
			head->next = NULL;
			head = n;

			count++;

			if (count == k) {
				//You are trying to fill the last part.
				ans.push_back(head);
				break;
			}
		}

	}

	return ans;
}

int main() {



}