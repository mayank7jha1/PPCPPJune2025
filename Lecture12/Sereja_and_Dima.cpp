#include<iostream>
using namespace std;


int main() {

	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	int s = 0, e = n - 1;

	int sp = 0, dp = 0;
	int turn = 1;

	while (s <= e) {

		if (turn % 2 == 1) {
			//This turn is for sereja
			if (a[s] > a[e]) {
				sp += a[s];
				s++;
			} else {
				sp += a[e];
				e--;
			}

		} else {
			//This turn is for dima.
			if (a[s] > a[e]) {
				dp += a[s];
				s++;
			} else {
				dp += a[e];
				e--;
			}

		}

		turn++;

	}

	cout << sp << " " << dp << endl;

}