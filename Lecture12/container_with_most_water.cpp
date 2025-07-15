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
	int maxi = INT_MIN;
	int area = 0;

	while (s <= e) {

		if (a[e] < a[s]) {
			area = (e - s) * a[e];
			e--;
		} else {
			area = (e - s) * a[s];
			s++;
		}

		if (maxi < area) {
			maxi = area;
		}

	}

	cout << maxi << endl;

}