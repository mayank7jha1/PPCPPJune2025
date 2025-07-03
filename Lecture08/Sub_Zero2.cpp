#include<iostream>
#include<climits>
using namespace std;


int main() {
	int n;
	cin >> n;
	int a[100001] {0};

	int maxi = INT_MIN;


	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0) {
			continue;
		} else {
			a[i] = a[i - 1] + a[i];
		}

		if (maxi < a[i]) {
			maxi = a[i];
		}
	}

	int freq[maxi + 1] {0};

	for (int i = 0; i < n; i++) {

		int element = a[i];
		freq[element]++;
	}


	for (int i = 1; i <= maxi; i++) {
		if (freq[i] > 1) {
			cout << "YES" << endl;
			return 0;
		}
	}

	if (freq[0] > 0) {
		cout << "YES" << endl;
		return 0;
	}

	cout << "NO" << endl;

}