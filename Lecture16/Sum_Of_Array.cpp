#include<iostream>
using namespace std;
int n;
int a[10001];

/*

	RFS(i): Sum of Array from i to n - 1 index;
	RFS(i) = a[i] + RFS(i + 1);
	RFS(n - 1) = a[n - 1];
	RFS(n) = 0;
*/

int RFS(int i) {
	//Currently I am Solving for state: F(i):

	if (i == n - 1) {
		return a[n - 1];
	}

	int ans = a[i] + RFS(i + 1);
	return ans;
}

int RFE(int i) {
	//Currently I am Solving for state: F(i):

	if (i == 0) {
		return a[0];
	}

	int ans = a[i] + RFE(i - 1);
	return ans;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << RFS(0) << endl;
	cout << RFE(n - 1) << endl;
}