#include<iostream>
using namespace std;
#define int long long


int32_t main() {

	int n, m;
	cin >> n >> m;

	if (n <= m) {
		cout << n << endl;
		return 0;
	}

	//This is for finding the value of k.
	int s = 0, e = 1e10;
	int ans = -1;
	while (s <= e) {
		int mid = (s + e) / 2;

		int value = n - m;
		int check = (mid * (mid + 1)) / 2;

		if (check >= value) {
			ans = mid;
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}

	cout << ans + m << endl;

	// int m;
	// int current_day = 1;

	// while (grains >= 0) {
	// 	grains = grains - current_day;
	// 	if (grains <= 0) {
	// 		break;
	// 	}
	// 	current_day++;
	// 	grains = grains + m;
	// }

	// cout << current_day << endl;






}