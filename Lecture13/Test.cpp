#include<iostream>
using namespace std;


int main() {



	int n, x;
	cin >> n >> x;
	int a[10001];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int pre[10001] {0};
	int count = 0;
	pre[0] = a[0];
	int freq[100001] {0};
	freq[a[0]]++;

	for (int i = 1; i < n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}
	// if (freq[x] > 0) {
	// 	count++;
	// }


	//cout << freq[x] << endl;

	for (int i = 0; i < n; i++) {
		int freq[pre[i]]++;
		int uv = pre[i] - x;

		//cout << pre[i] << " " << uv << " " << freq[uv] << endl;
		if (uv >= 0 and freq[uv] > 0) {
			count++;
		}
	}

	cout << count << endl;




}