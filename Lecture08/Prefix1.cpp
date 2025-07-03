#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	//n*q : 10^10: 100 sec
	int q;
	cin >> q;
	int i = 1;
	while (i <= q) {

		int l, r, value;
		cin >> l >> r >> value;
		for (int j = l; j <= r; j++) {
			a[j] += value;
		}

		i++;
	}

	for (int j = 0; j < n; j++) {
		cout << a[j] << " ";
	}

}