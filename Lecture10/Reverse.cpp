#include<iostream>
using namespace std;


int main() {

	char s[10001];
	cin >> s;

	int len = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		len++;
	}

	//Reverse Printing
	for (int i = len - 1; i >= 0; i--) {
		cout << s[i];
	}

	cout << endl;

	//Method 2: Using a Seperate Array.
	char rs[10001];
	for (int i = 0; i < len; i++) {
		rs[i] = s[len - i - 1];
	}

	for (int i = 0; i < len; i++) {
		cout << rs[i];
	}
	cout << endl;

	cout << rs << endl;

	//Method 3: Original Character Array me hi karna hain.
	for (int i = 0; i < len / 2; i++) {
		char temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}

	cout << s << endl;












}