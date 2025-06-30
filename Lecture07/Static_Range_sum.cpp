#include<iostream>
using namespace std;


int main() {

	int n, q;
	cin >> n >> q;
	long long int  pre[100001] {0};

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (i == 0) {
			pre[i] = x;
		} else {
			pre[i] = pre[i - 1] + x;
		}
	}



	int i = 1;

	while (i <= q) {

		long long int l, r;
		cin >> l >> r;
		l--;
		r--;

		if (l == 0) {
			cout << pre[r] << endl;
		} else {
			cout << pre[r] - pre[l - 1] << endl;
		}


		i++;
	}

	// C : 1 2 3 4
	// U : 0 1 2 3
	// A : 9 8 7 5

	// 1 3








}