#include<iostream>
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

	int freq[10001] {0};
	freq[0] = 1;

	for (int i = 0; i < n; i++) {

		int element = a[i];
		freq[element]++;
	}


	int count_subarrays = 0;


	//We are iterating over the freq array apart from
	//0 index.
	for (int i = 0; i <= maxi; i++ ) {
		//Current element is i and its freq is freq[i]
		int x = freq[i];
		count_subarrays += ((x * (x - 1)) / 2);
	}

	cout << count_subarrays << endl;







}





