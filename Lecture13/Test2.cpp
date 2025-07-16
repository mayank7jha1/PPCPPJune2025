#include<iostream>
using namespace std;


int main() {

	char ch[15];
	cin >> ch;
	int count = 0;
	int n = strlen(ch);

	for (int i = 2; i < n - 2; i++) {
		if (ch[i] == 'C') {
			count++;
		}
	}

	if (ch[0] != 'A') {
		cout << "WA" << endl;
		return 0;
	}

	if (count > 1) {
		cout << "WA" << endl;
		return 0;
	}

	for (int i = 1; i < n; i++) {
		if (ch[i] <= 'a' and ch[i] >= 'z') {
			cout << "WA" << endl;
			return 0;
		}
	}

	cout << "AC" << endl;







}