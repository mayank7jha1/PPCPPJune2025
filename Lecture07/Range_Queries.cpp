#include<iostream>
using namespace std;


int main() {


	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// [0,n-1] : n computations

	//Overall: n*q computations

	//n : [1,10^5]
	//q : [1,10^5]




	int q;
	cin >> q;

	int i = 1;

	while (i <= q) {

		int l, r;
		cin >> l >> r;


		int sum = 0;

		for (int j = l; j <= r; j++) {
			sum += a[j];
		}

		cout << sum << endl;


		q++;
	}








}