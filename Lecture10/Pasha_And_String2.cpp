#include<iostream>
using namespace std;
const int N = 200007;

int main() {

	char s[N];
	cin >> s;

	int len = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		len++;
	}

	int m;
	cin >> m;

	int i = 1;

	int diff[N] {0};

	while (i <= m) {

		int l;
		cin >> l;
		l--;//Because 0 based indexing.
		diff[l]++;

		//You don't need to write this:
		// diff[r + 1]--;

		i++;
	}

	//Take prefix of difference array.


	for (int i = 1; i < len; i++) {
		diff[i] = diff[i - 1] + diff[i];
	}

	// for (int i = 0; i < len; i++) {
	// 	cout << diff[i] << " ";
	// }

	// cout << endl;

	// diff[0] = diff[0];
	// diff[1] = diff[1] + diff[0];
	// diff[2] = diff[1] + diff[2];

	//Swap ka logic:

	for (int i = 0; i < len / 2; i++) {
		if ((diff[i] % 2) == 1) {
			//swap the current index with its adj. element of pair.
			char temp = s[i];
			s[i] = s[len - i - 1];
			s[len - i - 1] = temp;
		}
	}

	cout << s << endl;






}