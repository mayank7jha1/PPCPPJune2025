#include<iostream>
using namespace std;


int main() {

	int n, t;
	cin >> n >> t;

	int a[100001] {0};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int s = 0;
	int tc = 0;

	int maxi = INT_MIN;

	for (int e = 0; e < n; e++) {

		//Expansion
		tc += a[e];

		//Shrinking:
		while (s <= e and tc > t) {
			tc -= a[s];
			s++;
		}

		int count = e - s + 1;
		if (maxi < count) {
			maxi = count;
		}

	}

	cout << maxi << endl;
}




