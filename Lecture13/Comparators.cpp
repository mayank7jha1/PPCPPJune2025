#include<iostream>
using namespace std;

bool comp(int x, int y) {
	if (x > y) {
		return true;
	} else {
		return false;
	}
}


int main() {

	int n;
	cin >> n;

	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n, comp);

	for (int i = 0; i < n; i++) {
		cout << a[i];
	}






}