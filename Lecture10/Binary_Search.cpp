#include<iostream>
using namespace std;


int main() {
	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int key;
	cin >> key;

	int ans = n;
	int s = 0, e = n - 1;

	while (s <= e) {

		int mid = (s + e) / 2;
		if (a[mid] == key) {
			ans = mid;
			break;
		} else if (a[mid] > key) {
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}

	cout << ans << endl;




}