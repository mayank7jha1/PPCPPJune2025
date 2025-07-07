#include<iostream>
using namespace std;


int main() {

	int n;
	cin >> n;

	int a[n];
	int mini = INT_MAX;
	int maxi = INT_MIN;

	for (int i = 0; i < n; i++) {
		cin >> a[i];

		if (a[i] > maxi) {
			maxi = a[i];
		}

		if (a[i] < mini) {
			mini = a[i];
		}
	}

	// int freq[maxi - mini + 1] {0};
	int freq[100001] {0};

	for (int i = 0; i < n; i++) {
		int ele = a[i];
		int shifted_ele = a[i] - mini;
		freq[shifted_ele]++;
	}

	for (int i = 0; i < maxi - mini + 1; i++) {

		if (freq[i] > 0) {
			int shifted_ele = i;
			int original_ele = i + mini;
			cout << original_ele << " " << freq[i] << endl;
		}

	}






}