#include<iostream>
#include<climits>
using namespace std;
#define int long long


int32_t main() {

	int n, t;
	cin >> n >> t;

	int a[n];
	int mini = INT_MAX;

	for (int i = 0; i < n; i++) {
		cin >> a[i];

		if (mini > a[i]) {
			mini = a[i];
		}
	}

	int s = 1, e = mini * t;
	int ans = 0;

	while (s <= e) {

		int mid = (s + e) / 2;

		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += (mid / a[i]);
		}

		if (sum >= t) {
			ans = mid;
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}


	cout << ans << endl;

}