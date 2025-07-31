#include<iostream>
using namespace std;
char output[100];
int count1 = 0;
int n;

void F(int i, int oc, int cc) {

	if (i == 2 * n) {
		output[i] = '\0';
		cout << output << endl;
		count1++;
		return;
	}

	//Put the ')' at this index.
	if (cc < oc) {
		output[i] = ')';
		F(i + 1, oc, cc + 1);
	}

	//Put the '(' at this index.
	if (oc < n) {
		output[i] = '(';
		F(i + 1, oc + 1, cc);
	}

	return;
}


int main() {

	cin >> n;
	F(0, 0, 0);
	//cout << count1 << endl;
}


