#include<iostream>
using namespace std;
int n;
char output[100];

void F(int i, int mx) {

	if (i == n) {
		output[i] = '\0';
		cout << output << endl;
		return;
	}

	for (char ch = 'a'; ch <= mx; ch++) {
		output[i] = ch;
		if (ch == mx) {
			F(i + 1, mx + 1);
		} else {
			F(i + 1, mx);
		}
	}

	return;
}


int main() {
	cin >> n;
	F(0, 'a');
}




