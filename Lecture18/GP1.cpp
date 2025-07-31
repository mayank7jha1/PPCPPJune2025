#include<iostream>
using namespace std;
char output[100];
int count1 = 0;
int n;

void F(int i) {

	if (i == 2 * n) {
		output[i] = '\0';
		cout << output << endl;
		count1++;
		return;
	}


	//Put the '(' at this index.
	output[i] = '(';
	F(i + 1);

	//Put the ')' at this index.
	output[i] = ')';
	F(i + 1);

	return;
}


int main() {

	cin >> n;

	F(0);
	cout << count1 << endl;
}