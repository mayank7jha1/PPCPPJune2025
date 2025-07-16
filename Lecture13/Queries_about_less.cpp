#include<iostream>
using namespace std;


int main() {

	int n, m;
	cin >> n >> m;

	int a[100001], b[100001];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	sort(a, a + n);

	for (int i = 0; i < m; i++) {
		cout << upper_bound(a, a + n, b[i]) - a << " ";
	}


}