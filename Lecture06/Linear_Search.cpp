#include<iostream>
using namespace std;


int main() {

	int n;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int target;
	cin >> target;

	//THis variable will store the index where the element is found.
	int ans = n;

	int flag = 0;

//THis logic print the last found index of the target
	for (int i = 0; i < n; i++) {
		if (a[i] == target) {
			ans = i;
			flag = 1;
		}
	}

	// for (int i = 0; i < n; i++) {
	// 	if (a[i] == target and flag == 0) {
	// 		ans = i;
	// 		flag = 1;
	// 	}
	// }

	cout << ans << endl;


	// n=6
	// a[]= 3 4 1 9 7 19
	// target=7

	// ans=4


	// if (ans == n) {
	// 	cout << "No" << endl;
	// } else {
	// 	cout << "Yes" << endl;
	// }

	// if (flag == 0) {

	// } else {

	// }









}