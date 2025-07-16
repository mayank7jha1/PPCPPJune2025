#include<iostream>
using namespace std;

bool compare(string x, string y) {

	string xy = x + y;
	string yx = y + x;

	if (xy > yx) {
		return true;
	} else {
		return false;
	}
}


int main() {

	// int n;
	// cin >> n;

	// int a[n];

	// for (int i = 0; i < n; i++) {
	// 	cin >> a[i];
	// }

	// sort(a, a + n);
	// reverse(a, a + n);

	// for (int i = 0; i < n; i++) {
	// 	cout << a[i];
	// }


	// //Why this logic also don't work.
	// int n;
	// cin >> n;

	// string a[n];

	// for (int i = 0; i < n; i++) {
	// 	cin >> a[i];
	// }

	// sort(a, a + n);
	// reverse(a, a + n);

	// for (int i = 0; i < n; i++) {
	// 	cout << a[i];
	// }

	int n;
	cin >> n;

	string a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n, compare);
	for (int i = 0; i < n; i++) {
		cout << a[i];
	}









}