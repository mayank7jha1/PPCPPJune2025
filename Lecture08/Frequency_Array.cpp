#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int freq[100] {0};
	for (int i = 0; i < n; i++) {
		int element = a[i];

		freq[element]++;
	}


	for (int i = 0; i < 100; i++) {
		if (freq[i] > 0) {
			cout << i << "--->" << freq[i] << endl;
		}
	}

}






