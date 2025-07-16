#include<iostream>
using namespace std;


int main() {
	int n, x;
	cin >> n >> x;
	int a[1001];
	int pre[1001] {0};

	//I want to check i se pehle pre[i]-x
	//vala koi element pre[i] me hain.
	for (int i = 0; i < n; i++) {
		cin >> a[i];

		if (i > 0) {
			pre[i] = pre[i - 1] + a[i];
		} else {
			pre[i] = a[i];
		}
	}

	int freq[10001] {0};
	freq[0] = 1;//Because same concept subarray
	//zero vala.

	int count = 0;

	for (int i = 0; i < n; i++) {
		//Pre[i]
		int check = pre[i] - x;

		if (check >= 0 and freq[check] >= 0) {
			//Kuch kaam karna hain.
			//I now have a subarray.
			count += freq[check];
		}

		//Frequency array me current element ko
		// daal do
		if (pre[i] >= 0) {
			freq[pre[i]]++;
		}
	}

	cout << count << endl;
}
