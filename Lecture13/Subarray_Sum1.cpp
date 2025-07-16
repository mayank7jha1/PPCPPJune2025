#include<iostream>
using namespace std;


int main() {

	int n, x;
	cin >> n >> x;
	int a[1001];
	int pre[1001] {0};
	for (int i = 0; i < n; i++) {
		cin >> a[i];

		if (i > 0) {
			pre[i] = pre[i - 1] + a[i];
		} else {
			pre[i] = a[i];
		}
	}

	for (int i = 0; i < n; i++) {
		cout << pre[i] << " ";
	}



	//Check part 1: Kya prefix array me kahi par bhi x as a element aaraha hain.
	for (int i = 0; i < n; i++) {
		if (pre[i] == x) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	//Check Part2:










}