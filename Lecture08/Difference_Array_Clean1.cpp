#include<iostream>
using namespace std;


int main() {
	int n;
	cin >> n;

	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int difference[100001] {0};

	int q;
	cin >> q;
	int i = 1;

	while (i <= q) {

		int l, r, value;
		cin >> l >> r >> value;
		difference[l] += value;
		difference[r + 1] -= value;

		i++;
	}

	for (int i = 1; i < n; i++) {
		difference[i] = difference[i - 1] + difference[i];
	}

	for (int i = 0; i < n; i++) {
		a[i] = a[i] + difference[i];
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}


}




